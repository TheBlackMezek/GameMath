
#include "Vec3.h"

#include <cmath>
#include <cfloat>








float& vec3::operator[] (const int idx)
{
	return v[idx];
}

const float& vec3::operator[](const int idx) const
{
	return v[idx];
}




float magnitude(vec3 vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
vec3 normal(vec3 vec)
{
	vec3 ret;
	float mag = magnitude(vec);
	ret.x = vec.x / mag;
	ret.y = vec.y / mag;
	ret.z = vec.z / mag;
	return ret;
}
vec3& normalize(vec3& vec)
{
	float mag = magnitude(vec);
	vec.x /= mag;
	vec.y /= mag;
	vec.z /= mag;
	return vec;
}
float dot(vec3 v1, vec3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
float distance(vec3 v1, vec3 v2)
{
	return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}
vec3 min(vec3 v1, vec3 v2)
{
	vec3 ret;
	ret.x = v1.x < v2.x ? v1.x : v2.x;
	ret.y = v1.y < v2.y ? v1.y : v2.y;
	ret.z = v1.z < v2.z ? v1.z : v2.z;
	return ret;
}
vec3 max(vec3 v1, vec3 v2)
{
	vec3 ret;
	ret.x = v1.x > v2.x ? v1.x : v2.x;
	ret.y = v1.y > v2.y ? v1.y : v2.y;
	ret.z = v1.z > v2.z ? v1.z : v2.z;
	return ret;
}
vec3 cross(vec3 v1, vec3 v2)
{
	vec3 ret;
	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return ret;
}







vec3 operator+(const vec3 &lhs, const vec3 &rhs)
{
	vec3 ret;
	ret.x = lhs.x + rhs.x;
	ret.y = lhs.y + rhs.y;
	return ret;
}
vec3 operator-(const vec3 &lhs, const vec3 &rhs)
{
	vec3 ret;
	ret.x = lhs.x - rhs.x;
	ret.y = lhs.y - rhs.y;
	return ret;
}
vec3 operator*(const vec3 &lhs, const float &rhs)
{
	vec3 ret;
	ret.x = lhs.x * rhs;
	ret.y = lhs.y * rhs;
	return ret;
}
vec3 operator*(const float &lhs, const vec3 &rhs)
{
	vec3 ret;
	ret.x = lhs * rhs.x;
	ret.y = lhs * rhs.y;
	return ret;
}
vec3 operator/(const vec3 &lhs, const float &rhs)
{
	vec3 ret;
	ret.x = lhs.x / rhs;
	ret.y = lhs.y / rhs;
	return ret;
}
vec3 operator-(const vec3 &rhs)
{
	vec3 ret;
	ret.x = -rhs.x;
	ret.y = -rhs.y;
	return ret;
}



vec3& operator+=(vec3& lhs, const vec3& rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}
vec3& operator-=(vec3& lhs, const vec3& rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}
vec3& operator*=(vec3& lhs, const float& rhs)
{
	lhs.x *= rhs;
	lhs.y *= rhs;

	return lhs;
}
vec3& operator/=(vec3& lhs, const float& rhs)
{
	lhs.x /= rhs;
	lhs.y /= rhs;

	return lhs;
}



bool operator==(const vec3 &lhs, const vec3 &rhs)
{
	return	(abs(lhs.x - rhs.x) < FLT_EPSILON) &&
		(abs(lhs.y - rhs.y) < FLT_EPSILON) ? true : false;
}
bool operator!=(const vec3 &lhs, const vec3 &rhs)
{
	return	(abs(lhs.x - rhs.x) < FLT_EPSILON) &&
		(abs(lhs.y - rhs.y) < FLT_EPSILON) ? false : true;
}
