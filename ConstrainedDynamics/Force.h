#ifndef FORCE_H
#define FORCE_H
#include "global.h"
class Force{
public :
	Force(){}
	~Force(){}
	virtual void ApplyForce(Particle* particle){}
};
#endif