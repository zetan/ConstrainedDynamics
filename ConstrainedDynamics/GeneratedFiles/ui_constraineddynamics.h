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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ConstrainedDynamicsClass)
    {
        if (ConstrainedDynamicsClass->objectName().isEmpty())
            ConstrainedDynamicsClass->setObjectName(QStringLiteral("ConstrainedDynamicsClass"));
        ConstrainedDynamicsClass->resize(1170, 774);
        centralWidget = new QWidget(ConstrainedDynamicsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(932, 90, 211, 531));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        ConstrainedDynamicsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ConstrainedDynamicsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1170, 31));
        ConstrainedDynamicsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ConstrainedDynamicsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ConstrainedDynamicsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ConstrainedDynamicsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ConstrainedDynamicsClass->setStatusBar(statusBar);

        retranslateUi(ConstrainedDynamicsClass);

        QMetaObject::connectSlotsByName(ConstrainedDynamicsClass);
    } // setupUi

    void retranslateUi(QMainWindow *ConstrainedDynamicsClass)
    {
        ConstrainedDynamicsClass->setWindowTitle(QApplication::translate("ConstrainedDynamicsClass", "ConstrainedDynamics", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConstrainedDynamicsClass", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConstrainedDynamicsClass", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class ConstrainedDynamicsClass: public Ui_ConstrainedDynamicsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRAINEDDYNAMICS_H
