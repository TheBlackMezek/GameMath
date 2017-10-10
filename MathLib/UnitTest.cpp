
#include "UnitTest.h"


#include <cassert>
#include <iostream>

#include "Vec2.h"



void testVec2()
{

	vec2 v1;
	vec2 v2;
	float scalar;
	vec2 result;
	vec2 expected;


	v1.x = 10;
	v1.y = 20;
	v2.x = 10;
	v2.y = 20;
	assert(v1 == v2);
	v1.x = 8;
	assert(v1 != v2);

	v1.x = 1;
	v1.y = 2;
	v2.x = 9;
	v2.y = 18;
	expected.x = 10;
	expected.y = 20;
	assert(v1 + v2 == expected);

	v1.x = 11;
	v1.y = 21;
	v2.x = 1;
	v2.y = 1;
	assert(v1 - v2 == expected);

	v1.x = 5;
	v1.y = 10;
	scalar = 2;
	assert(v1 * scalar == expected);
	assert(scalar * v1 == expected);

	v1.x = 20;
	v1.y = 40;
	assert(v1 / scalar == expected);

	v1.x = -10;
	v1.y = -20;
	assert(-v1 == expected);

	v1.x = 1;
	v1.y = 2;
	v2.x = 9;
	v2.y = 18;
	assert((v1 += v2) == expected);

	v1.x = 11;
	v1.y = 21;
	v2.x = 1;
	v2.y = 1;
	assert((v1 -= v2) == expected);

	v1.x = 5;
	v1.y = 10;
	scalar = 2;
	assert((v1 *= scalar) == expected);

	v1.x = 20;
	v1.y = 40;
	assert((v1 /= scalar) == expected);

	assert(v1[0] == 10);




	std::cout << "MAGNITUDE TESTS:\n\n\n";
	v1.x = 0;
	v1.y = 1;
	std::cout << "Should be: 1\nIS:";
	std::cout << magnitude(v1) << std::endl << std::endl;
	v1.x = 1;
	v1.y = 1;
	std::cout << "Should be: ~1.41421\nIS:";
	std::cout << magnitude(v1) << std::endl << std::endl;
	v1.x = -2;
	v1.y = 3;
	std::cout << "Should be: ~3.60555\nIS:";
	std::cout << magnitude(v1) << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\nNORMALIZATION TESTS:\n\n\n";
	v1.x = 0;
	v1.y = 1;
	v2 = normal(v1);
	std::cout << "Should be: 0,1\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl;
	v1.x = 1;
	v1.y = 1;
	v2 = normal(v1);
	std::cout << "Should be: 0.707107,0.707107\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl;
	v1.x = -2;
	v1.y = 3;
	v2 = normal(v1);
	std::cout << "Should be: -0.5547,0.83205\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl << std::endl;

	v1.x = 0;
	v1.y = 1;
	normalize(v1);
	std::cout << "Should be: 0,1\nIS:";
	std::cout << v1.x << "," << v1.y << std::endl << std::endl;
	v1.x = 1;
	v1.y = 1;
	normalize(v1);
	std::cout << "Should be: 0.707107,0.707107\nIS:";
	std::cout << v1.x << "," << v1.y << std::endl << std::endl;
	v1.x = -2;
	v1.y = 3;
	normalize(v1);
	std::cout << "Should be: -0.5547,0.83205\nIS:";
	std::cout << v1.x << "," << v1.y << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\DOT PRODUCT TESTS:\n\n\n";
	v1.x = 2;
	v1.y = 3;
	v2.x = 7;
	v2.y = 5;
	scalar = dot(v1, v2);
	std::cout << "Should be: 29\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 1;
	v1.y = 0;
	v2.x = 1;
	v2.y = 1;
	scalar = dot(v1, v2);
	std::cout << "Should be: 1\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 4;
	v1.y = 0;
	v2.x = 1;
	v2.y = -3;
	scalar = dot(v1, v2);
	std::cout << "Should be: 4\nIS:";
	std::cout << scalar << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\DISTANCE TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v2.x = 1;
	v2.y = -3;
	scalar = distance(v1, v2);
	std::cout << "Should be: 4.24264\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 8;
	v1.y = 2;
	v2.x = 1;
	v2.y = 4;
	scalar = distance(v1, v2);
	std::cout << "Should be: 7.28011\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 5;
	v1.y = 12;
	v2.x = 0;
	v2.y = 0;
	scalar = distance(v1, v2);
	std::cout << "Should be: 13\nIS:";
	std::cout << scalar << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\COUNTERCLOCKWISE PERPENDICULAR TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v2 = perpendicular(v1, false);
	std::cout << "Should be: 0,4\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl;
	v1.x = 8;
	v1.y = 2;
	v2 = perpendicular(v1, false);
	std::cout << "Should be: -2,8\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl;
	v1.x = -5;
	v1.y = -12;
	v2 = perpendicular(v1, false);
	std::cout << "Should be: 12,-5\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\CLOCKWISE PERPENDICULAR TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v2 = perpendicular(v1, true);
	std::cout << "Should be: 0,-4\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl;
	v1.x = 8;
	v1.y = 2;
	v2 = perpendicular(v1, true);
	std::cout << "Should be: 2,-8\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl;
	v1.x = -5;
	v1.y = -12;
	v2 = perpendicular(v1, true);
	std::cout << "Should be: -12,5\nIS:";
	std::cout << v2.x << "," << v2.y << std::endl << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\LERP TESTS:\n\n\n";
	v1.x = 0;
	v1.y = 0;
	v2.x = 0;
	v2.y = 5;
	scalar = 0.5;
	result = lerp(v1, v2, scalar);
	std::cout << "Should be: 0,2.5\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;
	v1.x = 0;
	v1.y = 0;
	v2.x = 1;
	v2.y = 1;
	scalar = 0;
	result = lerp(v1, v2, scalar);
	std::cout << "Should be: 0,0\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;
	v1.x = 5;
	v1.y = 12;
	v2.x = 7;
	v2.y = 4;
	scalar = 1;
	result = lerp(v1, v2, scalar);
	std::cout << "Should be: 7,4\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\MIN TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v2.x = 1;
	v2.y = -3;
	result = min(v1, v2);
	std::cout << "Should be: 1,-3\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;
	v1.x = 8;
	v1.y = 2;
	v2.x = 1;
	v2.y = 4;
	result = min(v1, v2);
	std::cout << "Should be: 1,2\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;
	v1.x = 5;
	v1.y = 12;
	v2.x = 0;
	v2.y = 0;
	result = min(v1, v2);
	std::cout << "Should be: 0,0\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\MAX TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v2.x = 1;
	v2.y = -3;
	result = max(v1, v2);
	std::cout << "Should be: 4,0\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;
	v1.x = 8;
	v1.y = 2;
	v2.x = 1;
	v2.y = 4;
	result = max(v1, v2);
	std::cout << "Should be: 8,4\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;
	v1.x = 5;
	v1.y = 12;
	v2.x = 0;
	v2.y = 0;
	result = max(v1, v2);
	std::cout << "Should be: 5,12\nIS:";
	std::cout << result.x << "," << result.y << std::endl << std::endl;

	std::cin.get();

}


