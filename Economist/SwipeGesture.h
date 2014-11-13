#ifndef SWIPEGESTURE_H
#define SWIPEGESTURE_H

#include <QObject>
#include <QPointF>

class SwipeGesture : public QObject
{
    Q_OBJECT
public:
    SwipeGesture();
    // Метод визуальной настройки компонентов (размер и положение)
    void SwipeComponentSetting(QObject *qObject);
    // Метод соединения сигналов со слотами
    void ConnectSlotsWithSignals();

private slots:
    // Слот выполняет сдвиг до определенной позиции
    void MoveAction(double dCoord);
    // Слот устанавливает текущую координату оси Х элементов в fliczbleComponent
    void SetCurrentCoordX();

private:
    // Указатель на QML компонент swipeComponent
    QObject *m_qSwipeComponent;

    // Длина отступа от края рамки до компонента (def val = 5)
    double m_dTab;
    // Количество компонентов внутри swipe-компонента (def val = 3)
    int m_nInputComponentsCount;
    // Высота основного окна
    double m_dParentWindowHeight;
    // Ширина основного окна
    double m_dParentWindowWidth;

    // Текущиая координата оси Х
    int m_dCurrentX;
    // Направление движения
    QString m_sDirection;

};

#endif // SWIPEGESTURE_H
