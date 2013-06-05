#include "CircleConstrainForce.h"

CircleConstrainForce::CircleConstrainForce(){
	ks = 1;
	kd = 1;
}

void CircleConstrainForce::ApplyForce(Particle* particle){
	float fx = Vector3D::DotProduct(particle->getForce(), particle->getPos());
	float vv = Vector3D::DotProduct(particle->getVelocity(), particle->getVelocity());
	float xx = Vector3D::DotProduct(particle->getPos(), particle->getPos());

	double kdForce = kd * (xx - 1)/ 2;
	double ksForce = ks * Vector3D::DotProduct(particle->getPos(), particle->getVelocity());

	float lamda = -1 * (fx + particle->getMass() * vv + kdForce + ksForce) / xx;
	Vector3D constrainForce = Vector3D::Scale(particle->getPos(), lamda);
	particle->setForce(Vector3D::Add(particle->getForce(), constrainForce));
}