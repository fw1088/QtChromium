#pragma  once
#include "QtWidgets/QWidget"

class CefViewcc :public QWidget
{
public:
		CefViewcc(QWidget *parent);
		~CefViewcc();
public:
	void resizeEvent(QResizeEvent *event);
	void CreateBrowser(std::string url);
	void callJs();

};


