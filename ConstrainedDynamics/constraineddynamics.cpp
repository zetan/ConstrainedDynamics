#include "constraineddynamics.h"

ConstrainedDynamics::ConstrainedDynamics(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	canvas = new GLCanvas(ui.centralWidget);
	canvas->setGeometry(10,10, 800, 600);
}

ConstrainedDynamics::~ConstrainedDynamics()
{

}
