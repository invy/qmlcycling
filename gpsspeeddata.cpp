#include <QDebug>

#include "gpsspeeddata.h"

GPSSpeedData::GPSSpeedData(QObject *parent)
    : QObject(parent)
{

}

void GPSSpeedData::locationUpdated(const DeviceLocation &location) {
    if(location.m_positionLog.size() < 2)
        return;
    auto currentPos = location.m_positionLog.back();
    auto prevPos = location.m_positionLog.at(location.m_positionLog.length()-1);
    if(!currentPos.isValid() && !prevPos.isValid())
        return;

    qreal delta_s = currentPos.coordinate().distanceTo(prevPos.coordinate());
    qint64 delta_t = currentPos.timestamp().toMSecsSinceEpoch() - prevPos.timestamp().toMSecsSinceEpoch();
    qreal speed = delta_s/delta_t;
    qDebug() << "speed: " << m_speed;
    this->setSpeed(QString::asprintf("%.02f", speed));
}
