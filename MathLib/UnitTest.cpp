
#include "UnitTest.h"


#include <cassert>
#include <iostream>

#include "Vec2.h"
#include "Vec3.h"
#include "Mat3.h"



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

void testVec3()
{
	vec3 v1;
	vec3 v2;
	float scalar;
	vec3 result;
	vec3 expected;


	v1.x = 10;
	v1.y = 20;
	v1.z = 40;
	v2.x = 10;
	v2.y = 20;
	v2.z = 40;
	assert(v1 == v2);
	v1.x = 8;
	assert(v1 != v2);

	v1.x = 1;
	v1.y = 2;
	v1.z = 3;
	v2.x = 9;
	v2.y = 18;
	v2.z = 37;
	expected.x = 10;
	expected.y = 20;
	expected.z = 40;
	assert(v1 + v2 == expected);

	v1.x = 11;
	v1.y = 21;
	v1.z = 41;
	v2.x = 1;
	v2.y = 1;
	v2.z = 1;
	assert(v1 - v2 == expected);

	v1.x = 5;
	v1.y = 10;
	v1.z = 20;
	scalar = 2;
	assert(v1 * scalar == expected);
	assert(scalar * v1 == expected);

	v1.x = 20;
	v1.y = 40;
	v1.z = 80;
	assert(v1 / scalar == expected);

	v1.x = -10;
	v1.y = -20;
	v1.z = -40;
	assert(-v1 == expected);

	v1.x = 1;
	v1.y = 2;
	v1.z = 3;
	v2.x = 9;
	v2.y = 18;
	v2.z = 37;
	assert((v1 += v2) == expected);

	v1.x = 11;
	v1.y = 21;
	v1.z = 41;
	v2.x = 1;
	v2.y = 1;
	v2.z = 1;
	assert((v1 -= v2) == expected);

	v1.x = 5;
	v1.y = 10;
	v1.z = 20;
	scalar = 2;
	assert((v1 *= scalar) == expected);

	v1.x = 20;
	v1.y = 40;
	v1.z = 80;
	assert((v1 /= scalar) == expected);

	assert(v1[0] == 10);




	std::cout << "MAGNITUDE TESTS:\n\n\n";
	v1.x = 0;
	v1.y = 1;
	v1.z = 0;
	std::cout << "Should be: 1\nIS:";
	std::cout << magnitude(v1) << std::endl << std::endl;
	v1.x = 1;
	v1.y = 1;
	v1.z = 1;
	std::cout << "Should be: ~1.73205\nIS:";
	std::cout << magnitude(v1) << std::endl << std::endl;
	v1.x = -2;
	v1.y = 3;
	v1.z = 5;
	std::cout << "Should be: ~6.16441\nIS:";
	std::cout << magnitude(v1) << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\nNORMALIZATION TESTS:\n\n\n";
	v1.x = 0;
	v1.y = 1;
	v1.z = 0;
	v2 = normal(v1);
	std::cout << "Should be: 0,1,0\nIS:";
	std::cout << v2.x << "," << v2.y << "," << v2.z << std::endl << std::endl;
	v1.x = 1;
	v1.y = 1;
	v1.z = 1;
	v2 = normal(v1);
	std::cout << "Should be: 0.577350,0.577350,0.577350\nIS:";
	std::cout << v2.x << "," << v2.y << "," << v2.z << std::endl << std::endl;
	v1.x = -2;
	v1.y = 3;
	v1.z = 5;
	v2 = normal(v1);
	std::cout << "Should be: -0.32444,0.811107,\nIS:";
	std::cout << v2.x << "," << v2.y << "," << v2.z << std::endl << std::endl << std::endl;

	v1.x = 0;
	v1.y = 1;
	v1.z = 0;
	normalize(v1);
	std::cout << "Should be: 0,1,0\nIS:";
	std::cout << v1.x << "," << v1.y << "," << v1.z << std::endl << std::endl;
	v1.x = 1;
	v1.y = 1;
	v1.z = 1;
	normalize(v1);
	std::cout << "Should be: 0.577350,0.577350,0.577350\nIS:";
	std::cout << v1.x << "," << v1.y << "," << v1.z << std::endl << std::endl;
	v1.x = -2;
	v1.y = 3;
	v1.z = 5;
	normalize(v1);
	std::cout << "Should be: -0.32444,0.811107,\nIS:";
	std::cout << v1.x << "," << v1.y << "," << v1.z << std::endl << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\DOT PRODUCT TESTS:\n\n\n";
	v1.x = 2;
	v1.y = 3;
	v1.z = 4;
	v2.x = 7;
	v2.y = 5;
	v2.z = 3;
	scalar = dot(v1, v2);
	std::cout << "Should be: 41\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 1;
	v1.y = 0;
	v1.z = 0;
	v2.x = 1;
	v2.y = 1;
	v2.z = 1;
	scalar = dot(v1, v2);
	std::cout << "Should be: 1\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 4;
	v1.y = 0;
	v1.z = 0;
	v2.x = 1;
	v2.y = -3;
	v2.z = 1;
	scalar = dot(v1, v2);
	std::cout << "Should be: 4\nIS:";
	std::cout << scalar << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\DISTANCE TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v1.z = 0;
	v2.x = 1;
	v2.y = -3;
	v2.z = 1;
	scalar = distance(v1, v2);
	std::cout << "Should be: 4.358899\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 8;
	v1.y = 2;
	v1.z = 4;
	v2.x = 1;
	v2.y = 4;
	v2.z = 8;
	scalar = distance(v1, v2);
	std::cout << "Should be: 8.306624\nIS:";
	std::cout << scalar << std::endl << std::endl;
	v1.x = 5;
	v1.y = 12;
	v1.z = 20;
	v2.x = 0;
	v2.y = 0;
	v2.z = 0;
	scalar = distance(v1, v2);
	std::cout << "Should be: 23.853721\nIS:";
	std::cout << scalar << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\CROSS PRODUCT TESTS:\n\n\n";
	v1.x = 2;
	v1.y = 3;
	v1.z = 4;
	v2.x = 5;
	v2.y = 6;
	v2.z = 7;
	result = cross(v1, v2);
	std::cout << "Should be: -3,6,-3\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;
	v1.x = 1;
	v1.y = 3;
	v1.z = 9;
	v2.x = 4;
	v2.y = 4;
	v2.z = 4;
	result = cross(v1, v2);
	std::cout << "Should be: -24,32,-8\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;
	v1.x = -1;
	v1.y = -9;
	v1.z = -19;
	v2.x = 2;
	v2.y = -2;
	v2.z = 4;
	result = cross(v1, v2);
	std::cout << "Should be: -74,-34,20\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\MIN TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v1.z = 0;
	v2.x = 1;
	v2.y = -3;
	v2.z = 1;
	result = min(v1, v2);
	std::cout << "Should be: 1,-3,1\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;
	v1.x = 2;
	v1.y = 4;
	v1.z = 7;
	v2.x = -6;
	v2.y = 1;
	v2.z = 18;
	result = min(v1, v2);
	std::cout << "Should be: -6,1,7\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;
	v1.x = 444;
	v1.y = 333;
	v1.z = 222;
	v2.x = 111;
	v2.y = -309;
	v2.z = 999;
	result = min(v1, v2);
	std::cout << "Should be: 111,-309,222\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;

	std::cin.get();

	std::cout << "\n\n\MAX TESTS:\n\n\n";
	v1.x = 4;
	v1.y = 0;
	v1.z = 0;
	v2.x = 1;
	v2.y = -3;
	v2.z = 1;
	result = max(v1, v2);
	std::cout << "Should be: 4,0,1\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;
	v1.x = 2;
	v1.y = 4;
	v1.z = 7;
	v2.x = -6;
	v2.y = 1;
	v2.z = 18;
	result = max(v1, v2);
	std::cout << "Should be: 2,4,18\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;
	v1.x = 444;
	v1.y = 333;
	v1.z = 222;
	v2.x = 111;
	v2.y = -309;
	v2.z = 999;
	result = max(v1, v2);
	std::cout << "Should be: 444,333,999\nIS:";
	std::cout << result.x << "," << result.y << "," << result.z << std::endl << std::endl;

	std::cin.get();

}

