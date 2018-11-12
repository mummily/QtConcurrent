#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include "QRunnable"
#include "QFutureWatcher"

class QtGuiApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtGuiApplication1(QWidget *parent = Q_NULLPTR);

    void dosth();
    public slots:
    void showMsg(QString s);

private:
    Ui::QtGuiApplication1Class ui;
    QFutureWatcher<void> m_watch;
};

class DoSth : public QRunnable
{
public:
    DoSth(QObject* object)
        :m_object(object)
    {};

    virtual void run();
protected:
private:
    QObject* m_object;
};