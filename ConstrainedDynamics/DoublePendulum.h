#ifndef DOUBLE_PENDULUM_H
#define DOUBLE_PENDULUM_H
#include "global.h"
#include "Particle.h"
#include "ParticleSystem.h"
#include "Gravity.h"
#include "DoublePendulumConstrainForce.h"
using namespace std;

class DoublePendulum : public ParticleSystem{
public:
	DoublePendulum();
	~DoublePendulum(){}
	void Draw();
protected:
	void ApplyForces();
private:
	void DrawParabola();
	void DrawLine();

	Gravity gravity;
	DoublePendulumConstrainForce constrainForce;
};
#endif