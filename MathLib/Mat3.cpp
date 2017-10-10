#include "Mat3.h"



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

float& Mat3::operator[](int i)
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
