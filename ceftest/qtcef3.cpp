#include "qtcef3.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include "cefclient/cefview.h"
#include "cef_app.h"
#include "json.h"

Application application;
qtcef3::qtcef3(QWidget *parent)
	: QMainWindow(parent)
{

	label = new QPushButton(this);
	connect(label,SIGNAL(clicked(bool)),this,SLOT(handleClick()));
	label->setText("Misazw");
	label->move(0,0);
	m_pCefView = NULL;
	application.setGlobal(this);
}


qtcef3::~qtcef3()
{
	if (m_pCefView)
	{
		delete m_pCefView;
	}
}

void qtcef3::closeEvent(QCloseEvent *e)
{
	::PostQuitMessage(0);
}

void qtcef3::resizeEvent(QResizeEvent *e)
{
	QSize wndsize = size();
	label->move(0,0);
	label->setFixedSize(wndsize.width()*0.1,wndsize.height());
	m_pCefView->move(wndsize.width()*0.1,0);
	m_pCefView->setFixedSize(wndsize.width()*0.9,wndsize.height());
}

void qtcef3::showEvent(QShowEvent *e)
{
}

void qtcef3::CreateBrowser()
{
	if (m_pCefView == NULL)
	{
		m_pCefView = new CefViewcc(this);
	   m_pCefView->resize(width()-100, height());
		m_pCefView->CreateBrowser("");
		m_pCefView->move(100,0);
	}
}

void qtcef3::JsTocppMessageParse(std::string message, CefRefPtr<Callback> &callback)
{
	using namespace QtJson;
	bool ok;
	QString str = QString::fromStdString(message);
	JsonObject result = QtJson::parse(str, ok).toMap();
	if (result.contains("state"))
	{
		//entry.state = result["state"].toInt();
	}
	/*QJsonParseError error;
	QByteArray byteArray = QByteArray::fromStdString(message);
	QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray, &error);
	if (error.error == QJsonParseError::NoError)
	{
		QJsonObject  jsonObj = jsonDoc.object();
		QJsonArray jsonArray = jsonObj["function"].toArray();
		for (int i = 0; i < jsonArray.size(); i++)
		{
			QJsonObject tempObj = jsonArray[i].toObject();
			JsTocppMessageFuncPro(tempObj,callback);
		}
	}
	else
	{
		qDebug() << error.errorString();
	}*/

}


void qtcef3::JsTocppMessageFuncPro(QJsonObject jsonObjMsg,CefRefPtr<Callback> &callback)
{
	QString funcName;
	funcName = jsonObjMsg["name"].toString();
	if (funcName.contains("Minimize"))
	{
		this->showMinimized();
	}
	else if (funcName.contains("Maximize"))
	{
		this->showMaximized();
	}
	else if (funcName.contains("Closewindow"))
	{
		this->close();
	}
	else if (funcName.contains("Restore"))
	{
		this->showNormal();
	}
}

void qtcef3::handleClick()
{
	if (m_pCefView)
	{
		m_pCefView->callJs();
	}
}


qtcef3 * getApplication()
{
	return application.getGlobal();
}
