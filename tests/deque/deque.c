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

Deque new(int32_t type_size) {
	Deque deque = {};
	deque.elements = calloc(1, type_size);
	deque.type_size = type_size;
	deque.capacity = 1;

	return deque;
}

static void try_grow(Deque * const deque) {
	if (deque->size == deque->capacity) {
		uint8_t * const new_elements = calloc(deque->capacity * 2, deque->type_size);

		// An example ring buffer is [B,C, ,A], where the start_index is 3
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
    return ((a % b) + b) % b;
}

static void assign_element(Deque const * const deque, uint8_t const * const element, int32_t const index) {
	memcpy(deque->elements + index * deque->type_size, element, deque->type_size);
}

void push_front(Deque * const deque, uint8_t const * const element) {
	try_grow(deque);

	deque->start_index = modulo(deque->start_index - 1, deque->capacity);
	assign_element(deque, element, deque->start_index);

	deque->size++;
}

void push_back(Deque * const deque, uint8_t const * const element) {
	try_grow(deque);

    int32_t index;
    index = (deque->start_index + deque->size) % deque->capacity;
	assign_element(deque, element, index);

	deque->size++;
}

uint8_t * front(Deque * const deque) {
	return deque->elements + deque->start_index * deque->type_size;
}

uint8_t * back(Deque * const deque) {
    // TODO: Does this handle size=0 properly?
    int32_t index;
    index = (deque->start_index + deque->size - 1) % deque->capacity;
	return deque->elements + index * deque->type_size;
}

void pop_front(Deque * const deque) {
	deque->start_index = (deque->start_index + 1) % deque->capacity;
	deque->size--;
}

void pop_back(Deque * const deque) {
	deque->size--;
}

void delete(Deque * const deque) {
	free(deque->elements);
	deque->start_index = 0;
	deque->size = 0;
}

int32_t main(void) {
	Deque deque;
	deque = new(sizeof(Student));

	Student alice = {};
	alice.age = 10;
	push_back(&deque, (uint8_t *)&alice);

	Student bob = {};
	bob.age = 11;
	push_back(&deque, (uint8_t *)&bob);

	Student charles = {};
	charles.age = 9;
	push_front(&deque, (uint8_t *)&charles);

	assert(((Student *)(deque.elements + 3 * deque.type_size))->age == 9);
	assert(((Student *)(deque.elements + 0 * deque.type_size))->age == 10);
	assert(((Student *)(deque.elements + 1 * deque.type_size))->age == 11);

    Student * student;

    student = (Student *)front(&deque);
	assert(student->age == 9);
	pop_front(&deque);

    student = (Student *)back(&deque);
	assert(student->age == 11);
	pop_back(&deque);

	delete(&deque);

	deque = new(sizeof(Fruit));
	Fruit apple;
	apple.name = "apple";
	push_back(&deque, (uint8_t *)&apple);
	assert(
	    strcmp(
	        ((Fruit *)back(&deque))->name,
	        "apple"
	    ) == 0
	);
	delete(&deque);

	return 0;
}
