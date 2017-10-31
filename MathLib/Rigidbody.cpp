#include "Rigidbody.h"

#include <iostream>


Rigidbody::Rigidbody()
{
	velocity = { 0,0 };
	acceleration = { 0,0 };
	force = { 0,0 };
	impulse = { 0,0 };
	mass = 1;
	drag = 1;

	torque = 0;
	angularAcceleration = 0;
	angularVelocity = 0;
	angularDrag = 1;
}


Rigidbody::~Rigidbody()
{
}



void Rigidbody::integrate(Transform& T, float dt)
{
	acceleration = force / mass;
	velocity += acceleration * dt + impulse / mass;
	T.pos += velocity * dt;
	force = -velocity * drag;

	impulse = { 0,0 };

	angularAcceleration = torque / mass;
	angularVelocity += angularAcceleration * dt;
	T.angleRad += angularVelocity * dt;
	torque = -angularVelocity * angularDrag;

}
