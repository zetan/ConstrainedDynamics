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

	~ParticleSystem(){}
	virtual void Init(){}
	void Update();
	virtual void Draw(){}
	void StartPlay(){status = STATUS::PLAY;}
	void StopPlay(){status = STATUS::NONE; Init();}
	vector<Particle>& getParticles(){return particles;}
	virtual void ApplyForces(){}
protected:
	STATUS status;
	void ClearForces();
	
	void Solve();
	vector<Particle> particles;
	float time;
	ODESolver odeSolver;
	
};

#endif