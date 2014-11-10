import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import QtSensors 5.3

ApplicationWindow {
    title: qsTr("MoneyInTheBank")
    visible: true
    width: 335
    height: 500
    color: "#333"

    Flickable {
        id: flicable
        objectName: "flickable"
        anchors.fill: parent
        contentWidth: 665; contentHeight: 490
        flickableDirection: Flickable.HorizontalFlick
        focus: true

        Behavior on contentX { PropertyAnimation { duration: 500} }

        onMovementEnded: {
              flicable.contentX = contentWidth / 2
         }

        rebound: Transition {
            NumberAnimation {
                properties: "x"
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }

        Calendar{
            id: calendar
            objectName: "calendar"
            x: 5
            y: 5
            width: 325
            height: 490
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
            id: button
            x: 336
            y: 5
            width: 325
            height: 490
            text: qsTr("Button")
        }
    }


}
