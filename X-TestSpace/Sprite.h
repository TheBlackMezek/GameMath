#pragma once


#include "Vec2.h"
#include "Transform.h"
#include "Mat3.h"



class Sprite
{
public:
	Sprite();
	~Sprite();

	int texId;
	vec2 dim;
	vec2 offset;

	void draw(const Transform& t, const Mat3& cam = mat3identity());
};

