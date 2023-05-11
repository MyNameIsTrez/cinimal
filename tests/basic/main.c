#include <assert.h>
#include <stdint.h>
#include <stdio.h>

static void add(int32_t * const n) {
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

	return 0;
}
