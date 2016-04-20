#ifndef DEVICELOCATION_H
#define DEVICELOCATION_H

#include <QObject>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QQueue>

class DeviceLocation : public QObject
{
    Q_OBJECT
public:
    explicit DeviceLocation(QObject *parent = 0, QGeoPositionInfoSource *source = nullptr);

signals:
    void locationUpdated(const DeviceLocation &location);
public slots:
    void positionUpdated(const QGeoPositionInfo &info);

public:
    QQueue<QGeoPositionInfo> m_positionLog;
    QGeoPositionInfoSource *m_source;
};

#endif // DEVICELOCATION_H
