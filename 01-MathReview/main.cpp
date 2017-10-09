
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>


struct QuadRet
{
	float pos;
	float neg;
};


float dbl(float f);
float cube(float f);
float rad(float d);
float deg(float r);
float quad_basic(float x, float c);
QuadRet quadratic(float a, float b, float c);
float lerp(float s, float e, float a);
float dist(float x1, float y1, float x2, float y2);



int main()
{
	
	



	return 0;
}






float dbl(float f)
{
	return f * 2;
}

float cube(float f)
{
	return f * f * f;
}

float rad(float d)
{
	return d * (M_PI / 180);
}

float deg(float r)
{
	return r * (180 / M_PI);
}

float quad_basic(float x, float c)
{
	return (x * x) + (2 * x) - c;
}

QuadRet quadratic(float a, float b, float c)
{
	QuadRet ret;
	ret.pos = ((-1 * b) + sqrt((b * b) - (4 * a * c)) ) / (2 * a);
	ret.neg = ((-1 * b) - sqrt((b * b) - (4 * a * c))) / (2 * a);

	return ret;
}

float lerp(float s, float e, float a)
{
	return s + a * (e - s);
}

float dist(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x1 + x2, 2) + pow(y1 + y2, 2));
}
