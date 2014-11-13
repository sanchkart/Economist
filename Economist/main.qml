import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import QtSensors 5.3

ApplicationWindow {
    id: appwindow
    objectName: "mainWindow"
    title: qsTr("MoneyInTheBank")
    color: "#333"

    Flickable {
        id: swipeComponent
        objectName: "swipeComponent"
        anchors.fill: parent
        flickableDirection: Flickable.HorizontalFlick

        rebound: Transition {
            NumberAnimation {
                properties: "x"
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }

        Behavior on contentX {
            PropertyAnimation {
                duration: 200
            }
        }

        signal movementEnd(double coord)
        onMovementEnded: {
              movementEnd(swipeComponent.contentX)
         }

        Calendar{
            id: calendar
            objectName: "calendarComponent"
            weekNumbersVisible: true

            style: CalendarStyle {
                gridVisible: false
                dayDelegate: Rectangle {
                    gradient: Gradient {
                        GradientStop {
                            position: 0.00
                            color: styleData.selected ? "#111" : (styleData.visibleMonth && styleData.valid ? "#444" : "#666");
                        }
                        GradientStop {
                            position: 1.00
                            color: styleData.selected ? "#444" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
                        }
                        GradientStop {
                            position: 1.00
                            color: styleData.selected ? "#777" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
                        }
                    }

                    Label {
                        text: styleData.date.getDate()
                        anchors.centerIn: parent
                        color: styleData.valid ? "white" : "grey"
                    }

                   Rectangle {
                        width: parent.width
                        height: 1
                        color: "#555"
                        anchors.bottom: parent.bottom
                    }

                    Rectangle {
                        width: 1
                        height: parent.height
                        color: "#555"
                        anchors.right: parent.right
                    }
                }
            }
        }

        Button {
            id: button1
            objectName: "buttonComponent1"
            text: qsTr("Button1")
        }

        Button {
            id: button2
            objectName: "buttonComponent2"
            text: qsTr("Button2")
        }
    }
}
