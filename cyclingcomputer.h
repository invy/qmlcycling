#ifndef CYCLINGCOMPUTER_H
#define CYCLINGCOMPUTER_H

#include <QObject>
#include <QGeoPositionInfoSource>

#include "devicelocation.h"
#include "gpsspeeddata.h"
#include "slopedata.h"

class CyclingComputer : public QObject
{
    Q_OBJECT
public:
    explicit CyclingComputer(QGeoPositionInfoSource *posSource = nullptr, QObject *parent = 0);

signals:

public slots:
    void locationUpdated(const DeviceLocation &location);

public:
    DeviceLocation *m_location;
    GPSSpeedData *m_speedData;
    SlopeData *m_slopeData;

};

#endif // CYCLINGCOMPUTER_H
