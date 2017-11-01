#pragma once

#include "shapes.h"

struct Collision
{
	float penetrationDepth;
	int handedness;
	vec2 axis;
};

Collision intersect1D(float Amin, float Amax, float Bmin, float Bmax);

Collision intersectAABB(const AABB& A, const AABB& B);

Collision intersectCircle(const circle& A, const circle& B);

Collision intersectCircleAABB(const circle& A, const AABB& B);



void resolutionStatic(vec2& pos, vec2& vel, const Collision& hit, float elasticity = 1.0f);

void resolutionDynamic( vec2& apos, vec2& avel, const float amass,
						vec2& bpos, vec2& bvel, const float bmass,
						const Collision& hit, float elasticity = 1.0f);
