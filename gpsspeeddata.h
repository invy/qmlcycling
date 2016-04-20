#ifndef GPSSPEEDDATA_H
#define GPSSPEEDDATA_H

#include <QObject>

#include "devicelocation.h"

class GPSSpeedData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(QString avgSpeed READ avgSpeed WRITE setAvgSpeed NOTIFY avgSpeedChanged)
public:
    explicit GPSSpeedData(QObject *parent = 0);

    void setSpeed(const QString &s) {
        this->m_speed = s;
        emit speedChanged();
    }
    void setAvgSpeed(const QString &s) {
        this->m_avgSpeed = s;
        emit avgSpeedChanged();
    }

    QString speed() const {
        return m_speed;
    }

    QString avgSpeed() const {
        return m_avgSpeed;
    }


public:
    qreal getSpeedData() {
        return m_speedData;
    }

signals:
    void speedChanged();
    void avgSpeedChanged();

public slots:
    void locationUpdated(const DeviceLocation &location);

private:
    QString m_speed;
    QString m_avgSpeed;
    qreal m_speedData;
    qreal m_avgSpeedData;
    unsigned long m_pointsCount;
};

#endif // GPSSPEEDDATA_H
