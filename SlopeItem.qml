import QtQuick 2.0


Rectangle {
    anchors.fill: parent
    color: "black"
    border.color: "#0020bb"
    border.width: 3
    radius: 10
    Text {
        anchors.centerIn: parent
        text: slope.smoothedSlope.toFixed(2) + " %\n(" + slope.slope.toFixed(2) + ")"   // invokes SlopeData::slope() to get this value
        color: "white"
        scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
        Component.onCompleted: {
            slope.smoothedSlope = 0.0  // invokes Message::setSpeed()
            slope.alpha = 0.08
            slope.alphaSlope = 0.7
        }
    }
}
