#ifndef PARTICLE_H
#define PARTICLE_H
#include "global.h"

class Particle{
public:
	Particle(){}
	~Particle(){}
	void ClearForce(){force.Set(0, 0, 0);}
private:
	float mass;
	Vector3D pos;
	Vector3D velocity;
	Vector3D force;

};

#endif