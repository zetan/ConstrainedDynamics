/********************************************************************************
** Form generated from reading UI file 'constraineddynamics.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRAINEDDYNAMICS_H
#define UI_CONSTRAINEDDYNAMICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConstrainedDynamicsClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *pendulumPlayBtn;
    QPushButton *pendulumStopBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ConstrainedDynamicsClass)
    {
        if (ConstrainedDynamicsClass->objectName().isEmpty())
            ConstrainedDynamicsClass->setObjectName(QStringLiteral("ConstrainedDynamicsClass"));
        ConstrainedDynamicsClass->resize(1161, 774);
        centralWidget = new QWidget(ConstrainedDynamicsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(892, 90, 251, 531));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pendulumPlayBtn = new QPushButton(tab_2);
        pendulumPlayBtn->setObjectName(QStringLiteral("pendulumPlayBtn"));
        pendulumPlayBtn->setGeometry(QRect(10, 370, 112, 34));
        pendulumStopBtn = new QPushButton(tab_2);
        pendulumStopBtn->setObjectName(QStringLiteral("pendulumStopBtn"));
        pendulumStopBtn->setGeometry(QRect(151, 370, 91, 34));
        tabWidget->addTab(tab_2, QString());
        ConstrainedDynamicsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ConstrainedDynamicsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1161, 31));
        ConstrainedDynamicsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ConstrainedDynamicsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ConstrainedDynamicsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ConstrainedDynamicsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ConstrainedDynamicsClass->setStatusBar(statusBar);

        retranslateUi(ConstrainedDynamicsClass);
        QObject::connect(pendulumPlayBtn, SIGNAL(clicked()), ConstrainedDynamicsClass, SLOT(PendulumStartPlay()));
        QObject::connect(pendulumStopBtn, SIGNAL(clicked()), ConstrainedDynamicsClass, SLOT(PendulumStopPlay()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ConstrainedDynamicsClass);
    } // setupUi

    void retranslateUi(QMainWindow *ConstrainedDynamicsClass)
    {
        ConstrainedDynamicsClass->setWindowTitle(QApplication::translate("ConstrainedDynamicsClass", "ConstrainedDynamics", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConstrainedDynamicsClass", "Tab 1", 0));
        pendulumPlayBtn->setText(QApplication::translate("ConstrainedDynamicsClass", "Play", 0));
        pendulumStopBtn->setText(QApplication::translate("ConstrainedDynamicsClass", "Stop", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConstrainedDynamicsClass", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class ConstrainedDynamicsClass: public Ui_ConstrainedDynamicsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRAINEDDYNAMICS_H
