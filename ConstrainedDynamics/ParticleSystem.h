#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H
#include <vector>
#include "global.h"
#include "Particle.h"
#include "ODESolver.h"


using namespace std;

class ParticleSystem{
public:
	ParticleSystem(){status = STATUS::NONE;}
//	ParticleSystem(vector<Particle> particles);
	~ParticleSystem(){}
	void Update();
	virtual void Draw(){}
	void StartPlay(){status = STATUS::PLAY;}
	void StopPlay(){status = STATUS::NONE;}
protected:
	STATUS status;
	void ClearForces();
	virtual void ApplyForces(){}
	void Solve();
	vector<Particle> particles;
	ODESolver odeSolver;
	float time;
};

#endif