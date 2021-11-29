#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
  size_t head, tail;
  size_t capacity;
  int16_t *buffer;
} circular_buffer_t;

typedef int16_t buffer_value_t;

circular_buffer_t* new_circular_buffer(size_t);
size_t size(circular_buffer_t*);
int16_t read(circular_buffer_t*, int16_t*);
int16_t write(circular_buffer_t*, int16_t);
int16_t overwrite(circular_buffer_t*, int16_t);
void delete_buffer(circular_buffer_t*);
void clear_buffer(circular_buffer_t*);

#endif
