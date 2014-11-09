#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>

class MyCalendar : public QObject
{
    Q_OBJECT
public:
    MyCalendar();

public slots:
    void ShowShedulerWindow() const;
};

#endif // CALENDAR_H
