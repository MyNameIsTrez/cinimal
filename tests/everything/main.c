#include "animals/dog.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Names {
	char *first_name;
	char *last_name;
};

enum Country {
	Country_ukraine,
	Country_mexico,
};

struct Person {
	double age;
	struct Names names;
	enum Country country;
};

void *allocate_one_person(void) {
    return calloc(1, sizeof(struct Person));
}

void add(int32_t * n) {
    (*n)++;
}

int32_t main(void) {
	int32_t i = 0;

	while (i < 3) {
		if (i == 0) {
			printf("foo\n");
		} else printf("bar\n");
		i++;
	}

	assert(i == 3);
	add(&i);
	assert(i == 4);

	bark();
	assert(get_paw_count() == 4);

	assert(Country_mexico == 1);

	struct Person *people;
	people = calloc(2, sizeof(struct Person));

    struct Person *frank;
    frank = &people[0];
	frank->age = 24 * 1.5;
	assert(people[0].age == 36);
	frank->names.last_name = "frank";
	assert(strcmp(people[0].names.last_name, "frank") == 0);

	assert(people[1].names.last_name == NULL);

	people[1].country = Country_mexico;
	assert(people[1].country != Country_ukraine);

	free(people);
	people = NULL;
	assert(people == NULL);

	people = allocate_one_person();
	people[0].age = 42;
	assert(people[0].age == 42);

	free(people);
	people = NULL;

	Person[2] friends = {0};
	friends[1].age = 13;
	assert(friends[1].age == 13);

	printf("All tests passed!\n");

	return 0;
}
