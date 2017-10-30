#pragma once

#include "Vec2.h"
#include "Mat3.h"



struct circle
{
	vec2 pos;
	float radius;
};

struct AABB
{
	vec2 pos;
	vec2 extents;
};



circle operator*(const Mat3 &M, const circle &C);

AABB operator*(const Mat3& M, const AABB& B);
