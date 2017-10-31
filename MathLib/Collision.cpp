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

	float ap = dot(ret.axis, A.pos);
	float bp = dot(ret.axis, B.pos);

	float Amin = ap - A.radius;
	float Amax = ap + A.radius;

	float Bmin = bp - B.radius;
	float Bmax = bp + B.radius;

	ret.penetrationDepth = intersect1D(Amin, Amax, Bmin, Bmax).penetrationDepth;
	ret.penetrationDepth = (A.radius + B.radius) - distance(A.pos, B.pos);

	return ret;
}
