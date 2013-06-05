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
	DrawParabola();
	for(int i = 0; i < particles.size(); i++)
		particles[i].Draw();
	DrawLine();
}

void DoublePendulum::DrawParabola(){
	double alpha = constrainForce.getAlpha();
	glBegin( GL_LINE_STRIP_ADJACENCY );
	for (double x = -1.3; x <= 1.31; x+= 0.05)
	{
	//	float degInRad = i * 3.1415/ 180;
		glVertex3f(x,alpha*x*x, 0);
	}
	glEnd();
}

void DoublePendulum::DrawLine(){
	glBegin( GL_LINE_LOOP );
	glVertex3f(particles[0].getPos().x, particles[0].getPos().y, 0);
	glVertex3f(particles[1].getPos().x, particles[1].getPos().y, 0);
	glEnd();
}