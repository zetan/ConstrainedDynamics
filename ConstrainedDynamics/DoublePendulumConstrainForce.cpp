#include "DoublePendulumConstrainForce.h"

DoublePendulumConstrainForce::DoublePendulumConstrainForce():C(2,1),C1(2, 1), Q(4, 1), Q1(4, 1), F(4, 1), W(4, 4), 
	J(2, 4), J1(2, 4), lamda(2, 1){
	alpha = 1;
	radius = 1;

	ks = 1;
	kd = 1;
}

void DoublePendulumConstrainForce::ApplyForce(vector<Particle>& particles){
	ClearMatrix();
	ComputeQ(particles);
	ComputeQ1(particles);
	ComputeF(particles);
	ComputeW(particles);
	ComputeC();
	ComputeJ();	
	ComputeC1();
	ComputeJ1();

	MATRIX left = J * W * J.Trans();
	qDebug()<<"---------------update--------------------";
	PrintMatrix(J, 4, "J");
	PrintMatrix(J1, 4, "J1");
//	PrintMatrix(W, 4, "W");
	PrintMatrix(J1.Scale(-1), 4, "J1.Scale(-1)");
//	qDebug()<<"Matrix J"<<endl<<J<<endl;
	MATRIX right =  J1.Scale(-1) * Q1  - J * W * F - C.Scale(ks) - C1.Scale(kd);

	
	lamda = left.Inv() * right; //

	

	MATRIX constrainForce = J.Trans() * lamda;
	
	
	Vector3D constrainForceA, constrainForceB;
	constrainForceA.Set(constrainForce(1, 1), constrainForce(2, 1), 0);
	constrainForceB.Set(constrainForce(3, 1), constrainForce(4, 1), 0);

	particles[0].setForce(Vector3D::Add(particles[0].getForce(), constrainForceA));
	particles[1].setForce(Vector3D::Add(particles[1].getForce(), constrainForceB));

}

void DoublePendulumConstrainForce::ClearMatrix(){
	C.setAll(0);
	C1.setAll(0);
	Q.setAll(0);
	Q1.setAll(0);
	F.setAll(0);
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

void DoublePendulumConstrainForce::ComputeF(vector<Particle>& particles){
	Particle A = particles[0];
	F.setBody(0, 0, A.getForce().x);
	F.setBody(1, 0, A.getForce().y);
	Particle B = particles[1];
	F.setBody(2, 0, B.getForce().x);
	F.setBody(3, 0, B.getForce().y);
}

void DoublePendulumConstrainForce::ComputeW(vector<Particle>& particles){
	Particle A = particles[0];
	W.setBody(0, 0, 1 / A.getMass());
	W.setBody(1, 1, 1 / A.getMass());
	Particle B = particles[1];
	W.setBody(2, 2, 1 / B.getMass());
	W.setBody(3, 3, 1 / B.getMass());
}

void DoublePendulumConstrainForce::ComputeC(){
	C.setBody(0,0, alpha * getX1() * getX1() - getY1());
	C.setBody(1,0, (getX1() - getX2()) * (getX1() - getX2()) + (getY1() - getY2()) * (getY1() - getY2()) - radius * radius);
}

void DoublePendulumConstrainForce::ComputeC1(){
	C1 = J * Q1;
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

void DoublePendulumConstrainForce::PrintMatrix(MATRIX & m, int cols, char* name){
	qDebug()<<"Matrix "<<name;
	for(int i = 0; i < m.Row(); i++){
		switch(cols){
		case 1:
			qDebug()<<m(i+1, 1);
			break;
		case 2:
			qDebug()<<m(i+1, 1)<<"\t"<<m(i+1, 2);
			break;
		case 3:
			qDebug()<<m(i+1, 1)<<"\t"<<m(i+1, 2)<<"\t"<<m(i+1, 3);
			break;
		case 4:
			qDebug()<<m(i+1, 1)<<"\t"<<m(i+1, 2)<<"\t"<<m(i+1, 3)<<"\t"<<m(i+1, 4);
			break;
		default: break;
		}
		
	}
}