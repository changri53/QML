import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 360
    height: 360
    objectName: "MainWindow"
    MouseArea {
        objectName: "MouseArea"
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
    Rectangle{
        objectName: "rect"
        color: "red"
        x: 0
        y: 0
        width: 20
        height: 30
    }

    Text {
        objectName: "Text"
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
