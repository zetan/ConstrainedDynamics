#ifndef  GRAVITY_H
#define GRAVITY_H
#include "Force.h"
class Gravity : public Force{
public:
	Gravity(){}
	~Gravity(){}
	void ApplyForce(Particle* particle){
		particle->force = Vector3D.Add(particle->force, gravity);}
private:
	const Vector3D gravity = Vector3D(0, -10, 0); 
};
#endif