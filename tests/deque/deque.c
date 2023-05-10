#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	double age;
} Student;

typedef struct Fruit {
	char *name;
} Fruit;

typedef struct Deque {
    uint8_t * elements;
    int32_t type_size;
	int32_t start_index;
	int32_t size;
	int32_t capacity;
} Deque;

Deque deque_new(int32_t type_size) {
	Deque deque = {};
	deque.elements = calloc(1, type_size);
	deque.type_size = type_size;
	deque.capacity = 1;

	return deque;
}

static void try_grow(Deque * const deque) {
	if (deque->size == deque->capacity) {
		uint8_t * const new_elements = calloc(deque->capacity * 2, deque->type_size);

		// An example deque is [B,C, ,A], where the start_index is 3
		int32_t trailing;
		trailing = deque->capacity - deque->start_index;

		// Copies everything to the right of the unused elements
		memcpy(
		    new_elements,
		    deque->elements + deque->start_index * deque->type_size,
		    trailing * deque->type_size
		);

		// Copies everything to the left of the unused elements
		memcpy(
		    new_elements + trailing * deque->type_size,
		    deque->elements,
		    (deque->size - trailing) * deque->type_size
		);

		free(deque->elements);
		deque->elements = new_elements;

		deque->start_index = 0;
		deque->capacity *= 2;
	}
}

static int32_t modulo(int32_t const a, int32_t const b) {
    // TODO: Can be done more efficiently
    return ((a % b) + b) % b;
}

static void assign_element(Deque const * const deque, uint8_t const * const element, int32_t const index) {
	memcpy(deque->elements + index * deque->type_size, element, deque->type_size);
}

void deque_push_front(Deque * const deque, uint8_t const * const element) {
	try_grow(deque);

	deque->start_index = modulo(deque->start_index - 1, deque->capacity);
	assign_element(deque, element, deque->start_index);

	deque->size++;
}

void deque_push_back(Deque * const deque, uint8_t const * const element) {
	try_grow(deque);

    int32_t index;
    index = (deque->start_index + deque->size) % deque->capacity;
	assign_element(deque, element, index);

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

int32_t main(void) {
	Deque deque;
	deque = deque_new(sizeof(Student));

	Student alice = {};
	alice.age = 10;
	deque_push_back(&deque, (uint8_t *)&alice);

	Student bob = {};
	bob.age = 11;
	deque_push_back(&deque, (uint8_t *)&bob);

	Student charles = {};
	charles.age = 9;
	deque_push_front(&deque, (uint8_t *)&charles);

    Student const * student;

    student = deque_at(&deque, 3);
	assert(student->age == 9);
    student = deque_at(&deque, 0);
	assert(student->age == 10);
    student = deque_at(&deque, 1);
	assert(student->age == 11);

    student = deque_front(&deque);
	assert(student->age == 9);
	deque_pop_front(&deque);

    student = deque_back(&deque);
	assert(student->age == 11);
	deque_pop_back(&deque);

	deque_delete(&deque);

	deque = deque_new(sizeof(Fruit));
	Fruit apple;
	apple.name = "apple";
	deque_push_back(&deque, (uint8_t *)&apple);
	assert(strcmp(((Fruit *)deque_back(&deque))->name, "apple") == 0);
	deque_delete(&deque);

	return 0;
}
