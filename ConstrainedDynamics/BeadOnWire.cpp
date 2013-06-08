#include "BeadOnWire.h"



BeadOnWire::BeadOnWire(){
	Particle bead;
	bead.setPos(Vector3D(0.6, 0.8, 0));
	bead.setVelocity(Vector3D(0, 0, 0));
	bead.setForce(Vector3D(0, 0, 0));
	bead.setMass(1);
	particles.push_back(bead);
}

void BeadOnWire::Init(){
	particles[0].setPos(Vector3D(0.6, 0.8, 0));
	particles[0].setVelocity(Vector3D(0, 0, 0));
	particles[0].setForce(Vector3D(0, 0, 0));
	particles[0].setMass(1);
}

void BeadOnWire::ApplyForces(){
	ClearForces();
	//qDebug()<<Vector3D::DotProduct(particles[0].getPos(), particles[0].getPos()) - 1;
	qDebug()<<particles[0].getPos().y;
	for(int i = 0; i < particles.size(); i++){
		gravity.ApplyForce(&particles[i]);
		constrainForce.ApplyForce(&particles[i]);
	}
}

void BeadOnWire::Draw(){
	glColor3f(1.0, 1.0, 1.0);
	GLDraw::DrawCircle(1.0f);
	for(int i = 0; i < particles.size(); i++){
		particles[i].Draw();
	}
	glColor3f(1.0, 0.0, 0.0);
	GLDraw::DrawArrow(particles[0].getPos(), Vector3D::Scale(constrainForce.getConstrainForce(), 0.05));
}
