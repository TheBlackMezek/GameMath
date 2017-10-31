
#include "MathUtils.h"


int min(int a, int b)
{
	return a < b ? a : b;
}

float clamp(float n, float min, float max)
{
	float ret = n;

	if (ret < min)
	{
		ret = min;
	}
	else if (ret > max)
	{
		ret = max;
	}

	return ret;
}
