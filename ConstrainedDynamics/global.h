#ifndef GLOBAL_H
#define GLOBAL_H
#include <QGLWidget>

enum STATUS{NONE, PLAY};

enum SCENCE{BEAD_ON_WIRE, DOUBLE_PENDULUM};

class Vector3D{
public:
	GLfloat x, y, z;
	Vector3D(){}
	Vector3D(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	~Vector3D(){}

	static Vector3D Add(Vector3D A, Vector3D B){return Vector3D(A.x + B.x, A.y + B.y, A.z + B.z);}
	static Vector3D Scale(Vector3D A, GLfloat s){return Vector3D(A.x * s, A.y * s, A.z * s);}
	static float DotProduct(Vector3D A, Vector3D B){return (A.x*B.x + A.y*B.y + A.z*B.z);}
	GLfloat Length(){return sqrt(x*x + y*y + z*z);}
	void Set(GLfloat x, GLfloat y, GLfloat z){this->x = x; this->y = y; this->z = z;}
private:

};

class GLDraw{
public:
	static void DrawCircle(float radius){
		
			glBegin( GL_LINE_LOOP );
			for (int i=0; i< 360; i++)
			{
				float degInRad = i * 3.1415/ 180;
				glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius, 0);
			}
			glEnd();
		
	}
};

#endif