
#include <iostream>

#include "MathUtils.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Mat3.h"
#include "UnitTest.h"


int main()
{
	
	//testVec2();

	//std::cin.get();

	Mat3 mat;
	mat[0] = 1;
	mat[1] = 2;
	mat[2] = 3;
	mat[3] = 4;
	mat[4] = 5;
	mat[5] = 6;
	mat[6] = 7;
	mat[7] = 8;
	mat[8] = 9;

	vec3 vec;
	vec.x = 2;
	vec.y = 1;
	vec.z = 3;

	vec3 result = vec * mat;

	std::cout << result.x << "," << result.y << "," << result.z << std::endl;

	std::cin.get();



	return 0;
}