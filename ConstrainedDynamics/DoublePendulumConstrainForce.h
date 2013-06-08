#ifndef DOUBLE_PENDULUM_CONSTRAIN_FORCE_H
#define DOUBLE_PENDULUM_CONSTRAIN_FORCE_H

#include "global.h"
#include "Force.h"
#include "Particle.h"
#include "MATRIX.h"
#include <vector>
#include <QDebug>

class DoublePendulumConstrainForce : public Force{
public:
	DoublePendulumConstrainForce();
	~DoublePendulumConstrainForce(){}
	void ApplyForce(vector<Particle>& particles);
	void setAlpha(double alpha){this->alpha = alpha;}
	void setRadius(double radius){this->radius = radius;}
	void setKd(double kd){this->kd = kd;}
	void setKs(double ks){this->ks = ks;}

	double getAlpha(){return alpha;}
	Vector3D& getConstrainForceA(){return constrainForceA;}
	Vector3D& getConstrainForceB(){return constrainForceB;}
private:
	 MATRIX C;
	 MATRIX C1;
	 MATRIX Q; //pos
	 MATRIX Q1;//velocity
	 MATRIX F; //force

	 MATRIX W;
	 MATRIX J;
	 MATRIX J1;

	 MATRIX lamda;

	 void ClearMatrix();
	 void ComputeQ(vector<Particle>& particles);
	 void ComputeQ1(vector<Particle>& particles);
	 void ComputeF(vector<Particle>& particles);
	 void ComputeW(vector<Particle>& particles);
	 void ComputeC();
	 void ComputeC1();
	 void ComputeJ();
	 void ComputeJ1();

	 double ks;
	 double kd;

	 double alpha;
	 double radius;

	 Vector3D constrainForceA;
	 Vector3D constrainForceB;

	 inline double getX1(){return Q(1,1);}
	 inline double getY1(){return Q(2,1);}
	 inline double getX2(){return Q(3,1);}
	 inline double getY2(){return Q(4,1);}

	 inline double getU1(){return Q1(1,1);}
	 inline double getV1(){return Q1(2,1);}
	 inline double getU2(){return Q1(3,1);}
	 inline double getV2(){return Q1(4,1);}
	 void PrintMatrix(MATRIX & m, int cols, char* name);
};


#endif