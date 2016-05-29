import QtQuick.Layouts 1.1
import QtQuick 2.0

import "gearratio.js" as Logic

Rectangle {
    anchors.fill: parent
    color: "black"
    border.color: "#0020bb"
    border.width: 1
    radius: 10

    GridLayout {
        columns: 1
        rows: 4

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
                text: "Speed"
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
                text: spd.smoothedSpeed.toFixed(2) + " km/h\n(" + spd.speed.toFixed(2) + " km/h)"   // invokes GPSSpeedData::speed() to get this value
                color: "white"
                scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
            }
        }
        Rectangle {
            Layout.minimumHeight: 40
            Layout.fillWidth: true
            color: "black"
            border.color: "#0020bb"
            border.width: 1
            radius: 10
            Text {
                anchors.centerIn: parent
                text: "Optimal gears"
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
                text: "70rpm: 39x22\n" + "80rpm: 39x24\n" + "90rpm: 39x26\n" + "100rpm: 39x28\n"
                color: "white"
                scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
            }
        }
    }

}
