#include "DoublePendulum.h"

DoublePendulum::DoublePendulum(){
	Particle A;
	A.setMass(1);
	A.setPos(Vector3D(0, 0, 0));
	A.setVelocity(Vector3D(0, 0, 0));
	A.setForce(Vector3D(0, 0, 0));
	float radius = 1;
	Particle B;
	B.setMass(1);
	B.setPos(Vector3D(radius, 0, 0));
	B.setVelocity(Vector3D(0, 0, 0));
	B.setForce(Vector3D(0, 0, 0));

	particles.push_back(A);
	particles.push_back(B);

	//init constrain force parameters
	constrainForce.setAlpha(1);
	constrainForce.setRadius(1);
} 

void DoublePendulum::ApplyForces(){
	for(int i = 0; i < particles.size(); i++){
		gravity.ApplyForce(&particles[i]);
	}
	constrainForce.ApplyForce(particles);
}

void DoublePendulum::Draw(){
	for(int i = 0; i < particles.size(); i++)
		particles[i].Draw();
}