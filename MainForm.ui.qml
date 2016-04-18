import QtQuick 2.6
import QtQuick.Controls 1.5

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    SpeedItem {
        anchors.centerIn: parent
//        text: "Hello World on the Android"
        anchors.fill: parent
    }

}
