#include "animals/dog.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct names {
	char *first_name;
	char *last_name;
};

enum country {
	country_ukraine,
	country_mexico,
};

struct person {
	double age;
	struct names names;
	enum country country;
};

void *allocate_one_person(void) {
    return calloc(1, sizeof(struct person));
}

void add(int32_t * const n) {
    (*n)++;
}

int32_t main(void) {
	//single line comment
	/*multi
	line comment */ int32_t i = 0;

	while (i < 3) {
		if (i == 0) {
			printf("foo\n");
		} else if (i == 1) {
			printf("bar\n");
		} else printf("baz\n");
		i++;
	}

	assert(i == 3);
	add(&i);
	assert(i == 4);

	bark();
	assert(get_paw_count() == 4);

	assert(country_mexico == 1);

	struct person * people = calloc(2, sizeof(struct person));

    struct person * const frank = &people[0];
	frank->age = 24 * 1.5;
	assert(people[0].age == 36);
	frank->names.last_name = "frank";
	assert(strcmp(people[0].names.last_name, "frank") == 0);

	assert(people[1].names.last_name == NULL);

	people[1].country = country_mexico;
	assert(people[1].country != country_ukraine);

	free(people);
	people = allocate_one_person();
	people[0].age = 42;
	assert(people[0].age == 42);

	free(people);
	people = NULL;

	struct person friends[2][3] = {0};
	friends[0][2].age = 13;
	assert(friends[0][2].age == 13);

	printf("All tests passed!\n");

	return 0;
}
