#include "deque.h"

#include <assert.h>
#include <stdint.h>
#include <string.h>

typedef struct {
	double age;
} Student;

typedef struct {
	char * name;
} Fruit;

int32_t main(void) {
	Deque deque;
	deque = deque_new(sizeof(Student));

	Student alice = {10};
	deque_push_back(&deque, &alice);

	Student bob = {11};
	deque_push_back(&deque, &bob);

	Student charles = {9};
	deque_push_front(&deque, &charles);

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

	deque_reserve(&deque, 100);
	deque_push_back(&deque, &charles);
	deque_reserve(&deque, 200);

	Fruit apple;
	apple.name = "apple";
	deque_push_back(&deque, &apple);
	deque_set(&deque, &(Fruit){"banana"}, 1);
	assert(strcmp(((Fruit *)deque_back(&deque))->name, "banana") == 0);

	deque_delete(&deque);

	return 0;
}
