import QtQuick.Layouts 1.1
import QtQuick 2.0

Rectangle {
    anchors.fill: parent
    color: settings.bgColor
    border.color: settings.borderColor
    border.width: 1
    radius: 10

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
            radius: 10
            Text {
                anchors.centerIn: parent
                text: "Avg. Speed (km/h)"
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
                text: spd.avgSpeed.toFixed(2)
                color: settings.fgColor
                scale: (paintedWidth < parent.width && parent.width > 0 && paintedWidth > 0) ? (parent.width / paintedWidth) : (paintedWidth / parent.width)
            }
        }
    }

}
