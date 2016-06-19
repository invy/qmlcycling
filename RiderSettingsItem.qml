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
        Column {
            Column {
                Label { text: "Chain Rings" }
            }
        }
        Column {
            Row {
                SpinBox {
                    id: largeChainRing
                    value: riderData.largeChainRing
                    from: 45
                    to: 58
                }
                SpinBox {
                    id: smallChainRing
                    value: riderData.smallChainRing
                    from: 25
                    to: 45
                }
            }
        }
        Column {
            Label { text: "Cassette (Cogs)" }
        }
        Column {
            Row {
                SpinBox {
                    id: smallestCog
                    value: riderData.smallestCog
                    from: 9
                    to: 15
                }
                SpinBox {
                    id: biggestCog
                    value: riderData.biggestCog
                    from: 18
                    to: 35
                }
            }
        }
        Row {
            Button {
                text: "Update"
                onClicked: {
                    settings.riderWeight = riderData.weight = riderWeight.value
                    settings.bikeWeight = riderData.bikeWeight = bikeWeight.value
                    settings.tireWidth = riderData.tireWidth = tireWidth.value
                    settings.largeChainRing = riderData.largeChainRing = largeChainRing.value
                    settings.smallChainRing = riderData.smallChainRing = smallChainRing.value
                    settings.smallestCog = riderData.smallestCog = smallestCog.value
                    settings.biggestCog = riderData.biggestCog = biggestCog.value
                }
            }
        }
        Rectangle { }
        Column {
            Row {
                RadioButton {
                    checked: settings.dark
                    text: "Dark Theme"
                    onClicked: {
                        settings.fontSize = 17
                        settings.dark = true
                        settings.bgColor = "black"
                        settings.fgColor = "white"
                        settings = "#ff471a"

                    }
                }
                RadioButton {
                    checked: !settings.dark
                    text: "Light Theme"
                    onClicked: {
                        settings.fontSize = 17
                        settings.dark = false
                        settings.bgColor = "white"
                        settings.fgColor = "black"
                        settings = "#ff471a"

                    }
                }
            }
        }
    }
    Component.onCompleted: {
        riderWeight.value = riderData.weight = settings.riderWeight
        bikeWeight.value = riderData.bikeWeight = settings.bikeWeight
        tireWidth.value = riderData.tireWidth = settings.tireWidth
        largeChainRing.value = riderData.largeChainRing = settings.largeChainRing
        smallChainRing.value = riderData.smallChainRing = settings.smallChainRing
        smallestCog.value = riderData.smallestCog = settings.smallestCog
        biggestCog.value = riderData.biggestCog = settings.biggestCog

    }

    Component.onDestruction: {
        settings.riderWeight = riderData.weight
        settings.bikeWeight = riderData.bikeWeight
        settings.tireWidth = riderData.tireWidth
        settings.largeChainRing = riderData.largeChainRing
        settings.smallChainRing = riderData.smallChainRing
        settings.smallestCog = riderData.smallestCog
        settings.biggestCog = riderData.biggestCog
    }
}
