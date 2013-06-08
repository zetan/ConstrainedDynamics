#include "ODESolver.h"

void ODESolver::Solve(vector<Particle> & particles){
	vector<Vector3D> velocityVec;
	vector<Vector3D> accVec;
	// get state
	for(int i = 0; i < particles.size(); i++){
		velocityVec.push_back(particles[i].getVelocity());
		accVec.push_back(Vector3D::Scale(particles[i].getForce(), 1 / particles[i].getMass()));
	}

	// solve + set state
	float time = 0.01f;
	for(int i = 0; i < particles.size(); i++){
		Vector3D velocity = Vector3D::Add(velocityVec[i], Vector3D::Scale(accVec[i], time));
		Vector3D pos = Vector3D::Add(particles[i].getPos(), Vector3D::Scale(velocityVec[i], time));
		particles[i].setVelocity(velocity);
		particles[i].setPos(pos);
	}
}