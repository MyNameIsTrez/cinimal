#include "animals/dog.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

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

void doubling(int32_t & n)
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
			std::cout << "foo" << std::endl;
		}
		else
		{
			std::cout << "bar" << std::endl;
		}

		i += 1;
	}

	doubling(i);
	assert(i == 6);

	Dog::bark();
	assert(Dog::get_paw_count() == 4);

	assert(Country::mexico == 1);

	std::vector<struct Person> *people_ptr = new std::vector<struct Person>;
	std::vector<struct Person> *&people = people_ptr;

	struct Person frank = {};
	frank.age = 24 * 1.5;
	assert(frank.age == 36);
	frank.names.last_name = "frank";
	people->push_back(frank);

	struct Person john = {};
	assert(john.names.last_name == "");
	john.country = Country::mexico;
	assert(john.country != Country::ukraine);
	people->push_back(john);

	assert(people->size() == 2);
	struct Person last;
	last = people->back();
	people->pop_back();
	assert(last.country == Country::mexico);
	assert(people->size() == 1);

	delete people;
	people = nullptr;
	assert(people == nullptr);

	std::cout << "All tests passed!" << std::endl;

	return 0;
}
