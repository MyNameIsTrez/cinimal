#include "vector.h"

#include <assert.h>
#include <stdint.h>
#include <string.h>

typedef struct Student {
	double age;
} Student;

typedef struct Fruit {
	char * name;
} Fruit;

int32_t main(void) {
	Vector vector;
	vector = vector_new(sizeof(Student));

	Student alice = {10};
	vector_push(&vector, &alice);

	Student bob = {11};
	vector_push(&vector, &bob);

	Student const * student;

	student = vector_at(&vector, 0);
	assert(student->age == 10);
	student = vector_at(&vector, 1);
	assert(student->age == 11);

	student = vector_back(&vector);
	assert(student->age == 11);
	vector_pop_back(&vector);

	student = vector_back(&vector);
	assert(student->age == 10);
	vector_pop_back(&vector);

	vector_delete(&vector);

	vector = vector_new(sizeof(Fruit));

	vector_reserve(&vector, 100);
	vector_push(&vector, &bob);
	vector_reserve(&vector, 200);

	Fruit apple;
	apple.name = "apple";
	vector_push(&vector, &apple);
	vector_set(&vector, &(Fruit){"banana"}, 1);
	assert(strcmp(((Fruit *)vector_back(&vector))->name, "banana") == 0);

	vector_delete(&vector);

	return 0;
}
