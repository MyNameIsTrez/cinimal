#include "deque.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

Deque deque_new(int32_t type_size) {
	Deque deque = {};
	deque.elements = calloc(1, type_size);
	deque.type_size = type_size;
	deque.capacity = 1;

	return deque;
}

void deque_reserve(Deque * const deque, int32_t const new_capacity) {
	uint8_t * const new_elements = calloc(new_capacity, deque->type_size);

	int32_t on_right;
	if (deque->start_index > 0) {
	    // An example deque is [B,C, ,A], where the start_index is 3
	    on_right = deque->capacity - deque->start_index;
	} else {
	    // An example deque is [A, , , ], where the start_index is 0
	    on_right = 0;
	}

	// Copies everything to the right of the unused elements
	memcpy(
	    new_elements,
	    deque->elements + deque->start_index * deque->type_size,
	    on_right * deque->type_size
	);

	// Copies everything to the left of the unused elements
	memcpy(
	    new_elements + on_right * deque->type_size,
	    deque->elements,
	    (deque->size - on_right) * deque->type_size
	);

	free(deque->elements);
	deque->elements = new_elements;

	deque->start_index = 0;
	deque->capacity = new_capacity;
}

static int32_t modulo(int32_t const a, int32_t const b) {
    // TODO: Can be done more efficiently
    return ((a % b) + b) % b;
}

void deque_set(Deque const * const deque, void const * const element, int32_t const index) {
	memcpy(deque->elements + index * deque->type_size, element, deque->type_size);
}

void deque_push_front(Deque * const deque, void const * const element) {
	if (deque->size == deque->capacity) {
	    deque_reserve(deque, deque->capacity * 2);
	}

	deque->start_index = modulo(deque->start_index - 1, deque->capacity);
	deque_set(deque, element, deque->start_index);

	deque->size++;
}

void deque_push_back(Deque * const deque, void const * const element) {
	if (deque->size == deque->capacity) {
	    deque_reserve(deque, deque->capacity * 2);
	}

    int32_t index;
    index = (deque->start_index + deque->size) % deque->capacity;
	deque_set(deque, element, index);

	deque->size++;
}

void * deque_front(Deque * const deque) {
	return deque->elements + deque->start_index * deque->type_size;
}

void * deque_back(Deque * const deque) {
    // TODO: Does this handle size=0 properly?
    int32_t index;
    index = (deque->start_index + deque->size - 1) % deque->capacity;
	return deque->elements + index * deque->type_size;
}

void deque_pop_front(Deque * const deque) {
	deque->start_index = (deque->start_index + 1) % deque->capacity;
	deque->size--;
}

void deque_pop_back(Deque * const deque) {
	deque->size--;
}

void * deque_at(Deque const * const deque, int32_t index) {
    return deque->elements + index * deque->type_size;
}

void deque_delete(Deque * const deque) {
	free(deque->elements);
	deque->start_index = 0;
	deque->size = 0;
}
