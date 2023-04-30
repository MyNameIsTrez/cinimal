#include "dog.h"

#include "typedefs.h"

void bark(void)
{
	printf("%s\n", "bark");
	printf("%d\n", 42);
}

i32 get_paw_count(i32 dog_count)
{
	return dog_count * 4;
}
