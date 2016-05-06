
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDebug>
#include "devicelocation.h"

DeviceLocation::DeviceLocation(QGeoPositionInfoSource *source, QObject *parent) : QObject(parent)
{
    if(!source)
        m_source = QGeoPositionInfoSource::createDefaultSource(this);
    else
        m_source = source;

    m_source->setPreferredPositioningMethods(QGeoPositionInfoSource::SatellitePositioningMethods);

    qDebug() << "available sources: " << QGeoPositionInfoSource::availableSources();
    if (m_source) {
        qDebug() << "supported methods: " << m_source->supportedPositioningMethods();
        connect(m_source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
        m_source->startUpdates(); //requestUpdate(1000);
    }
}

void DeviceLocation::positionUpdated(const QGeoPositionInfo &info)
{
    qDebug() << "Position updated:" << info;
    this->m_positionLog.push_back(info);
    emit locationUpdated(*this);
}
