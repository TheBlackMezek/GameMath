#include "Collider.h"



Collider::Collider()
{
}


Collider::~Collider()
{
}

AABB Collider::getGlobalBox(const Transform& T) const
{
	return T.getGlobalTransform() * box;
}

Collision collides(const Transform& at, const Collider&ac,
	const Transform& bt, const Collider& bc)
{
	return intersectAABB(ac.getGlobalBox(at), bc.getGlobalBox(bt));
}
