
#include <iostream>

#include "sfwdraw.h"

#include "MathUtils.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Mat3.h"
#include "UnitTest.h"


int main()
{
	
	//testVec2();
	//testVec3();
	testMat3Inverse();
	testMat3Determinant();

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



	sfw::initContext(800, 600, "StarBlock One");

	sfw::setBackgroundColor(BLACK);

	vec2 playerPos;
	playerPos.x = 30;
	playerPos.y = 30;

	float orbRot = 0;
	vec2 orbPos;
	orbPos.x = 0;
	orbPos.y = 0;

	vec2 testone;
	testone.x = 10;
	testone.y = 0;
	vec2 testtwo;
	testtwo.x = -10;
	testtwo.y = 10;
	std::cout << isAngleClockwise(testone, testtwo) << std::endl;

	while (sfw::stepContext())
	{
		if (sfw::getKey('W'))
		{
			playerPos.y += 2;
		}
		if (sfw::getKey('A'))
		{
			playerPos.x -= 2;
		}
		if (sfw::getKey('S'))
		{
			playerPos.y -= 2;
		}
		if (sfw::getKey('D'))
		{
			playerPos.x += 2;
		}

		orbRot += 0.1;
		orbPos.x = playerPos.x + cos(orbRot) * 20;
		orbPos.y = playerPos.y + sin(orbRot) * 20;

		sfw::drawCircle(playerPos.x, playerPos.y, 10);
		sfw::drawCircle(orbPos.x, orbPos.y, 2);
	}



	//std::cin.get();



	return 0;
}