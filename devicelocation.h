#ifndef DEVICELOCATION_H
#define DEVICELOCATION_H

#include <QObject>
#include <QGeoPositionInfo>
#include <QQueue>

class DeviceLocation : public QObject
{
    Q_OBJECT
public:
    explicit DeviceLocation(QObject *parent = 0);

signals:
    void locationUpdated(const DeviceLocation &location);
public slots:
    void positionUpdated(const QGeoPositionInfo &info);

public:
    QQueue<QGeoPositionInfo> m_positionLog;
};

#endif // DEVICELOCATION_H
