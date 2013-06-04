#ifndef DOUBLE_PENDULUM_CONSTRAIN_FORCE_H
#define DOUBLE_PENDULUM_CONSTRAIN_FORCE_H

#include "global.h"
#include "Force.h"
#include "Particle.h"
#include "MATRIX.h"
#include <vector>


class DoublePendulumConstrainForce : public Force{
public:
	DoublePendulumConstrainForce();
	~DoublePendulumConstrainForce(){}
	void ApplyForce(vector<Particle>& particles);
	void setAlpha(double alpha){this->alpha = alpha;}
	void setRadius(double radius){this->radius = radius;}
private:
	 MATRIX C;
	 MATRIX C1;
	 MATRIX Q;
	 MATRIX Q1;

	 MATRIX W;
	 MATRIX J;
	 MATRIX J1;

	 MATRIX lamda;

	 void ClearMatrix(){}
	 void ComputeQ(vector<Particle>& particles){}
	 void ComputeQ1(vector<Particle>& particles){}
	 void ComputeW(vector<Particle>& particles){}
	 void ComputeC(){}
	 void ComputeJ(){}
	 void ComputeJ1(){}

	 double alpha;
	 double radius;

	 inline double getX1(){return Q(0,0);}
	 inline double getY1(){return Q(1,0);}
	 inline double getX2(){return Q(2,0);}
	 inline double getY2(){return Q(3,0);}

	 inline double getU1(){return Q1(0,0);}
	 inline double getV1(){return Q1(1,0);}
	 inline double getU2(){return Q1(2,0);}
	 inline double getV2(){return Q1(3,0);}

};


#endif