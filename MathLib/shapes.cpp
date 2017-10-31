#include "shapes.h"

#include <cmath>

#include "Vec3.h"
#include"Vec2.h"





circle operator*(const Mat3 &M, const circle &C)
{
	circle ret = C;

	ret.pos = { M[6] * ret.pos.x, M[7] * ret.pos.y };

	vec2 scale;
	scale.x = magnitude(vec2{ M[0],M[1] });
	scale.y = magnitude(vec2{ M[3],M[4] });

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}

AABB operator*(const Mat3& M, const AABB& B)
{
	AABB ret = B;

	vec2 tr = B.max;
	vec2 tl = { B.min.x, B.max.y };
	vec2 br = { B.max.x, B.min.y };
	vec2 bl = B.min;

	tr = mulpos(M, tr);
	tl = mulpos(M, tl);
	br = mulpos(M, br);
	bl = mulpos(M, bl);

	//tr = (tr * M).xy;
	//tl = (tl * M).xy;
	//br = (br * M).xy;
	//l = (bl * M).xy;

	ret.min = min(tr, tl);
	ret.min = min(ret.min, br);
	ret.min = min(ret.min, bl);

	ret.max = max(tr, tl);
	ret.max = max(ret.max, br);
	ret.max = max(ret.max, bl);

	return ret;
}


