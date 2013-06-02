#ifndef ODESOLVER_H
#define ODESOLVER_H
#include <vector>
#include "global.h"
#include "Particle.h"
using namespace std;

class ODESolver{
public:
	ODESolver(){}
	~ODESolver(){}
	void Solve(vector<Particle> & particles);
};
#endif