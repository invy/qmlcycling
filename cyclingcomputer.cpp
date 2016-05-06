#include "cyclingcomputer.h"

CyclingComputer::CyclingComputer(QGeoPositionInfoSource *posSource, QObject *parent)
    : QObject(parent),
    m_location(new DeviceLocation(posSource, this)),
    m_speedData(new GPSSpeedData(this)),
    m_slopeData(new SlopeData(this))
{
    QObject::connect(m_location,  &DeviceLocation::locationUpdated,
                     this, &CyclingComputer::locationUpdated);
}

void CyclingComputer::locationUpdated(const DeviceLocation &location) {
    m_speedData->locationUpdated(location);
    m_slopeData->locationUpdated(location);

}
