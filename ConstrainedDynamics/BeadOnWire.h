#ifndef BEAD_ON_WIRE_H
#define BEAD_ON_WIRE_H
#include "global.h"
#include "Particle.h"
#include "ParticleSystem.h"
#include "Gravity.h"
#include "CircleConstrainForce.h"
using namespace std;

class BeadOnWire : public ParticleSystem{
public:
	BeadOnWire();
	~BeadOnWire(){}
	void Draw();
	void Init();
protected:
	void ApplyForces();
private:
	Gravity gravity;
	CircleConstrainForce constrainForce;
};

#endif