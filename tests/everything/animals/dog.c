#include "dog.h"

#include <stdint.h>

namespace Dog
{

void bark()
{
	std::cout << "bark" << std::endl;
}

int32_t get_paw_count()
{
	return 4;
}

}
