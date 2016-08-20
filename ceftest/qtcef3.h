#ifndef QTCEF3_H
#define QTCEF3_H

#include <QtWidgets/QMainWindow>
#include <QJsonObject>
#include "include/wrapper/cef_message_router.h"
#include "cefclient/cefview.h"
#include <QLabel>
#include <QPushButton>
typedef CefMessageRouterBrowserSide::Callback Callback;

class qtcef3 : public QMainWindow
{
	Q_OBJECT

public:
	qtcef3(QWidget *parent = 0);
	~qtcef3();
public:
	void JsTocppMessageParse(std::string message, CefRefPtr<Callback> &callback);
	void JsTocppMessageFuncPro(QJsonObject jsonObjMsg,CefRefPtr<Callback> &callback);
	void CreateBrowser();

public:
	void closeEvent(QCloseEvent *e);
	void resizeEvent(QResizeEvent *e);
	void showEvent(QShowEvent *e);
public slots:
	void handleClick();
private:
	CefViewcc *m_pCefView;
	QPushButton *label;

};
class Application{
public:
	Application(){isInitial = false;}
	qtcef3* getGlobal(){
		if (isInitial){return globalPtr;}
		else{return NULL;}}

	void setGlobal(qtcef3* ptr){globalPtr = ptr;isInitial = true;}
private:
	bool isInitial;
	qtcef3 *globalPtr;
};

qtcef3 * getApplication();
#endif // QTCEF3_H
