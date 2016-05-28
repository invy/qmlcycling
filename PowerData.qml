import QtQuick 2.0


Rectangle {
    anchors.fill: parent
    color: "black"
    border.color: "#0020bb"
    border.width: 3
    radius: 10
    property real cyclistArea: 0.4
    property real rho: 1.2041
    property real dragCoefficient: 1

    Text {
        anchors.centerIn: parent
        text:
            (((spd.deltaS *
            slope.smoothedSlope *
            9.81 * (riderData.weight + riderData.bikeWeight)) /
            (100 * spd.deltaT)) +
            0.5 * rho * Math.pow((spd.smoothedSpeed*1000/3600), 3) * cyclistArea * dragCoefficient).toFixed(2)
//        text: slope.smoothedSlope + " %\n(" + slope.slope + ")"   // invokes SlopeData::slope() to get this value
        color: "white"
        scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
        Component.onCompleted: {
        }
    }
}
