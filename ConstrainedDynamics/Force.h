#ifndef FORCE_H
#define FORCE_H
#include "global.h"
#include "Particle.h"
#include <vector>
using namespace std;
class Force{
public :
	Force(){}
	~Force(){}
	virtual void ApplyForce(Particle* particle){}
	virtual void ApplyForce(vector<Particle>& particles){}
};
#endif