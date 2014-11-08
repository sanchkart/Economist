#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "Calendar.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlComponent qComponent(&engine,
        QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *qObject = qComponent.create();

    QObject *qobjCalendar = qObject->findChild<QObject*>("Calendar");

    if(qobjCalendar)
    {
       Calendar *objCalendar = new Calendar();
       QObject::connect(qobjCalendar, SIGNAL(clicked()), objCalendar, SLOT(ShowShedulerWindow()));

    }

    return app.exec();
}
