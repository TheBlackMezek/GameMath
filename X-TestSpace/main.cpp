
#include <iostream>

#include "MathUtils.h"
#include "Vec2.h"


int main()
{
	vec2 test;
	test.x = 1;
	test.y = 1;
	vec2 tset;
	tset.x = 2;
	tset.y = 3;

	vec2 vadd = test + tset;

	std::cout << vadd.x << std::endl;
	std::cout << vadd.y << std::endl;

	std::cout << min(5, 2) << std::endl;

	std::cin.get();

	

	std::cout << test.x << std::endl;
	std::cout << test.y << std::endl;
	std::cout << "Adding\n";

	test += tset;

	std::cout << test.x << std::endl;
	std::cout << test.y << std::endl;
	std::cin.get();



	if (test == tset)
	{
		std::cout << "Equal\n";
	}
	else
	{
		std::cout << "Not equal\n";
	}

	std::cin.get();



	return 0;
}