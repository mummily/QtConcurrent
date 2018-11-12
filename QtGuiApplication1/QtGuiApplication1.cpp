#include "QtGuiApplication1.h"
#include <QThread>
#include <QtConcurrent>
#include <QMessageBox>

using namespace QtConcurrent;

void globalFun()
{
    QThread::sleep(5);
}

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

#pragma region run全局函数
//     auto f = QtConcurrent::run(globalFun);
//     f.waitForFinished();
//     showMsg();
#pragma endregion run全局函数
#pragma region funtureWatch
     auto f = QtConcurrent::run(globalFun);
     m_watch.setFuture(f);
     connect(&m_watch, SIGNAL(finished()), this, SLOT(showMsg()));
#pragma endregion funtureWatch
#pragma region run当前类函数
    // QFuture<void> f = QtConcurrent::run(this, &QtGuiApplication1::dosth);
#pragma endregion run当前类函数

#pragma region QRunnable
      //DoSth* ds = new DoSth(this);
      //QThreadPool::globalInstance()->start(ds);
#pragma endregion QRunnable
}

void QtGuiApplication1::dosth()
{
    QThread::sleep(5);
    QMessageBox::information(nullptr, "", "");
}

void QtGuiApplication1::showMsg(QString s)
{
    QMessageBox::information(nullptr, "", s);
}

void DoSth::run()
{
    QThread::sleep(5);
    QMetaObject::invokeMethod(m_object, "showMsg", Q_ARG(QString, "123"));
}
