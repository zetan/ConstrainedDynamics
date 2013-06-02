#include "CircleConstrainForce.h"

void CircleConstrainForce::ApplyForce(Particle* particle){
	float fx = Vector3D::DotProduct(particle->getForce(), particle->getPos());
	float vv = Vector3D::DotProduct(particle->getVelocity(), particle->getVelocity());
	float xx = Vector3D::DotProduct(particle->getPos(), particle->getPos());
	float lamda = -1 * (fx + particle->getMass() * vv) / xx;
	Vector3D constrainForce = Vector3D::Scale(particle->getPos(), lamda);
	particle->setForce(Vector3D::Add(particle->getForce(), constrainForce));
}