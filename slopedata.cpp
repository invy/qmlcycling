
#include <QDebug>
#include <QGeoPositionInfo>
#include "mathutils.h"
#include "slopedata.h"

SlopeData::SlopeData(QObject *parent)
    : QObject(parent),
    m_slopeData(0.0f),
    m_smoothedSlopeData(0.0f),
    m_alpha(0.01),
    m_alphaSlope(0.1),
    m_previousAltitude(0.0f),
    m_previousSlopeData(0.0f)
{

}

double SlopeData::calculateSlope(double distance, double altitude, double defaultSlope) {
    double slope = defaultSlope;
    if(distance > 0) {
        auto tslope = altitude/distance * 100.0f;
        // consider slope of 30% gradiente as unrealistic and fallback to the default value
        if(fabs(tslope) < 30.0f)
            slope = tslope;
    }
    return slope;
}

void SlopeData::locationUpdated(const DeviceLocation &location) {
    if(location.m_positionLog.size() == 0)
        return;
    if(location.m_positionLog.size() == 1) {
        m_previousAltitude = location.m_positionLog.at(location.m_positionLog.length()-1).coordinate().altitude();
        return;
    }


    auto currentPos = location.m_positionLog.at(location.m_positionLog.length()-1);
    auto prevPos = location.m_positionLog.at(location.m_positionLog.length()-2);
    if(!currentPos.isValid() && !prevPos.isValid())
        return;

    qreal currentAltitude = MathUtils::exponentialFilter(currentPos.coordinate().altitude(), this->m_previousAltitude, this->m_alpha);
    qDebug() << "corrected altitude: " << currentAltitude;
    qreal delta_h = currentAltitude - m_previousAltitude;
    qreal delta_s = currentPos.coordinate().distanceTo(prevPos.coordinate());
    m_slopeData = calculateSlope(delta_s, delta_h, m_slopeData);
    m_previousAltitude = currentAltitude;
    m_smoothedSlopeData = MathUtils::exponentialFilter(m_slopeData, m_previousSlopeData, m_alphaSlope);
    m_previousSlopeData = m_smoothedSlopeData;
    emit slopeChanged();
}
