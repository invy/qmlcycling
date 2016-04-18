
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDebug>
#include "devicelocation.h"

DeviceLocation::DeviceLocation(QObject *parent) : QObject(parent)
{
    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    qDebug() << "available sources: " << QGeoPositionInfoSource::availableSources();
    if (source) {
        qDebug() << "supported methods: " << source->supportedPositioningMethods();
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
        source->requestUpdate(1000);
    }
}

void DeviceLocation::positionUpdated(const QGeoPositionInfo &info)
{
    qDebug() << "Position updated:" << info;
    this->m_positionLog.push_back(info);
    emit locationUpdated(*this);
}
