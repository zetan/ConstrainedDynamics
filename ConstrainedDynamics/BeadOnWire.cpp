#include "BeadOnWire.h"



BeadOnWire::BeadOnWire(){
	Particle bead;
	bead.setPos(Vector3D(0.03, 1, 0));
	bead.setVelocity(Vector3D(0, 0, 0));
	bead.setForce(Vector3D(0, 0, 0));
	bead.setMass(1);
	particles.push_back(bead);
}

void BeadOnWire::ApplyForces(){
	for(int i = 0; i < particles.size(); i++){
		gravity.ApplyForce(&particles[i]);
		constrainForce.ApplyForce(&particles[i]);
	}
}

void BeadOnWire::Draw(){
	GLDraw::DrawCircle(1.0f);
	for(int i = 0; i < particles.size(); i++){
		particles[i].Draw();
	}
}
