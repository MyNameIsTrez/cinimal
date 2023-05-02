#include <cassert>
#include <iostream>

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
			std::cout << "foo" << std::endl;
		}
		else
		{
			std::cout << "bar" << std::endl;
		}

		i += 1;
	}

	twice(i);
	assert(i == 6);

	return 0;
}
