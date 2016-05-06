import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import Qt.labs.controls 1.0
import Qt.labs.settings 1.0

ApplicationWindow {
    id: app
    visible: true

    width: 400
    height: 800


    Settings {
        id: settings
        property int riderWeight: 60
        property int bikeWeight: 6
        property int tireWidth: 23
    }

    SwipeView {
        id: view

        currentIndex: 1
        anchors.fill: parent

        Item {
            id: firstPage
        }
        Item {
            id: secondPage
        }
    }
    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        opacity: 1.0
    }

    Rectangle {
        parent: firstPage
        anchors.fill: parent
        color: "white"
        RiderSettingsItem {

        }
    }

    /*
     * Main view with cyclng parameters
     */
    Rectangle {
        parent: secondPage
        id: mainView
        anchors.fill: parent
        color: "#c0c0c0"

        GridLayout {
            columns: 2
            rows: 2

            anchors.fill: parent
            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                id: spdItem

                SpeedItem {
                    anchors.fill: parent
                }
            }
            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                id: avgSpedItem

                AvgSpeedItem {
                    anchors.fill: parent
                }
            }
            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                id: slopeItem

                SlopeItem {
                    anchors.fill: parent
                }
            }
        }
    }


}
