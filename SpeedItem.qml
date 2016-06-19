import QtQuick.Layouts 1.1
import QtQuick 2.5
import QtQuick.Controls 1.4

import "gearratio.js" as Logic

Rectangle {
    id: speedItem
    anchors.fill: parent
    color: settings.bgColor
    border.color: settings.borderColor
    border.width: 1
    radius: 10

    GridLayout {
        columns: 1
        rows: 4

        anchors.fill: parent
        Rectangle {
            Layout.minimumHeight: 40
            Layout.fillWidth: true
            color: settings.bgColor
            border.color: settings.borderColor
            border.width: 1
            radius: 10
            Text {
                anchors.centerIn: parent
                text: "Speed (km/h)"
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
            radius: 10
            Text {
                anchors.centerIn: parent
                text: spd.smoothedSpeed.toFixed(2)   // invokes GPSSpeedData::speed() to get this value
                color: settings.fgColor
                scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
            }
        }
        Rectangle {
            Layout.minimumHeight: 40
            Layout.fillWidth: true
            color: settings.bgColor
            border.color: settings.borderColor
            border.width: 1
            radius: 10
            Text {
                anchors.centerIn: parent
                text: "Optimal Gears"
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
            radius: 10

            ListView {
                id: gearingList
                property var gearingArray: Logic.getRatios(spd.speed*1000/3600, 0.335, riderData.smallChainRing, riderData.largeChainRing, riderData.smallestCog, riderData.biggestCog)
                anchors.fill: parent
                model: gearingArray
                delegate: Text {
                    color: (gearingList.gearingArray[index].rpm >= 80) ? "green" : (gearingList.gearingArray[index].rpm >= 70) ? "orange" : "red"
                    text: gearingList.gearingArray[index].rpm + ":    " + gearingList.gearingArray[index].chainRing + "x" + gearingList.gearingArray[index].cog
                    font.pixelSize: settings.fontSize
                }
            }
        }
    }

}
