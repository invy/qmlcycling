#ifndef GPSSPEEDDATA_H
#define GPSSPEEDDATA_H

#include <QObject>

#include "devicelocation.h"

class GPSSpeedData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal speed         READ speed         NOTIFY speedChanged)
    Q_PROPERTY(qreal smoothedSpeed READ smoothedSpeed NOTIFY speedChanged)
    Q_PROPERTY(qreal avgSpeed      READ avgSpeed      NOTIFY speedChanged)
    Q_PROPERTY(qreal deltaT        READ deltaT        NOTIFY speedChanged)
    Q_PROPERTY(qreal deltaS        READ deltaS        NOTIFY speedChanged)
public:
    explicit GPSSpeedData(QObject *parent = 0);

    qreal deltaT() const;
    qreal deltaS() const;

    qreal speed() const;
    qreal smoothedSpeed() const;

    qreal avgSpeed() const;

public:
    qreal getSpeedData() const;

signals:
    void speedChanged();

public slots:
    void locationUpdated(const DeviceLocation &location);

private:
    qreal m_alpha;
    qreal m_prevSpeedData;
    qreal m_smoothedSpeedData;
    qreal m_speedData;
    qreal m_avgSpeedData;
    qreal m_deltat;
    qreal m_deltas;
    unsigned long m_pointsCount;
};

#endif // GPSSPEEDDATA_H
