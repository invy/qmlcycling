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

    Rectangle {
        id: spdItem
        x: 0
        y: 0
        height:parent.height
        width: parent.width/2
        SpeedItem {
            anchors.fill: parent
        }
    }
    Rectangle {
        id: avgSpedItem
        x: parent.width/2
        y: 0
        height:parent.height
        width:parent.width/2
        AvgSpeedItem {
            anchors.fill: parent
        }
    }

}
