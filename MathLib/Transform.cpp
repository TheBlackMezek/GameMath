#include "Transform.h"

#include <cmath>


Transform::Transform()
{
	parent = nullptr;
	pos = { 0, 0 };
	size = { 10, 10 };
	angleRad = 0;
}


Transform::~Transform()
{
}



Mat3 Transform::getLocalTransform() const
{
	return scaleMat(size) * rotationByRad(angleRad) * translation(pos);
	//return translation(pos) * rotationByRad(angleRad) * scaleMat(size);
	//return rotationByRad(angleRad) * scaleMat(size) * translation(pos);
	//return translation(pos) * scaleMat(size) * rotationByRad(angleRad);
}

Mat3 Transform::getGlobalTransform() const
{
	if (parent != nullptr)
	{
		return parent->getGlobalTransform() * getLocalTransform();
	}
	else
	{
		return getLocalTransform();
	}
}

vec2 Transform::getForwardFacing() const
{
	vec2 facing;
	facing.x = cos(angleRad);
	facing.y = -sin(angleRad);
	return facing;
}

vec2 Transform::getUpFacing() const
{
	vec2 facing;
	facing.x = sin(angleRad);
	facing.y = cos(angleRad);
	return facing;
}
