import QtQuick.Layouts 1.1
import QtQuick 2.0


Rectangle {
    anchors.fill: parent
    color: "black"
    border.color: "#0020bb"
    border.width: 1
    radius: 10

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
                text: "Slope"
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
                text: slope.smoothedSlope.toFixed(2) + " %\n(" + slope.slope.toFixed(2) + " %)"   // invokes SlopeData::slope() to get this value
                color: "white"
                scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
                Component.onCompleted: {
                    slope.alpha = 0.08
                    slope.alphaSlope = 0.7
                }
            }
        }
    }

}
