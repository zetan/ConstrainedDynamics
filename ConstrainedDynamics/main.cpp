#include "constraineddynamics.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ConstrainedDynamics w;
	w.show();
	return a.exec();
}
