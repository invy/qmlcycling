import QtQuick.Layouts 1.1
import QtQuick 2.0

import "powercalc.js" as Logic

Rectangle {
    anchors.fill: parent
    color: settings.bgColor
    border.color: settings.borderColor
    border.width: 1
    radius: settings.borderRadius

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
            color: settings.bgColor
            border.color: settings.borderColor
            border.width: 1
            radius: settings.borderRadius
            Text {
                anchors.centerIn: parent
                text: "Est. Power (Watts)"
                color: settings.fgColor
                font.pixelSize: settings.fontSize

            }
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: settings.bgColor
            border.color: settings.borderColor
            border.width: 1
            radius: settings.borderRadius
            Text {
                anchors.centerIn: parent
                text: Logic.estimatePower(spd.deltaT, spd.deltaS, spd.smoothedSpeed*1000/3600, slope.smoothedSlope, riderData.weight + riderData.bikeWeight, rho, cyclistArea, dragCoefficient).toFixed(2)
                color: settings.fgColor
                scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
            }
        }
    }
}
