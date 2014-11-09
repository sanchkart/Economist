#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
<<<<<<< HEAD
#include <QQuickItem>
#include <QDate>
#include <QMetaObject>
=======
#include <QDate>


>>>>>>> origin/master

#include "Calendar.h"
#include "SwipeGesture.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlComponent qComponent(&engine,
        QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *qObject = qComponent.create();

   /* QObject *qobjCalendar = qObject->findChild<QObject*>("calendar");
    if(qobjCalendar)
    {
<<<<<<< HEAD
       MyCalendar *objCalendar = new MyCalendar();
       QObject::connect(qobjCalendar, SIGNAL(clicked(QDateTime)), objCalendar, SLOT(ShowShedulerWindow()));
    }*/

    QObject *qobjSwipeGesture = qObject->findChild<QObject*>("swipeArea");
    if(qobjSwipeGesture){
       SwipeGesture *objSwipe = new SwipeGesture();

       QObject::connect(qobjSwipeGesture, SIGNAL(pushed(QPointF)),
           objSwipe, SLOT(GetCurrentPoint(QPointF)));

       QObject::connect(qobjSwipeGesture, SIGNAL(swipe(QPointF)),
           objSwipe, SLOT(DoSwipe(QPointF)));
=======
       Calendar *objCalendar = new Calendar();
       QObject::connect(qobjCalendar, SIGNAL(clicked(QDateTime)), objCalendar, SLOT(ShowShedulerWindow()));
>>>>>>> origin/master
    }

    return app.exec();
}
