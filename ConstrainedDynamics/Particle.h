#ifndef PARTICLE_H
#define PARTICLE_H
#include "global.h"

class Particle{
public:
	Particle(){}
	~Particle(){}
	void ClearForce(){force.Set(0, 0, 0);}
	void Draw();

	float getMass() const { return mass; }
	void setMass(float val) { mass = val; }
	Vector3D getPos() const { return pos; }
	void setPos(Vector3D val) { pos = val; }
	Vector3D getVelocity() const { return velocity; }
	void setVelocity(Vector3D val) { velocity = val; }
	Vector3D getForce() const { return force; }
	void setForce(Vector3D val) { force = val; }
private:
	float mass;
	Vector3D pos;
	Vector3D velocity;	
	Vector3D force;
	
};

#endif