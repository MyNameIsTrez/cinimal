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

namespace Country {
enum Country
{
	ukraine,
	mexico,
};
}

struct Person
{
	double age;
	struct Names names;
	Country::Country country;
};

void twice(int32_t & n)
{
    n *= 2;
}

int32_t main()
{
	int32_t i;
	i = 0;
	while (i < 3)
	{
		if (i == 0)
		{
			std::cout << "deez" << std::endl;
		}
		else if (i == 1)
		{
			assert(Dog::get_paw_count(i) == 4);
		}
		else
		{
			assert(Country::mexico == 1);
		}

		i += 1;
	}

	twice(i);
	assert(i == 6);

	Dog::bark();

	struct Person *people_ptr;
	people_ptr = new struct Person[2];
	struct Person *&people = people_ptr;

	struct Person &frank = people[0];

	frank.age = 24 * 1.5;
	assert(people[0].age == 36);
	frank.names.last_name = "frank";

	assert(people[1].names.last_name == "");
	people[1].country = Country::ukraine;
	assert(people[1].country != Country::mexico);

    // This grows the array and frees the old one
    delete[] people;
	people_ptr = new struct Person[3];

	people_ptr[0].age = 0;
	people_ptr[1].age = 1;
	people_ptr[2].age = 2;
	assert(people_ptr[2].age == 2);

	delete[] people;
	people = nullptr;
	assert(people == nullptr);

	std::cout << "All tests passed!" << std::endl;

	return 0;
}
