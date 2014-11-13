#include "SwipeGesture.h"
#include <QQmlApplicationEngine>
#include <QQmlComponent>

// Конструктор по умолчанию
SwipeGesture::SwipeGesture() :
    m_nInputComponentsCount(3)
    , m_dParentWindowHeight(600)
    , m_dParentWindowWidth(400)
    , m_sDirection("")
    , m_dCurrentX(0)
    , m_dTab(5)
{
}

// Метод визуальной настройки компонентов (размер и положение)
void SwipeGesture::SwipeComponentSetting(QObject *qObject)
{
    // Настраиваем главное окно
    if(qObject){
        // Ширина и высота окна
        qObject->setProperty("width", m_dParentWindowWidth);
        qObject->setProperty("height", m_dParentWindowHeight);
    }
    else
        return;

    // Дочерние компоненты
    QObject *qChildComponent;

    // Ищем дочерние окна по имени
    qChildComponent = qObject->findChild<QObject*>("swipeComponent");
    if(qChildComponent){
        // Ширина и высота окна
        qChildComponent->setProperty("width", m_dParentWindowWidth);
        qChildComponent->setProperty("height", m_dParentWindowHeight);
        // Ширина и высота содержимого
        qChildComponent->setProperty("contentWidth", m_dParentWindowWidth * m_nInputComponentsCount);
        qChildComponent->setProperty("contentHeight", m_dParentWindowHeight);
        // Начальное положение содержимого
        qChildComponent->setProperty("contentX", m_dParentWindowWidth);

        // Запоминаем указатель на компонент
        m_qSwipeComponent = qChildComponent;
    }

    // Ширина и высота вложенных компонент
    double dChildComponentWidth = m_dParentWindowWidth - 2 * m_dTab;
    double dChildComponentHeight = m_dParentWindowHeight - 2 * m_dTab;
    // Количество пробелов между компонентами
    int nTabCount = 1;

    qChildComponent = qObject->findChild<QObject*>("calendarComponent");
    if(qChildComponent){
        // Ширина и высота окна
        qChildComponent->setProperty("width", dChildComponentWidth);
        qChildComponent->setProperty("height", dChildComponentHeight);
        // Положение
        qChildComponent->setProperty("x", nTabCount * m_dTab);
        qChildComponent->setProperty("y", m_dTab);
        nTabCount += 2;
    }

    qChildComponent = qObject->findChild<QObject*>("buttonComponent1");
    if(qChildComponent){
        // Ширина и высота окна
        qChildComponent->setProperty("width", dChildComponentWidth);
        qChildComponent->setProperty("height", dChildComponentHeight);
        // Положение
        qChildComponent->setProperty("x", dChildComponentWidth + nTabCount * m_dTab);
        qChildComponent->setProperty("y", m_dTab);
        nTabCount += 2;
    }

    qChildComponent = qObject->findChild<QObject*>("buttonComponent2");
    if(qChildComponent){
        // Ширина и высота окна
        qChildComponent->setProperty("width", dChildComponentWidth);
        qChildComponent->setProperty("height", dChildComponentHeight);
        // Положение
        qChildComponent->setProperty("x", dChildComponentWidth * 2 + nTabCount * m_dTab);
        qChildComponent->setProperty("y", m_dTab);
        nTabCount += 2;
    }

    qObject->setProperty("visible", true);
}

// Метод соединения сигналов со слотами
void SwipeGesture::ConnectSlotsWithSignals()
{
    // TODO: ДОБАВИТЬ ДЕЙСТВИЙ ЕСЛИ НЕ НАШЛИ КОМПОНЕНТ
    if(m_qSwipeComponent){
        QObject::connect(m_qSwipeComponent, SIGNAL(movementStarted()),
            this, SLOT(SetCurrentCoordX()));

        QObject::connect(m_qSwipeComponent, SIGNAL(movementEnd(double)),
            this, SLOT(MoveAction(double)));
    }
}

//================================== SLOTS ==================================

// Слот устанавливает текущую координату оси Х элементов в fliczbleComponent
void SwipeGesture::SetCurrentCoordX()
{
    m_dCurrentX = m_qSwipeComponent->property("contentX").toDouble();
}

// Слот выполняет сдвиг до определенной позиции
void SwipeGesture::MoveAction(double dCoord)
{
    // Считываем текущую координату по оси Х
    double dCurrentContentX = m_qSwipeComponent->property("contentX").toDouble();

    // Крайняя левая позиция
    if(!m_dCurrentX){
        if(dCoord >= m_dParentWindowWidth / 2)
            m_qSwipeComponent->setProperty("contentX", m_dParentWindowWidth);
        else
           m_qSwipeComponent->setProperty("contentX", 0);
    }
    // Центральная позиция
    if(m_dCurrentX == m_dParentWindowWidth){
        if(dCoord <= m_dParentWindowWidth / 2)
            m_qSwipeComponent->setProperty("contentX", 0);
        else if(dCoord >= m_dParentWindowWidth * 1.5)
            m_qSwipeComponent->setProperty("contentX", m_dParentWindowWidth * 2);
        else
           m_qSwipeComponent->setProperty("contentX", m_dParentWindowWidth);
    }
    // Краяняя правая позиция
    if(m_dCurrentX == m_dParentWindowWidth * 2){
        if(dCoord <= m_dParentWindowWidth * 1.5)
            m_qSwipeComponent->setProperty("contentX", m_dParentWindowWidth);
        else
           m_qSwipeComponent->setProperty("contentX", m_dParentWindowWidth * 2);
    }
}

