import QtQuick 2.0
import QtQuick.Layouts 1.1
import Qt.labs.controls 1.0

Item {
    GridLayout {
        anchors.margins: 10
        anchors.fill: parent
        columns: 2
        rowSpacing: 5
        columnSpacing: 10

        Label { text: "Rider Weight (kg)" }
        SpinBox {
            id: riderWeight
            value: settings.riderWeight
            from: 40
            to: 120
        }
        Label { text: "Bike Weight (kg)" }
        SpinBox {
            id: bikeWeight
            value: settings.bikeWeight
            from: 2
            to: 30
        }
        Label { text: "Tire width (mm)" }
        SpinBox {
            id: tireWidth
            value: settings.tireWidth
            from: 18
            to: 35
        }
    }
    Component.onDestruction: {
        settings.riderWeight = riderWeight.value
        settings.bikeWeight = bikeWeight.value
        settings.tireWidth = tireWidth.value
    }
}
