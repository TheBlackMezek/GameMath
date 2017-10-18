
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "sfwdraw.h"

#include "MathUtils.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Mat3.h"
#include "UnitTest.h"
#include "Transform.h"



//void drawTransformCircle()
void debugDraw(Transform& t);


int main()
{
	
	//testVec2();
	//testVec3();
	//testMat3Basic();
	//testMat3Transforms();
	//testMat3xIdentity();
	//testMat3Inverse();
	//testMat3Determinant();

	//std::cin.get();

	

	sfw::initContext(800, 600, "StarBlock One");

	sfw::setBackgroundColor(BLACK);

	

	Transform player;
	player.pos = { 10, 10 };
	player.disfigure = { 2, 2 };
	Transform orbball;
	orbball.pos = { 10, 10 };
	orbball.parent = &player;
	Transform orb2;
	orb2.pos = { 10, 10 };
	orb2.parent = &orbball;



	while (sfw::stepContext())
	{
		vec2 ffacing = player.getForwardFacing();
		vec2 ufacing = player.getUpFacing();
		if (sfw::getKey('W'))
		{
			//player.pos.y += 2;
			player.pos += 2 * ufacing;
		}
		if (sfw::getKey('A'))
		{
			//player.pos.x -= 2;
			player.pos -= 2 * ffacing;
		}
		if (sfw::getKey('S'))
		{
			//player.pos.y -= 2;
			player.pos -= 2 * ufacing;
		}
		if (sfw::getKey('D'))
		{
			//player.pos.x += 2;
			player.pos += 2 * ffacing;
		}
		if (sfw::getKey('Q'))
		{
			player.angleRad -= 0.1f;
			if (player.angleRad > M_PI * 2)
			{
				player.angleRad -= M_PI * 2;
			}
		}
		if (sfw::getKey('E'))
		{
			player.angleRad += 0.1f;
			if (player.angleRad < 0)
			{
				player.angleRad += M_PI * 2;
			}
		}

		orbball.angleRad += 0.01f;
		orb2.angleRad -= 0.01f;

		//orbRot += 0.1;
		//orbPos.x = playerPos.x + cos(orbRot) * 20;
		//orbPos.y = playerPos.y + sin(orbRot) * 20;

		//sfw::drawCircle(playerPos.x, playerPos.y, 10);
		//sfw::drawCircle(orbPos.x, orbPos.y, 2);
		debugDraw(player);
		debugDraw(orbball);
		debugDraw(orb2);
	}



	//std::cin.get();



	return 0;
}


void debugDraw(Transform& t)
{
	float drawScale = 10;

	Mat3 m = t.getGlobalTransform();
	//Mat3 m = translation(collider.pos);
	//Mat3 m = rotationByRad(rotation);
	//Mat3 m = scaleMat({ collider.radius * 2, collider.radius * 2 }) * rotationByRad(rotation) * translation(collider.pos);

	vec2 pos = { m[6], m[7] };
	vec2 right_ep = { pos.x + m[0] * drawScale, pos.y + m[1] * drawScale };
	vec2 up_ep = { pos.x + m[3] * drawScale, pos.y + m[4] * drawScale };

	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawScale);
}