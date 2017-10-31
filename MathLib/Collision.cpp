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
