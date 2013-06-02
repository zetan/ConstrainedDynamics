#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(vector<Particle> particles){
	this->particles = particles;
}

void ParticleSystem::ClearForces(){
	for(int i = 0; i < particles.size(); i++)
		particles[i].ClearForce();
}

void ParticleSystem::Solve(){
	odeSolver.Solve(particles);
}

void ParticleSystem::Update(){
	ClearForces();
	ApplyForces();
	Solve();
}