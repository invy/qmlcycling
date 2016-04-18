import QtQuick 2.0

Text {
    width: 100; height: 100
    text: spd.speed    // invokes GPSSpeedData::speed() to get this value

    Component.onCompleted: {
        spd.author = "n.a."  // invokes Message::setSpeed()
    }
}
