import QtQuick.Layouts 1.1
import QtQuick 2.0


Rectangle {
    anchors.fill: parent
    color: settings.bgColor
    border.color: settings.borderColor
    border.width: 1
    radius: settings.borderRadius

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
                text: "Slope (%)"
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
                text: slope.smoothedSlope.toFixed(2)
                color: settings.fgColor
                scale: (paintedWidth < parent.width) ? (parent.width / paintedWidth) : (paintedWidth/parent.width)
                Component.onCompleted: {
                    slope.alpha = 0.08
                    slope.alphaSlope = 0.7
                }
            }
        }
    }

}
