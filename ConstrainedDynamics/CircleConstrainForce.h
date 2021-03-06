#ifndef CIRCLE_CONSTRAIN_FORCE_H
#define CIRCLE_CONSTRAIN_FORCE_H
#include "global.h"
#include "Particle.h"
#include "Force.h"

class CircleConstrainForce : public Force{
public:
	CircleConstrainForce();
	~CircleConstrainForce(){}
	void ApplyForce(Particle* particle);
	Vector3D& getConstrainForce(){return constrainForce;}
private:
	double kd;
	double ks;
	Vector3D constrainForce;
//	Vector3D center;
//	float radious;
};
#endif