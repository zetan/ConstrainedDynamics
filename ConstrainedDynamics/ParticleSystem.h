#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H
#include <vector>
#include "global.h"
#include "Particle.h"
#include "ODESolver.h"


using namespace std;

class ParticleSystem{
public:
	ParticleSystem(){}
	ParticleSystem(vector<Particle> particles);
	~ParticleSystem(){}
	void Update();
protected:
	void ClearForces();
	virtual void ApplyForces(){}
	void Solve();
	vector<Particle> particles;
	ODESolver odeSolver;
	float time;
};

#endif