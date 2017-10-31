#pragma once

struct Collision
{
	float penetrationDepth;
	int handedness;
};

Collision intersect1D(float Amin, float Amax, float Bmin, float Bmax);

