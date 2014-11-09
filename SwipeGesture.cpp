#include "SwipeGesture.h"
#include <QMessageBox>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

SwipeGesture::SwipeGesture() :
    m_qCurrentPoint(0, 0)
{}

void SwipeGesture::GetCurrentPoint(QPointF currentPoint)
{
    m_qCurrentPoint = currentPoint;
    QQmlApplicationEngine engine;
    QQmlComponent qComponent(&engine,
        QUrl(QStringLiteral("qrc:/Sheduler.qml")));

    QObject *qObject = qComponent.create();
}

void SwipeGesture::DoSwipe(QPointF coords)
{
    //if(m_qCurrentPoint.rx != coords.rx)

}
