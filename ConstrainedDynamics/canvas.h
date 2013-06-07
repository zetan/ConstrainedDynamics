#ifndef CANVAS_H  
#define CANVAS_H  

#include <QGLWidget>  
#include <GL/GL.h>
#include <GL/GLU.h>
#include <gl/glut.h>
#include "global.h"
#include "BeadOnWire.h"
#include "DoublePendulum.h"
#include <QDebug>
class QTimer;  
class QKeyEvent;  

class GLCanvas : public QGLWidget  
{  
	Q_OBJECT  
public:  
	explicit GLCanvas(QWidget *parent = 0);  

	BeadOnWire& getBeadOnWireScene(){return beadOnWire;}
	DoublePendulum& getDoublePendulumScene(){return doublePendulum;}
	void SetScene(SCENCE scene){this->scene = scene;}
protected:  
	void initializeGL();  
	void resizeGL(int w, int h);  
	void paintGL();  

	void keyPressEvent(QKeyEvent *); 
	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void closeEvent(QCloseEvent *);  


	public Q_SLOTS:
		void updateGL();

private:  
	QTimer *timer;  
	bool fullscreen;  //窗口是否全屏显示  
	SCENCE scene;
	BeadOnWire beadOnWire;
	DoublePendulum doublePendulum;
	double mouseX;
	double mouseY;
};  

#endif // MYGLWIDGET_H  