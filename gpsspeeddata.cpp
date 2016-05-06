#include <QDebug>

#include "mathutils.h"
#include "gpsspeeddata.h"

GPSSpeedData::GPSSpeedData(QObject *parent)
    : QObject(parent), m_alpha(0.5f), m_prevSpeedData(0.0f), m_smoothedSpeedData(0.0f), m_speedData(0.0f), m_avgSpeedData(0.0f), m_pointsCount(1)
{

}

void GPSSpeedData::locationUpdated(const DeviceLocation &location) {
    if(location.m_positionLog.size() < 2)
        return;
    auto currentPos = location.m_positionLog.at(location.m_positionLog.length()-1);
    auto prevPos = location.m_positionLog.at(location.m_positionLog.length()-2);
    if(!currentPos.isValid() && !prevPos.isValid())
        return;

    qreal delta_s = currentPos.coordinate().distanceTo(prevPos.coordinate());
    qreal delta_t = (currentPos.timestamp().toMSecsSinceEpoch() - prevPos.timestamp().toMSecsSinceEpoch())/1000.0f;
    if(delta_t > 0)
        m_speedData = delta_s/delta_t * 3600.0 / 1000.0;
    m_smoothedSpeedData = MathUtils::exponentialFilter(m_speedData, m_prevSpeedData, m_alpha);
    m_prevSpeedData = m_smoothedSpeedData;
    m_avgSpeedData = m_avgSpeedData + (m_speedData - m_avgSpeedData) / ++m_pointsCount;
    this->setSpeed(QString::asprintf("%.02f", m_speedData));
    this->setAvgSpeed(QString::asprintf("%.02f", m_avgSpeedData));
    this->setSmoothedSpeed(QString::asprintf("%.02f", m_smoothedSpeedData));
}
