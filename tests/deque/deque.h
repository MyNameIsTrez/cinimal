#ifndef DEQUE_H
# define DEQUE_H

#include <stdint.h>

typedef struct {
	uint8_t * elements;
	int32_t type_size;
	int32_t start_index;
	int32_t size;
	int32_t capacity;
} Deque;

Deque deque_new(int32_t const type_size);
void deque_reserve(Deque * const deque, int32_t const new_capacity);
void deque_set(Deque * const deque, void const * const element, int32_t const index);
void deque_push_front(Deque * const deque, void const * const element);
void deque_push_back(Deque * const deque, void const * const element);
void * deque_front(Deque * const deque);
void * deque_back(Deque * const deque);
void deque_pop_front(Deque * const deque);
void deque_pop_back(Deque * const deque);
void * deque_at(Deque const * const deque, int32_t const index);
void deque_delete(Deque * const deque);

#endif
