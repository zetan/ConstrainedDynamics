#ifndef DOUBLE_PENDULUM_H
#define DOUBLE_PENDULUM_H
#include "global.h"
#include "Particle.h"
#include "ParticleSystem.h"
#include "Gravity.h"
#include "DoublePendulumConstrainForce.h"
#include "SpringForce.h"
using namespace std;

class DoublePendulum : public ParticleSystem{
public:
	DoublePendulum();
	~DoublePendulum(){}
	void Draw();
	void setMouseSpring(Vector3D start, Vector3D end);
	void Init();
protected:
	void ApplyForces();
	
private:
	void DrawParabola();
	void DrawLine();
	void DrawSpring();

	Gravity gravity;
	DoublePendulumConstrainForce constrainForce;
	SpringForce spring1;
	SpringForce spring2;
};
#endif