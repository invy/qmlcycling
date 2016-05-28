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
            value: riderData.weight
            from: 40
            to: 120
        }
        Label { text: "Bike Weight (kg)" }
        SpinBox {
            id: bikeWeight
            value: riderData.bikeWeight
            from: 2
            to: 30
        }
        Label { text: "Tire width (mm)" }
        SpinBox {
            id: tireWidth
            value: riderData.tireWidth
            from: 18
            to: 35
        }
        Button {
            text: "Update"
            onClicked: {
                settings.riderWeight = riderData.weight = riderWeight.value
                settings.bikeWeight = riderData.bikeWeight = bikeWeight.value
                settings.tireWidth = riderData.tireWidth = tireWidth.value
            }
        }
    }
    Component.onCompleted: {
        riderWeight.value = riderData.weight = settings.riderWeight
        bikeWeight.value = riderData.bikeWeight = settings.bikeWeight
        tireWidth.value = riderData.tireWidth = settings.tireWidth
    }

    Component.onDestruction: {
        settings.riderWeight = riderData.weight
        settings.bikeWeight = riderData.bikeWeight
        settings.tireWidth = riderData.tireWidth
    }
}
