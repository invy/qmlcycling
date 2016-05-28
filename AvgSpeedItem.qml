import QtQuick 2.0

Rectangle {
    anchors.fill: parent
    color: "black"
    border.color: "#0020bb"
    border.width: 3
    radius: 10
    Text {
        anchors.centerIn: parent
        text: spd.avgSpeed.toFixed(2) + " km/h"   // invokes GPSSpeedData::speed() to get this value
        color: "white"
        scale: (paintedWidth < parent.width && parent.width > 0 && paintedWidth > 0) ? (parent.width / paintedWidth) : (paintedWidth / parent.width)
    }
}
