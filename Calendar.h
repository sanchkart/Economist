#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>

class Calendar : public QObject
{
    Q_OBJECT
public:
    Calendar();

private slots:
    void ShowShedulerWindow() const;
};

#endif // CALENDAR_H
