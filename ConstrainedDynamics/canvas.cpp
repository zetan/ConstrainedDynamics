#include "canvas.h"  
#include <QTimer>  
#include <QKeyEvent>  
#include <QMessageBox>  
#include <QApplication>  
#include <QDebug>  

GLCanvas::GLCanvas(QWidget *parent) :  
QGLWidget(parent), fullscreen(false)  
{  
	setWindowTitle(tr("nehe----lesson01"));  
	timer = new QTimer(this);  
	connect(timer, SIGNAL(timeout()), this, SLOT(updateGL())); //²»Í£Ë¢ÐÂ´°¿Ú  
	timer->start(20);  
	scene = SCENCE::BEAD_ON_WIRE;
}  

void GLCanvas::initializeGL()  
{  
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glClearDepth( 1.0 );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	
}  

void GLCanvas::updateGL(){

	if(scene == SCENCE::BEAD_ON_WIRE)beadOnWire.Update();
	if(scene == SCENCE::DOUBLE_PENDULUM) doublePendulum.Update();
	//doublePendulum.Update();
	update();

}


void GLCanvas::paintGL()  
{  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer  
	glLoadIdentity();       // Reset The Current Modelview Matrix  

	glTranslatef( 0.0,  0.0, -5.0 );

	if(scene == SCENCE::BEAD_ON_WIRE)beadOnWire.Draw();
	if(scene == SCENCE::DOUBLE_PENDULUM) doublePendulum.Draw();
	//doublePendulum.Draw();
}  


void GLCanvas::resizeGL(int width, int height)  
{  
	if (height==0) {    // Prevent A Divide By Zero By  
		height=1;    // Making Height Equal One  
	}  
	glViewport(0, 0, width, height);    // Reset The Current Viewport  
	glMatrixMode(GL_PROJECTION);       // Select The Projection Matrix  
	glLoadIdentity();                  // Reset The Projection Matrix  

	// Calculate The Aspect Ratio Of The Window
	/*gluPerspective(140.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);  
	gluLookAt(0.0,10.0,50.0,0.0,0.0,-100.0,0.0,1.0,0.0);
	glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix  
	glLoadIdentity();                // Reset The Modelview Matrix 
	*/
	gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}  


void GLCanvas::keyPressEvent(QKeyEvent *e)  
{  
	
}  

void GLCanvas::mousePressEvent(QMouseEvent *e){
	mouseX = ((double)(e->pos().x() - 400)) / 150;
	mouseY = ((double)(e->pos().y() - 300 )) / -150;
	qDebug()<<"press x "<<e->pos().x()<<" y "<<e->pos().y();
	qDebug()<<"release x "<<mouseX<<" y "<<mouseY;
}

void GLCanvas::mouseReleaseEvent(QMouseEvent *e){
	double releaseX = ((double)(e->pos().x() - 400)) / 150;
	double releaseY =((double)(e->pos().y() - 300 )) / -150;
	qDebug()<<"release x "<<e->pos().x()<<" y "<<e->pos().y();
	qDebug()<<"release x "<<releaseX<<" y "<<releaseY;
	//beadOnWire
	if(scene == SCENCE::DOUBLE_PENDULUM){
		doublePendulum.setMouseSpring(Vector3D(mouseX, mouseY, 0), Vector3D(releaseX, releaseY, 0));
	}
}

void GLCanvas::closeEvent(QCloseEvent *e)  
{  
	QMessageBox::StandardButton reply;  
	reply = QMessageBox::question(this, "NeHe",  
		"Do you want to exit?",  
		QMessageBox::Yes | QMessageBox::No,  
		QMessageBox::No);  
	if (reply == QMessageBox::Yes) {  
		e->accept();  
	} else {  
		e->ignore();  
	}  

}