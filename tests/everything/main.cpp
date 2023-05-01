#include "animals/dog.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>

struct Names
{
	std::string first_name;
	std::string last_name;
};

enum struct Country
{
	ukraine,
	mexico,
};

struct Person
{
	int8_t age;
	struct Names names;
	Country country;
};

int32_t main()
{
	// Example comment

	int32_t i;
	i = 0;
	while (i < 3)
	{
		if (i == 0)
		{
			std::cout << "a" << std::endl;
		}
		else if (i == 1)
		{
			std::cout << "b" << std::endl;
		}
		else
		{
			std::cout << "c" << std::endl;
		}

		i += 1;
	}

	Dog::bark();

	int16_t paw_count;
	paw_count = Dog::get_paw_count(2);

	int16_t &paw_count_ref = paw_count;
	assert(paw_count_ref == 8);

	struct Person *people_ptr;
	people_ptr = (struct Person *)calloc(2, sizeof(struct Person));
	struct Person *&people = people_ptr;

	struct Person &frank = people[0];
	frank.age = 24;
	assert(people[0].age == 24);
	frank.names.last_name = "frank";

	assert(people[1].names.last_name == "");
	people[1].country = Country::ukraine;
	assert(people[1].country != Country::mexico);

	free(people);
	people = nullptr;
	assert(people == nullptr);

	std::cout << "All tests passed!" << std::endl;

	return 0;
}
