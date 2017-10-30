#pragma once



#include "Vec2.h"
#include "Rigidbody.h"





class MassEffectField
{
public:
	MassEffectField();
	~MassEffectField();

	vec2 pos;
	float dissipation;
	float strength;


	void effect(Transform& T, Rigidbody& R);
};

