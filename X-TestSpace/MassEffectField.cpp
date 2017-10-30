#include "MassEffectField.h"



MassEffectField::MassEffectField()
{
	pos = { 0,0 };
	dissipation = 0.5f;
	strength = -50;
}


MassEffectField::~MassEffectField()
{
}




void MassEffectField::effect(Transform& T, Rigidbody& R)
{
	R.massEffect = (strength / distance(T.pos, pos)) / dissipation;
}

