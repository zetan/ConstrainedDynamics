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

void ConstrainedDynamics::BeadStartPlay(){
	canvas->getBeadOnWireScene().StartPlay();
}

void ConstrainedDynamics::BeadStopPlay(){
	canvas->getBeadOnWireScene().StopPlay();
}

void ConstrainedDynamics::PendulumStartPlay(){
	canvas->getDoublePendulumScene().StartPlay();
}

void ConstrainedDynamics::PendulumStopPlay(){
	canvas->getDoublePendulumScene().StopPlay();
}

void ConstrainedDynamics::ChangeScene(int i){
	if(i == 0) canvas->SetScene(SCENCE::BEAD_ON_WIRE);
	if(i == 1) canvas->SetScene(SCENCE::DOUBLE_PENDULUM);
}