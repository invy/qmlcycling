#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "gpxfilepositionsource.h"
#include "cyclingcomputer.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QGeoPositionInfoSource *source = nullptr;
    if(QCoreApplication::arguments().size() > 2 && QCoreApplication::arguments().at(1) == "--testSource") {
        source = new GpxFilePositionSource(QCoreApplication::arguments().at(2), &app);
    }

    CyclingComputer *cc = new CyclingComputer(source, &app);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("spd", cc->m_speedData);
    engine.rootContext()->setContextProperty("slope", cc->m_slopeData);
    engine.rootContext()->setContextProperty("riderData", cc->m_riderData);
    QQmlComponent spdComponent(&engine, QUrl::fromLocalFile("SpeedItem.qml"));
    QQmlComponent avgSpdComponent(&engine, QUrl::fromLocalFile("AvgSpeedItem.qml"));
    QQmlComponent slopeComponent(&engine, QUrl::fromLocalFile("SlopeItem.qml"));
    QQmlComponent riderSettingsComponent(&engine, QUrl::fromLocalFile("RiderSettingsItem.qml"));
    QQmlComponent powerData(&engine, QUrl::fromLocalFile("PowerData.qml"));
    spdComponent.create();
    avgSpdComponent.create();
    slopeComponent.create();
    riderSettingsComponent.create();
    powerData.create();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
