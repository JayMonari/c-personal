#include "list_ops.h"
#include <assert.h>
#include <stdint.h> // for SIZE_MAX
#include <stdlib.h> // for malloc / free
#include <string.h> // for memcpy

static list_t *new_empty_list(size_t length) {
  if ((SIZE_MAX - sizeof(list_t)) / sizeof(list_element_t) < length)
    return NULL;
  list_t *list = malloc(sizeof(*list) + length * sizeof(*list->elements));
  if (list)
    list->length = length;
  return list;
}

list_t *new_list(size_t length, const list_element_t elements[]) {
  assert(elements || length == 0);
  list_t *list = new_empty_list(length);
  if (list)
    memcpy(list->elements, elements, length * sizeof(*elements));
  return list;
}

list_t *append_list(const list_t *list1, const list_t *list2) {
  assert(list1);
  assert(list2);
  if (SIZE_MAX - list1->length < list2->length)
    return NULL;
  list_t *list = new_empty_list(list1->length + list2->length);
  if (!list)
    return NULL;
  memcpy(list->elements, list1->elements,
         list1->length * sizeof(*list->elements));
  memcpy(list->elements + list1->length, list2->elements,
         list2->length * sizeof(*list->elements));
  return list;
}

list_t *filter_list(const list_t *list1,
                    bool (*predicate)(list_element_t value)) {
  assert(list1);
  list_t *list = new_empty_list(list1->length);
  if (!list)
    return NULL;
  list->length = 0;
  for (size_t i = 0; i < list1->length; ++i)
    if (predicate(list1->elements[i]))
      list->elements[list->length++] = list1->elements[i];
  return list;
}

size_t length_list(const list_t *list) {
  assert(list);
  return list->length;
}

list_t *map_list(const list_t *list1,
                 list_element_t (*map)(list_element_t value)) {
  assert(list1);
  list_t *list = new_empty_list(list1->length);
  if (!list)
    return NULL;
  for (size_t i = 0; i < list->length; ++i)
    list->elements[i] = map(list1->elements[i]);
  return list;
}

list_element_t foldl_list(const list_t *list1, list_element_t initial,
                          list_element_t (*foldl)(list_element_t value,
                                                  list_element_t initial)) {
  assert(list1);
  for (size_t i = 0; i < list1->length; ++i)
    initial = foldl(list1->elements[i], initial);
  return initial;
}

list_element_t foldr_list(const list_t *list1, list_element_t initial,
                          list_element_t (*foldr)(list_element_t value,
                                                  list_element_t initial)) {
  assert(list1);
  for (size_t i = list1->length - 1; i < list1->length; --i)
    initial = foldr(list1->elements[i], initial);
  return initial;
}

list_t *reverse_list(const list_t *list1) {
  assert(list1);
  list_t *list = new_empty_list(list1->length);
  if (!list)
    return NULL;
  for (size_t i1 = 0, i2 = list1->length - 1; i1 < list->length; ++i1, --i2)
    list->elements[i1] = list1->elements[i2];
  return list;
}

void delete_list(list_t *list) { free(list); }
