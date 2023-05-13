#include "animals/dog.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Type {
	INTEGER,
	STRING,
};

typedef struct {
	enum Type type;
	union {
		int32_t integer;
		char * string;
	};
} Value;

static void * allocate_one_value(void) {
	return calloc(1, sizeof(Value));
}

static void add(int32_t * const n) {
	(*n)++;
}

int32_t main(void) {
	//single line comment
	/*multiline
	comment */ int32_t i = 0;

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

	for (int32_t j = 0; j < 2; j++) {
		// Prints 0, 1
		printf("%d\n", j);
	}

	bark();
	assert(get_paw_count() == 4);

	assert(STRING == 1);

	Value * values = calloc(2, sizeof(Value));

	Value * const v0 = &values[0];
	v0->type = STRING;
	assert(values[0].type == STRING);
	assert(v0->string == NULL);
	v0->string = "frank";
	assert(strcmp(values[0].string, "frank") == 0);

	values[1].type = STRING;
	assert(values[1].type != INTEGER);

	free(values);
	values = allocate_one_value();
	values[0].integer = 42;
	assert(values[0].integer == 42);
	free(values);

	Value matrix[2][3] = {0};
	matrix[0][2].integer = 13;
	assert(matrix[0][2].integer == 13);

	printf("All tests passed!\n");

	return 0;
}
