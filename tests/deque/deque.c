#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	double age;
} Student;

typedef struct Deque {
    Student * data;
	int32_t start_index;
	int32_t size;
	int32_t capacity;
} Deque;

Deque new(void) {
	Deque deque = {};
	deque.data = calloc(1, sizeof(Student));
	deque.capacity = 1;

	return deque;
}

static void try_grow(Deque * const deque) {
	if (deque->size == deque->capacity) {
		Student * const new_data = calloc(deque->capacity * 2, sizeof(Student));

		// An example ring buffer is [B,C, ,A], where the start_index is 3
		int32_t trailing;
		trailing = deque->capacity - deque->start_index;

		// This copies the part that wrapped below index 0 to the other side
		memcpy(new_data, deque->data + deque->start_index, trailing * sizeof(Student));
		// This copies from index 0 on
		memcpy(new_data + trailing, deque->data, (deque->size - trailing) * sizeof(Student));

		free(deque->data);
		deque->data = new_data;

		deque->start_index = 0;
		deque->capacity *= 2;
	}
}

static int32_t modulo(int32_t a, int32_t b) {
    return ((a % b) + b) % b;
}

void push_front(Deque * const deque, Student student) {
	try_grow(deque);

	deque->start_index = modulo(deque->start_index - 1, deque->capacity);
	deque->data[deque->start_index] = student;

	deque->size++;
}

void push_back(Deque * const deque, Student student) {
	try_grow(deque);

    int32_t index;
    index = (deque->start_index + deque->size) % deque->capacity;
	deque->data[index] = student;

	deque->size++;
}

void pop_front(Deque * const deque) {
	deque->start_index = (deque->start_index + 1) % deque->capacity;
	deque->size--;
}

Student * front(Deque * const deque) {
	return deque->data + deque->start_index;
}

Student * back(Deque * const deque) {
    // TODO: Does this handle size=0 properly?
    int32_t index;
    index = (deque->start_index + deque->size - 1) % deque->capacity;
	return deque->data + index;
}

void pop_back(Deque * const deque) {
	deque->size--;
}

void delete(Deque * const deque) {
	free(deque->data);
}

int32_t main(void) {
	Deque deque;
	deque = new();

	Student alice = {};
	alice.age = 10;
	push_back(&deque, alice);

	Student bob = {};
	bob.age = 11;
	push_back(&deque, bob);

	Student charles = {};
	charles.age = 9;
	push_front(&deque, charles);

	assert(deque.data[3].age == 9);
	assert(deque.data[0].age == 10);
	assert(deque.data[1].age == 11);

	assert(front(&deque)->age == 9);
	pop_front(&deque);
	assert(back(&deque)->age == 11);
	pop_back(&deque);

	delete(&deque);

	return 0;
}
