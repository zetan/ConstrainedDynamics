#ifndef  GRAVITY_H
#define GRAVITY_H
#include "Force.h"
class Gravity : public Force{
public:
	Gravity(){gravity = Vector3D(0, -10, 0);}
	~Gravity(){}
	void ApplyForce(Particle* particle){
		
		particle->setForce(Vector3D::Add(particle->getForce(), gravity));}
private:
	Vector3D gravity;
};
#endif