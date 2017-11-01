#include "Collision.h"

#include <cmath>
#include "MathUtils.h"




Collision intersect1D(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret;

	float lPD = Bmax - Amin;
	float rPD = Amax - Bmin;

	ret.penetrationDepth = min(lPD, rPD);
	ret.handedness = copysign(1, rPD - lPD);

	return ret;
}

Collision intersectAABB(const AABB& A, const AABB& B)
{
	Collision xres = intersect1D(A.min.x, A.max.x, B.min.x, B.max.x);
	Collision yres = intersect1D(A.min.y, A.max.y, B.min.y, B.max.y);

	xres.axis = vec2{ 1, 0 };
	yres.axis = vec2{ 0, 1 };

	return xres.penetrationDepth < yres.penetrationDepth ? xres : yres;
}

Collision intersectCircle(const circle& A, const circle& B)
{
	Collision ret;

	ret.axis = normal(B.pos - A.pos);
	ret.handedness = -1;
	ret.penetrationDepth = (A.radius + B.radius) - distance(A.pos, B.pos);

	return ret;
}

Collision intersectCircleAABB(const circle& A, const AABB& B)
{
	Collision ret;
	ret.handedness = 1;

	vec2 p;
	p.x = clamp(A.pos.x, B.min.x, B.max.x);
	p.y = clamp(A.pos.y, B.min.y, B.max.y);

	vec2 toClosest = p - A.pos;

	ret.axis = normal(toClosest);

	float d = magnitude(toClosest);

	ret.penetrationDepth = A.radius - d;

	return ret;
}



void resolutionStatic(vec2& pos, vec2& vel, const Collision& hit, float elasticity)
{
	pos += hit.axis * hit.handedness * hit.penetrationDepth;

	vel = -reflect(vel, hit.axis * hit.handedness) * elasticity;
}

void resolutionDynamic(	vec2& apos, vec2& avel, const float amass,
						vec2& bpos, vec2& bvel, const float bmass,
						const Collision& hit, float elasticity = 1.0f)
{
	//mass * vel = momentum

	vec2 normal = hit.axis * hit.handedness;

	vec2 rvel = avel - bvel;

	//impulse magnitude - balanced change in magnitude
	float j = -(1+elasticity) * dot(rvel, normal) / dot(normal, normal*(1 / amass + 1 / bmass));

	avel += (j / amass) * normal;
	bvel -= (j / bmass) * normal;

	apos += normal * hit.penetrationDepth * amass / (amass + bmass);
	bpos -= normal * hit.penetrationDepth * bmass / (amass + bmass);
}
