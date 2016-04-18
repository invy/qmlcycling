#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "devicelocation.h"
#include "gpsspeeddata.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    DeviceLocation *location = new DeviceLocation(&app);
    GPSSpeedData *speedData = new GPSSpeedData(&app);


    QObject::connect(location,  &DeviceLocation::locationUpdated,
                     speedData, &GPSSpeedData::locationUpdated);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("spd", speedData);
    QQmlComponent component(&engine, QUrl::fromLocalFile("SpeedItem.qml"));
    component.create();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
