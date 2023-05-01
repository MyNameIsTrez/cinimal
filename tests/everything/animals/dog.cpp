#include "dog.h"

#include <stdint.h>

namespace Dog
{

void bark(void)
{
	std::cout << "bark" << std::endl;
}

int32_t get_paw_count(int32_t dog_count)
{
	return dog_count * 4;
}

}
