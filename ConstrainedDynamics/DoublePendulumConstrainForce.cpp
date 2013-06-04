#include "DoublePendulumConstrainForce.h"

DoublePendulumConstrainForce::DoublePendulumConstrainForce():C(2,1),C1(2, 1), Q(4, 1), Q1(4, 1), W(4, 4), 
	J(2, 4), J1(2, 4), lamda(2, 1){
	alpha = 1;
	radius = 1;
}

void DoublePendulumConstrainForce::ApplyForce(vector<Particle>& particles){
	ClearMatrix();
	ComputeQ(particles);
	ComputeQ1(particles);
	ComputeW(particles);
	ComputeJ();
	ComputeC();
	ComputeJ1();

	Matrix2d left = J * W * J.transpose();
	Vector2d right = -1 * J1 * Q1 - J * W * Q;
	lamda = left.inverse() * right; //

	Vector4d constrainForce = J.transpose() * lamda;
	
	Vector3D constrainForceA, constrainForceB;
	constrainForceA.Set(constrainForce(0, 0), constrainForce(1, 0), 0);
	constrainForceB.Set(constrainForce(2, 0), constrainForce(3, 0), 0);

	particles[0].setForce(Vector3D::Add(particles[0].getForce(), constrainForceA));
	particles[1].setForce(Vector3D::Add(particles[1].getForce(), constrainForceB));

}

void DoublePendulumConstrainForce::ClearMatrix(){
	C.setAll(0);
	C1.setAll(0);
	Q.setAll(0);
	Q1.setAll(0);
	W.setAll(0);
	J.setAll(0);
	J1.setAll(0);
	lamda.setAll(0);
}

void DoublePendulumConstrainForce::ComputeQ(vector<Particle>& particles){
	Particle A = particles[0];
	Q.setBody(0, 0, A.getPos().x);
	Q.setBody(1, 0, A.getPos().y);
	Particle B = particles[1];
	Q.setBody(2, 0, B.getPos().x);
	Q.setBody(3, 0, B.getPos().y);
}

void DoublePendulumConstrainForce::ComputeQ1(vector<Particle>& particles){
	Particle A = particles[0];
	Q1.setBody(0, 0, A.getVelocity().x);
	Q1.setBody(1, 0, A.getVelocity().y);
	Particle B = particles[1];
	Q1.setBody(2, 0, B.getVelocity().x);
	Q1.setBody(3, 0, B.getVelocity().y);
}

void DoublePendulumConstrainForce::ComputeW(vector<Particle>& particles){
	Particle A = particles[0];
	W.setBody(0, 0, 1 / A.getMass());
	W.setBody(1, 1, 1 / A.getMass());
	Particle B = particles[1];
	W.setBody(2, 2, 1 / B.getMass());
	W.setBody(3, 2, 1 / B.getMass());
}

void DoublePendulumConstrainForce::ComputeC(){
	C.setBody(0,0, alpha * getX1() * getX1() - getY1());
	C.setBody(1,0, (getX1() - getX2()) * (getX1() - getX2()) + (getY1() - getY2()) * (getY1() - getY2()) - radius * radius);
}

void DoublePendulumConstrainForce::ComputeJ(){
	//row 0
	J.setBody(0, 0, 2 * alpha * getX1());
	J.setBody(0, 1, -1);
	// J(0, 2) = 0;
	// K(0, 3) = 0;
	//row 1
	J.setBody(1, 0, 2 * (getX1() - getX2()));
	J.setBody(1, 1, 2 * (getY1() - getY2()));
	J.setBody(1, 2, 2 * (getX2() - getX1()));
	J.setBody(1, 3, 2 * (getY2() - getY1()));
}

void DoublePendulumConstrainForce::ComputeJ1(){
	//row 0
	J1.setBody(0, 0, 2 * alpha * getU1());
	//row 1
	J1.setBody(1, 0, 2 * (getU1() - getU2()));
	J1.setBody(1, 1, 2 * (getV1() - getV2()));
	J1.setBody(1, 2, 2 * (getU2() - getU1()));
	J1.setBody(1, 3, 2 * (getV2() - getV1()));
}