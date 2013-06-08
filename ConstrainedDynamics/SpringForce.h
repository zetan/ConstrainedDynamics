#ifndef SPRING_FORCE_H
#define SPRING_FORCE_H
#include "Force.h"


class SpringForce : public Force{
public:
	SpringForce();
	SpringForce(Vector3D pt, double restLength, double k);
	~SpringForce(){}
	void ApplyForce(Particle* particle);
	bool isActive(){return active;}
	void setActive(bool active){this->active = active;}

	void setRestLength(double restLength){this->restLength = restLength;}
	double getRestLength(){return restLength;}
	void setPt(Vector3D pt){this->pt = pt;}
	Vector3D& getPt(){return pt;}
private:
	double restLength;
	Vector3D pt;
	double k;
	bool active;
};
#endif