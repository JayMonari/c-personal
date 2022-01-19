#ifndef UUID_EDB360AE_8079_4527_9ED2_5CC117147ABE
#define UUID_EDB360AE_8079_4527_9ED2_5CC117147ABE

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h> // required by the tests

typedef int list_element_t;
typedef struct {
  size_t length;
  list_element_t elements[];
} list_t;
/**
 * Construct a new list.
 * @param length The number of elements in the new list.
 * @param value The elements of the new list.
 * @return The new list, or NULL if the required memory could not get allocated.
 *
 * The returned list must be released with delete_list().
 */
list_t *new_list(size_t length, const list_element_t elements[]);
/**
 * Create a new list from the elements of 'list1' and 'list2'.
 * @param list1 The first source list.
 * @param list2 The second source list.
 * @return The new list, or NULL if the required memory could not get allocated.
 *
 * The returned list must be released with delete_list().
 */
list_t *append_list(const list_t *list1, const list_t *list2);
/**
 * Create a new list with all elements from 'list1' that satisfy the
 * 'predicate'.
 * @param list1 The source list.
 * @param predicate A function that returns 'true' for all elements that should
 * be in the new list.
 * @return The new list, or NULL if the required memory could not get allocated.
 *
 * The returned list must be released with delete_list().
 */
list_t *filter_list(const list_t *list1, bool (*predicate)(list_element_t value));
/**
 * Return the length of the list.
 * @param list1 The list.
 * @return The length.
 */
size_t length_list(const list_t *list1);
/**
 * Create a new list with elements that were mapped from 'list1' by the function
 * 'map'.
 * @param list1 The source list.
 * @param map The mapping function.
 * @return The new list, or NULL if the required memory could not get allocated.
 *
 * The returned list must be released with delete_list().
 */
list_t *map_list(const list_t *list1, list_element_t (*map)(list_element_t value));
/**
 * "Reduce" the 'list1' by applying 'foldl' to all elements starting from the
 * left.
 * @param list1 The source list.
 * @param initial The initial value that gets passed as 2nd argument to 'foldl'.
 * @param foldl The folding function.
 * @return The final value.
 */
list_element_t foldl_list(const list_t *list1, list_element_t initial,
                        list_element_t (*foldl)(list_element_t value,
                                              list_element_t initial));
/**
 * "Reduce" the 'list1' by applying 'foldr' to all elements starting from the
 * right.
 * @param list1 The source list.
 * @param initial The initial value that gets passed as 2nd argument to 'foldr'.
 * @param foldr The folding function.
 * @return The final value.
 */
list_element_t foldr_list(const list_t *list1, list_element_t initial,
                        list_element_t (*foldr)(list_element_t value,
                                              list_element_t initial));
/**
 * Create a new list from the element of 'list1' in reversed order.
 * @param list1 The source list.
 * @return The new list, or NULL if the required memory could not get allocated.
 *
 * The returned list must be released with delete_list().
 */
list_t *reverse_list(const list_t *list1);
/**
 * Destroy the list and release the allocated memory.
 * @param list1 The list to be destroyed, or NULL.
 *
 * 'list1' will be a dangling pointer after the function returned.
 */
void delete_list(list_t *list1);
#endif // UUID_EDB360AE_8079_4527_9ED2_5CC117147ABE
