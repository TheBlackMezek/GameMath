
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "sfwdraw.h"

#include "MathUtils.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Mat3.h"
#include "UnitTest.h"
#include "DrawShapes.h"
#include "Collision.h"
#include "GameObjects.h"



//void drawTransformCircle()
void debugDraw(Transform& t);
void drawAABB(AABB b);


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

	

	sfw::initContext(800, 600, "MathTest");

	sfw::setBackgroundColor(BLACK);

	

	Player player;
	player.transform.pos = { 400, 300 };
	player.transform.disfigure = { 2, 2 };
	player.body.mass = 10;
	player.body.drag = 10;

	AABB box;
	box.min = { -20, -20 };
	box.max = { 20, 20 };
	AABB otherBox;
	otherBox.min = { 100, 100 };
	otherBox.max = { 130, 150 };
	circle hitCircle;
	hitCircle.pos = { 400, 400 };
	hitCircle.radius = 20;
	circle hitCircle2;
	hitCircle2.pos = { 100, 400 };
	hitCircle2.radius = 20;
	//boxBase.pos = box.min;
	//boxBase.disfigure = box.max - box.min;

	float thrusterForce = 1000;
	float angularForce = 20;

	/*Transform orbball;
	orbball.pos = { 10, 10 };
	orbball.parent = &player;
	Transform orb2;
	orb2.pos = { 10, 10 };
	orb2.parent = &orbball;*/



	while (sfw::stepContext())
	{
		vec2 ffacing = player.transform.getForwardFacing();
		vec2 ufacing = player.transform.getUpFacing();


		if (sfw::getKey('W'))
		{
			//player.pos.y += 2;
			//player.pos += 2 * ufacing;
			player.body.force += ufacing * thrusterForce;
		}
		if (sfw::getKey('S'))
		{
			//player.pos.y -= 2;
			//player.pos -= 2 * ufacing;
			player.body.force += ufacing * -thrusterForce;
		}

		if (sfw::getKey('A'))
		{
			//player.pos.x -= 2;
			//player.pos -= 2 * ffacing;
			player.body.force += ffacing * -thrusterForce;
		}
		if (sfw::getKey('D'))
		{
			//player.pos.x += 2;
			//player.pos += 2 * ffacing;
			player.body.force += ffacing * thrusterForce;
		}


		if (sfw::getKey('Q'))
		{
			player.body.torque -= M_PI * angularForce;
		}
		if (sfw::getKey('E'))
		{
			player.body.torque += M_PI * angularForce;
		}

		if(sfw::getKey('B'))
		{
			player.body.torque = 0;
			player.body.angularAcceleration = 0;
			player.body.angularVelocity = 0;
		}

		

		//field.effect(player, body);
		player.body.integrate(player.transform, sfw::getDeltaTime());

		//orbball.angleRad += 0.01f;
		//orb2.angleRad -= 0.01f;

		//orbRot += 0.1;
		//orbPos.x = playerPos.x + cos(orbRot) * 20;
		//orbPos.y = playerPos.y + sin(orbRot) * 20;

		//sfw::drawCircle(playerPos.x, playerPos.y, 10);
		//sfw::drawCircle(orbPos.x, orbPos.y, 2);

		//drawAABB(box);
		//AABB boxRender = player.getGlobalTransform() * box;
		/*AABB boxRender = rotationByRad(player.angleRad) * box;
		boxRender.max += vec2{ 100, 100 };
		boxRender.min += vec2{ 100, 100 };
		std::cout << boxRender.min.x << "," << boxRender.min.y << ",";
		std::cout << boxRender.max.x << "," << boxRender.max.y << std::endl;*/
		//drawAABB(boxRender);

		//player.getGlobalTransform() * box;
		

		auto trans = player.transform.getGlobalTransform();
		auto temp = trans * box;

		Collision col = intersectAABB(temp, otherBox);
		if (col.penetrationDepth > 0)
		{
			resolutionStatic(player.transform.pos, player.body.velocity, col, 0.25f);
			//player.pos += col.axis * col.handedness * (col.penetrationDepth);
			trans = player.transform.getGlobalTransform();
			temp = trans * box;
			//body.force += col.axis * col.handedness * (col.penetrationDepth * 2);
		}

		col = intersectCircle({ {player.transform.pos.x, player.transform.pos.y}, 10 }, hitCircle);
		if (col.penetrationDepth > 0)
		{
			resolutionStatic(player.transform.pos, player.body.velocity, col, 1.0f);
			//player.pos += col.axis * col.handedness * (col.penetrationDepth);
		}

		col = intersectCircleAABB(hitCircle2, temp);
		if (col.penetrationDepth > 0)
		{
			resolutionStatic(player.transform.pos, player.body.velocity, col, 0.25f);
			//player.pos += col.axis * col.handedness * (col.penetrationDepth);
			trans = player.transform.getGlobalTransform();
			temp = trans * box;
		}
		


		debugDraw(player.transform);
		drawAABB(otherBox);
		drawAABB(temp);
		sfw::drawCircle(hitCircle.pos.x, hitCircle.pos.y, hitCircle.radius);
		sfw::drawCircle(hitCircle2.pos.x, hitCircle2.pos.y, hitCircle2.radius);
		
		//debugDraw(orbball);
		//debugDraw(orb2);
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

void drawAABB(AABB b)
{
	sfw::drawLine(b.min.x, b.min.y, b.max.x, b.min.y);
	sfw::drawLine(b.min.x, b.max.y, b.max.x, b.max.y);
	sfw::drawLine(b.min.x, b.min.y, b.min.x, b.max.y);
	sfw::drawLine(b.max.x, b.min.y, b.max.x, b.max.y);
}
