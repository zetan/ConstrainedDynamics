#ifndef CONSTRAINEDDYNAMICS_H
#define CONSTRAINEDDYNAMICS_H

#include <QtWidgets/QMainWindow>
#include "ui_constraineddynamics.h"
#include "global.h"
#include "canvas.h"
class ConstrainedDynamics : public QMainWindow
{
	Q_OBJECT

public:
	ConstrainedDynamics(QWidget *parent = 0);
	~ConstrainedDynamics();

public slots:
		void BeadStartPlay();
		void BeadStopPlay();
		void PendulumStartPlay();
		void PendulumStopPlay();
private:
	Ui::ConstrainedDynamicsClass ui;
	GLCanvas* canvas;

};

#endif // CONSTRAINEDDYNAMICS_H
