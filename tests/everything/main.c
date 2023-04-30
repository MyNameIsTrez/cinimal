#include "animals/dog.h"

#include "typedefs.h"

struct names
{
	char *first_name;
	char *last_name;
};

enum country
{
	ukraine,
	mexico,
};

struct person
{
	i8 age;
	struct names names;
	country country;
}

i32 main()
{
	i32 i;
	i = 0;
	while (i < 3)
	{
		if (a == 0)
		{
			printf("%s\n", "a");
		}
		else if (a == 1)
		{
			printf("%s\n", "b");
		}
		else
		{
			printf("%s\n", "c");
		}

		i += 1
	}

	dog::bark();

	i16 paw_count;
	paw_count = dog::get_paw_count(2);

	i16 * paw_count_ptr;
	paw_count_ptr = &paw_count;
	assert(*paw_count_ptr, 8);

	struct person * people;
	people = calloc(2 * sizeof(struct person));

	struct person * frank;
	frank = &people[0];
	frank->age = 24;
	assert(people[0]->age, 24);
	frank->names.last_name = "frank";

	assert(people[1].names.last_name, "");
	people[1].country = country::ukraine;
	nassert(people[1].country, country::mexico);

	free(people);
	people = NULL;

	return 0;
}
