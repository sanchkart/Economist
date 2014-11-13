#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QDate>
#include <QMetaObject>

#include "Calendar.h"
#include "SwipeGesture.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlComponent qComponent(&engine,
        QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *qObject = qComponent.create();

    SwipeGesture *swipeGesture = new SwipeGesture();
    // Настраиваем размер и положение компонентов виджета
    swipeGesture->SwipeComponentSetting(qObject);
    // Соединяем сигналы виджета со слотами класса
    swipeGesture->ConnectSlotsWithSignals();

    return app.exec();
}
