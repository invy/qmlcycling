#ifndef GPSSPEEDDATA_H
#define GPSSPEEDDATA_H

#include <QObject>

#include "devicelocation.h"

class GPSSpeedData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString speed READ speed WRITE setSpeed NOTIFY speedChanged)
public:
    explicit GPSSpeedData(QObject *parent = 0);

    void setSpeed(const QString &s) {
        this->m_speed = s;
        emit speedChanged();
    }

    QString speed() const {
        return m_speed;
    }

signals:
    void speedChanged();

public slots:
    void locationUpdated(const DeviceLocation &location);

private:
    QString m_speed;
};

#endif // GPSSPEEDDATA_H
