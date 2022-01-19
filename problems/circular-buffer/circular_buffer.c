#include "circular_buffer.h"
#include <errno.h>

circular_buffer_t *new_circular_buffer(size_t capacity) {
  circular_buffer_t *c = malloc(sizeof(circular_buffer_t));
  *c = (circular_buffer_t){.head = 0,
                           .tail = 0,
                           .capacity = capacity,
                           .buffer = malloc(sizeof(int16_t) * capacity)};
  return c;
}

size_t size(circular_buffer_t *c) { return c->tail - c->head; }

int16_t read(circular_buffer_t *c, int16_t *out) {
  if (size(c) == 0) {
    errno = ENODATA;
    return EXIT_FAILURE;
  }

  *out = c->buffer[c->head++ % c->capacity];

  return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t *c, int16_t val) {
  if (size(c) == c->capacity) {
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }

  c->buffer[c->tail++ % c->capacity] = val;

  return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *c, int16_t val) {
  write(c, val);

  if (errno == ENOBUFS) {
    c->buffer[c->tail % c->capacity] = val;
    c->head += 1;
    c->tail += 1;
  }

  return EXIT_SUCCESS;
}

void delete_buffer(circular_buffer_t *c) {
  free(c->buffer);
  free(c);
}

void clear_buffer(circular_buffer_t *c) {
  c->head = 0;
  c->tail = 0;
}
