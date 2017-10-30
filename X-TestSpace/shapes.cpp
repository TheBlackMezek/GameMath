#include "shapes.h"

#include <cmath>





circle operator*(const Mat3 &M, const circle &C)
{
	circle ret = C;

	ret.pos = { M[6] * ret.pos.x, M[7] * ret.pos.y };

	vec2 scale;
	scale.x = magnitude({ M[0],M[1] });
	scale.y = magnitude({ M[3],M[4] });

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}

AABB operator*(const Mat3& M, const AABB& B)
{
	AABB ret;



	return ret;
}


