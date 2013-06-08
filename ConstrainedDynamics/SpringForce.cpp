#include "SpringForce.h"

SpringForce::SpringForce(){
	this->pt = Vector3D(0,0,0);
	this->restLength = 0;
	this->k = 50;
	this->active = false;
}

SpringForce::SpringForce(Vector3D pt, double restLength, double k){
	this->pt = pt;
	this->restLength = restLength;
	this->k = k;
	this->active = true;
}

void SpringForce::ApplyForce(Particle* particle){
	if(active == false) return;
	double length = Vector3D::Minus(particle->getPos(), pt).Length();
	Vector3D force = Vector3D::Scale(Vector3D::Minus(particle->getPos(), pt), k * (length - restLength) / length * -1);
	particle->setForce(Vector3D::Add(particle->getForce(), force));
}