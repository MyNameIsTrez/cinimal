#include "dog.h"

#include <stdint.h>

void bark(void)
{
	printf("%s\n", "bark");
	printf("%d\n", 42);
}

int32_t get_paw_count(int32_t dog_count)
{
	return dog_count * 4;
}
