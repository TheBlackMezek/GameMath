
#include "Vec2.h"

#include <cmath>
#include <cfloat>








float& vec2::operator[] (const size_t idx)
{
	return v[idx];
}

const float& vec2::operator[](const size_t idx) const
{
	return v[idx];
}




float magnitude(vec2 vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}
vec2 normal(vec2 vec)
{
	vec2 ret;
	float mag = magnitude(vec);
	ret.x = vec.x / mag;
	ret.y = vec.y / mag;
	return ret;
}
vec2& normalize(vec2& vec)
{
	float mag = magnitude(vec);
	vec.x /= mag;
	vec.y /= mag;
	return vec;
}
float dot(vec2 v1, vec2 v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}
float angle(vec2 v1, vec2 v2)
{
	return acos(dot(v1, v2) / (magnitude(v1) * magnitude(v2)));
}
bool isAngleClockwise(vec2 v1, vec2 v2)
{
	vec2 perp = perpendicular(v2, true);
	return dot(v1, perp) > 0 ? true : false;
}
float distance(vec2 v1, vec2 v2)
{
	return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}
vec2 perpendicular(vec2 vec, bool clockwise)
{
	vec2 ret;
	if (clockwise)
	{
		ret.x = vec.y;
		ret.y = -vec.x;
	}
	else
	{
		ret.x = -vec.y;
		ret.y = vec.x;
	}
	return ret;
}
vec2 lerp(vec2 s, vec2 e, float a)
{
	return s + a * (e - s);
}
vec2 min(vec2 v1, vec2 v2)
{
	vec2 ret;
	ret.x = v1.x < v2.x ? v1.x : v2.x;
	ret.y = v1.y < v2.y ? v1.y : v2.y;
	return ret;
}
vec2 max(vec2 v1, vec2 v2)
{
	vec2 ret;
	ret.x = v1.x > v2.x ? v1.x : v2.x;
	ret.y = v1.y > v2.y ? v1.y : v2.y;
	return ret;
}







vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	vec2 ret;
	ret.x = lhs.x + rhs.x;
	ret.y = lhs.y + rhs.y;
	return ret;
}
vec2 operator-(const vec2 &lhs, const vec2 &rhs)
{
	vec2 ret;
	ret.x = lhs.x - rhs.x;
	ret.y = lhs.y - rhs.y;
	return ret;
}
vec2 operator*(const vec2 &lhs, const float &rhs)
{
	vec2 ret;
	ret.x = lhs.x * rhs;
	ret.y = lhs.y * rhs;
	return ret;
}
vec2 operator*(const float &lhs, const vec2 &rhs)
{
	vec2 ret;
	ret.x = lhs * rhs.x;
	ret.y = lhs * rhs.y;
	return ret;
}
vec2 operator/(const vec2 &lhs, const float &rhs)
{
	vec2 ret;
	ret.x = lhs.x / rhs;
	ret.y = lhs.y / rhs;
	return ret;
}
vec2 operator-(const vec2 &rhs)
{
	vec2 ret;
	ret.x = -rhs.x;
	ret.y = -rhs.y;
	return ret;
}



vec2& operator+=(vec2& lhs, const vec2& rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}
vec2& operator-=(vec2& lhs, const vec2& rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}
vec2& operator*=(vec2& lhs, const float& rhs)
{
	lhs.x *= rhs;
	lhs.y *= rhs;

	return lhs;
}
vec2& operator/=(vec2& lhs, const float& rhs)
{
	lhs.x /= rhs;
	lhs.y /= rhs;

	return lhs;
}



bool operator==(const vec2 &lhs, const vec2 &rhs)
{
	return	(abs(lhs.x - rhs.x) < FLT_EPSILON) && 
			(abs(lhs.y - rhs.y) < FLT_EPSILON) ? true : false;
}
bool operator!=(const vec2 &lhs, const vec2 &rhs)
{
	return	(abs(lhs.x - rhs.x) < FLT_EPSILON) &&
			(abs(lhs.y - rhs.y) < FLT_EPSILON) ? false : true;
}
