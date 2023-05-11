#include "deque.h"
#include "vector.h"

#include <stdint.h>

Vector vector_new(int32_t const type_size) {
	return (Vector){ deque_new(type_size) };
}

void vector_reserve(Vector * const vector, int32_t const new_capacity) {
	deque_reserve(&vector->deque, new_capacity);
}

void vector_set(Vector * const vector, void const * const element, int32_t const index) {
	deque_set(&vector->deque, element, index);
}

void vector_push(Vector * const vector, void const * const element) {
	deque_push_back(&vector->deque, element);
}

void * vector_back(Vector * const vector) {
	return deque_back(&vector->deque);
}

void vector_pop_back(Vector * const vector) {
	deque_pop_back(&vector->deque);
}

void * vector_at(Vector const * const vector, int32_t const index) {
	return deque_at(&vector->deque, index);
}

void vector_delete(Vector * const vector) {
	deque_delete(&vector->deque);
}