void testMat3Inverse()
{
	Mat3 m;
	m[0] = 9;
	m[1] = -6;
	m[2] = -1;
	m[3] = 3;
	m[4] = -9;
	m[5] = -8;
	m[6] = 5;
	m[7] = 7;
	m[8] = 1;

	std::cout << "Should be:\n"
		"47 -43  66\n"
		"-1  14 -93\n"
		"39  69 -63\n\n";

	Mat3 mm = inverse(m);

	std::cout << "Is:\n"
		<< mm[0] << " " << mm[3] << "  " << mm[6] << std::endl
		<< mm[1] << "  " << mm[4] << " " << mm[7] << std::endl
		<< mm[2] << "  " << mm[5] << " " << mm[8] << std::endl;

	std::cin.get();
}

void testMat3Determinant()
{
	Mat3 m;
	m[0] = 9;
	m[1] = -6;
	m[2] = -1;
	m[3] = 3;
	m[4] = -9;
	m[5] = -8;
	m[6] = 5;
	m[7] = 7;
	m[8] = 1;

	float d = determinant(m);

	std::cout << "Should be:\n615\n\nIs:\n" << d << std::endl;

	std::cin.get();
}

void testMat3xIdentity()
{
	Mat3 m;
	m[0] = 9;
	m[1] = -6;
	m[2] = -1;

	m[3] = 3;
	m[4] = -9;
	m[5] = -8;

	m[6] = 5;
	m[7] = 7;
	m[8] = 1;

	Mat3 I;
	I[0] = 1;
	I[1] = 0;
	I[2] = 0;

	I[3] = 0;
	I[4] = 1;
	I[5] = 0;

	I[6] = 0;
	I[7] = 0;
	I[8] = 1;


	m = m * I;

	std::cout << "Should be:\n"
		"9 3 5\n"
		"-6 -9 7\n"
		"-1 -8 1\n\n";

	std::cout << "Is:\n"
		<< m[0] << " " << m[3] << " " << m[6] << std::endl
		<< m[1] << " " << m[4] << " " << m[7] << std::endl
		<< m[2] << " " << m[5] << " " << m[8] << std::endl;

	std::cin.get();
}
