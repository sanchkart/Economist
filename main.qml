import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1
import QtSensors 5.3

ApplicationWindow {
    visible: true
    width: 1335
    height: 500
    color: "#333"

    Item{
        x: 5
        y: 9
        anchors.fill: parent

        Calendar{
            objectName: "Calendar"
            x: 4
            y: 5
            anchors.fill: parent
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
    }
    /*Item {
        x: 5
        y: 255
        width: 325
        height: 240*/


    title: qsTr("MoneyInTheBank")

}








