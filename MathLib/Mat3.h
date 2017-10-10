#pragma once
class Mat3
{
public:
	Mat3();
	~Mat3();

	float m[9];

	float& operator[](int i);
};

Mat3 operator+(const Mat3& lhs, const Mat3& rhs);
