#include "Particle.h"

void Particle::Draw(){
	glTranslatef( pos.x,  pos.y, pos.z );

	GLDraw::DrawCircle(0.1);

	glTranslatef(-pos.x,  -pos.y, -pos.z);
}