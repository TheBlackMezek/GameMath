#include "Mat3.h"

#include "Vec3.h"


Mat3::Mat3()
{
	for (int i = 0; i < 9; ++i)
	{
		m[i] = 0;
	}
}

Mat3::~Mat3()
{
}

float& Mat3::operator[](const size_t i)
{
	return m[i];
}

const float& Mat3::operator[](const size_t i) const
{
	return m[i];
}



Mat3 operator+(const Mat3& lhs, const Mat3& rhs)
{
	Mat3 ret;
	for (int i = 0; i < 9; ++i)
	{
		ret[i] = lhs[i] + rhs[i];
	}
	return ret;
}
Mat3 operator-(const Mat3& lhs, const Mat3& rhs)
{
	Mat3 ret;
	for (int i = 0; i < 9; ++i)
	{
		ret[i] = lhs[i] - rhs[i];
	}
	return ret;
}
Mat3 operator-(const Mat3& lhs)
{
	Mat3 ret;
	for (int i = 0; i < 9; ++i)
	{
		ret[i] = -lhs[i];
	}
	return ret;
}
Mat3 operator*(const Mat3& lhs, const float& rhs)
{
	Mat3 ret;
	for (int i = 0; i < 9; ++i)
	{
		ret[i] = lhs[i] * rhs;
	}
	return ret;
}
Mat3 operator*(const float& lhs, const Mat3& rhs)
{
	Mat3 ret;
	for (int i = 0; i < 9; ++i)
	{
		ret[i] = rhs[i] * lhs;
	}
	return ret;
}
Mat3 operator*(const Mat3& lhs, const Mat3& rhs)
{
	Mat3 ret;
	for (int y = 0; y < 3; ++y)
	{
		vec3 lhsRow;
		lhsRow.x = lhs[0 + y * 3];
		lhsRow.y = lhs[1 + y * 3];
		lhsRow.z = lhs[2 + y * 3];
		for (int x = 0; x < 3; ++x)
		{
			vec3 rhsColumn;
			rhsColumn.x = lhs[x];
			rhsColumn.y = lhs[x + 1 * 3];
			rhsColumn.z = lhs[x + 2 * 3];

			ret[x + y * 3] = dot(lhsRow, rhsColumn);
		}
	}
	return ret;
}
vec3 operator*(const Mat3& lhs, const vec3& rhs)
{
	vec3 ret;
	ret.x = lhs[0] * rhs.x + lhs[1] * rhs.y + lhs[2] * rhs.z;
	ret.y = lhs[3] * rhs.x + lhs[4] * rhs.y + lhs[5] * rhs.z;
	ret.z = lhs[6] * rhs.x + lhs[7] * rhs.y + lhs[8] * rhs.z;
	return ret;
}
vec3 operator*(const vec3& lhs, const Mat3& rhs)
{
	vec3 ret;
	ret.x = rhs[0] * lhs.x + rhs[1] * lhs.y + rhs[2] * lhs.z;
	ret.y = rhs[3] * lhs.x + rhs[4] * lhs.y + rhs[5] * lhs.z;
	ret.z = rhs[6] * lhs.x + rhs[7] * lhs.y + rhs[8] * lhs.z;
	return ret;
}



Mat3 transposition(const Mat3& m)
{
	Mat3 ret;

	ret[0] = m[0];
	ret[1] = m[3];
	ret[2] = m[6];
	ret[3] = m[1];
	ret[4] = m[4];
	ret[5] = m[7];
	ret[6] = m[2];
	ret[7] = m[5];
	ret[8] = m[8];

	return ret;
}
Mat3 transpose(Mat3& m)
{
	Mat3 ret;

	ret[0] = m[0];
	ret[1] = m[3];
	ret[2] = m[6];
	ret[3] = m[1];
	ret[4] = m[4];
	ret[5] = m[7];
	ret[6] = m[2];
	ret[7] = m[5];
	ret[8] = m[8];

	for (int i = 0; i < 9; ++i)
	{
		m[i] = ret[i];
	}

	return m;
}
