#include "ceftest.h"
#include <QHBoxLayout>
ceftest::ceftest(QWidget *parent)
	: QMainWindow(parent)
{

	webview_ = new CefViewcc(this);
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(webview_);
	setFixedSize(800,600);
	setLayout(layout);
}

ceftest::~ceftest()
{

}
