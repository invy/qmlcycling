#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "gpxfilepositionsource.h"
#include "devicelocation.h"
#include "gpsspeeddata.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QGeoPositionInfoSource *source = nullptr;
    if(QCoreApplication::arguments().size() > 2 && QCoreApplication::arguments().at(1) == "--testSource") {
        source = new GpxFilePositionSource(QCoreApplication::arguments().at(2), &app);
    }

    DeviceLocation *location = new DeviceLocation(&app, source);
    GPSSpeedData *speedData = new GPSSpeedData(&app);


    QObject::connect(location,  &DeviceLocation::locationUpdated,
                     speedData, &GPSSpeedData::locationUpdated);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("spd", speedData);
    QQmlComponent spdComponent(&engine, QUrl::fromLocalFile("SpeedItem.qml"));
    QQmlComponent avgSpdComponent(&engine, QUrl::fromLocalFile("AvgSpeedItem.qml"));
    spdComponent.create();
    avgSpdComponent.create();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
