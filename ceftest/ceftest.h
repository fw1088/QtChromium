#ifndef CEFTEST_H
#define CEFTEST_H

#include <QtWidgets/QMainWindow>
#include "ui_ceftest.h"
#include "cefclient/cefview.h"
class ceftest : public QMainWindow
{
	Q_OBJECT

public:
	ceftest(QWidget *parent = 0);
	~ceftest();
private:
	 CefViewcc* webview_;
};

#endif // CEFTEST_H
