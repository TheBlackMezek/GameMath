#pragma once

#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Sprite.h"



class Player
{
public:
	Transform transform;
	Rigidbody body;
	Collider collider;
	Sprite sprite;
};

class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

class Ball
{
public:
	Transform transform;
	Rigidbody body;
	Collider collider;
	Sprite sprite;
};



bool doCollision(Player& player, const Wall& wall);
bool doCollision(Player& player, const Ball& ball);
bool doCollision(Ball& ball, Wall& wall);
