/********************************************************************************
** Form generated from reading UI file 'ceftest.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CEFTEST_H
#define UI_CEFTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ceftestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ceftestClass)
    {
        if (ceftestClass->objectName().isEmpty())
            ceftestClass->setObjectName(QStringLiteral("ceftestClass"));
        ceftestClass->resize(600, 400);
        menuBar = new QMenuBar(ceftestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ceftestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ceftestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ceftestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ceftestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ceftestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ceftestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ceftestClass->setStatusBar(statusBar);

        retranslateUi(ceftestClass);

        QMetaObject::connectSlotsByName(ceftestClass);
    } // setupUi

    void retranslateUi(QMainWindow *ceftestClass)
    {
        ceftestClass->setWindowTitle(QApplication::translate("ceftestClass", "ceftest", 0));
    } // retranslateUi

};

namespace Ui {
    class ceftestClass: public Ui_ceftestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CEFTEST_H
