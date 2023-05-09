#include "animals/dog.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Names {
	char * first_name;
	char * last_name;
};

typedef enum Country {
	ukraine,
	mexico,
} Country;

typedef struct Person {
	double age;
	struct Names names;
	Country country;
} Person;

typedef enum {
    INTEGER,
    REAL,
} Type;

typedef struct {
    Type type;
    union {
        int integer;
        float real;
    };
} Value;

Value value_new_integer(int integer)
{
  Value v;
  v.type = INTEGER;
  v.integer = integer;
  return v;
}

static void * allocate_one_person(void) {
    return calloc(1, sizeof(Person));
}

static void add(int32_t * const n) {
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

	assert(mexico == 1);

	Person * people = calloc(2, sizeof(Person));

    Person * const frank = &people[0];
	frank->age = 24 * 1.5;
	assert(people[0].age == 36);
	frank->names.last_name = "frank";
	assert(strcmp(people[0].names.last_name, "frank") == 0);

	assert(people[1].names.last_name == NULL);

	people[1].country = mexico;
	assert(people[1].country != ukraine);

	free(people);
	people = allocate_one_person();
	people[0].age = 42;
	assert(people[0].age == 42);

	free(people);
	people = NULL;

	Person friends[2][3] = {0};
	friends[0][2].age = 13;
	assert(friends[0][2].age == 13);

    Value v;
    v.integer = 42;
    assert(v.integer == 42);
    v.real = 1337;
    assert(v.real == 1337);

	printf("All tests passed!\n");

	return 0;
}
