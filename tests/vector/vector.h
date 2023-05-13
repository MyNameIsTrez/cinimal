#ifndef VECTOR_H
# define VECTOR_H

#include "deque.h"

#include <stdint.h>

typedef struct Vector {
	Deque deque;
} Vector;

Vector vector_new(int32_t const type_size);
void vector_reserve(Vector * const vector, int32_t const new_capacity);
void vector_set(Vector * const vector, void const * const element, int32_t const index);
void vector_push(Vector * const vector, void const * const element);
void * vector_back(Vector * const vector);
void vector_pop_back(Vector * const vector);
void * vector_at(Vector const * const vector, int32_t index);
void vector_delete(Vector * const vector);

#endif
