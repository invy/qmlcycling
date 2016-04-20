import QtQuick 2.0

Rectangle {
    anchors.fill: parent
    color: "black"
    border.color: "#0020bb"
    border.width: 3
    radius: 10
    Text {
        anchors.centerIn: parent
        text: spd.speed + " km/h"   // invokes GPSSpeedData::speed() to get this value
        color: "white"
        scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
        Component.onCompleted: {
            spd.author = "n.a."  // invokes Message::setSpeed()
        }
    }
}
