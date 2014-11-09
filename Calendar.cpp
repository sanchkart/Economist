#include "Calendar.h"

#include <QQmlApplicationEngine>
#include <QQmlComponent>

MyCalendar::MyCalendar()
{
}

void MyCalendar::ShowShedulerWindow() const
{
    QQmlApplicationEngine engine;
    QQmlComponent qComponent(&engine,
        QUrl(QStringLiteral("qrc:/Sheduler.qml")));

    QObject *qObject = qComponent.create();
}
