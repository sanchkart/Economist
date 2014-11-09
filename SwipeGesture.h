#ifndef SWIPEGESTURE_H
#define SWIPEGESTURE_H

#include <QObject>
#include <QPointF>

class SwipeGesture : public QObject
{
    Q_OBJECT
public:
    SwipeGesture();

private slots:
    void GetCurrentPoint(QPointF currentPoint);
    void DoSwipe(QPointF coords);

private:
    QPointF m_qCurrentPoint;

};

#endif // SWIPEGESTURE_H
