import QtQuick.Layouts 1.1
import QtQuick 2.0


Rectangle {
    anchors.fill: parent
    color: "black"
    border.color: "#0020bb"
    border.width: 1
    radius: 10
    property real cyclistArea: 0.4
    property real rho: 1.2041
    property real dragCoefficient: 1

    GridLayout {
        columns: 1
        rows: 2

        anchors.fill: parent
        Rectangle {
            Layout.minimumHeight: 40
            Layout.fillWidth: true
            color: "black"
            border.color: "#0020bb"
            border.width: 1
            radius: 10
            Text {
                anchors.centerIn: parent
                text: "Est. Power"
                color: "white"
            }
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "black"
            border.color: "#0020bb"
            border.width: 1
            radius: 10
            Text {
                anchors.centerIn: parent
                text:
                    // power to counteract gravity
                    (((spd.deltaS *
                    slope.smoothedSlope *
                    9.81 * (riderData.weight + riderData.bikeWeight)) /
                    (100 * spd.deltaT)) +
                    // power to counteract aerodynamic drag
                    (0.5 * rho * Math.pow((spd.smoothedSpeed*1000/3600), 3) * cyclistArea * dragCoefficient)
                    ).toFixed(2) + " Watts"
                color: "white"
                scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
                Component.onCompleted: {
                }
            }
        }
    }
}
