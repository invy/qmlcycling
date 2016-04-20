#ifndef GPXFILEPOSITIONSOURCE_H
#define GPXFILEPOSITIONSOURCE_H

#include <QGeoPositionInfoSource>
#include <QXmlStreamReader>
#include <QFile>
#include <QTimer>
#include <QQueue>

class GpxFilePositionSource : public QGeoPositionInfoSource
{
    Q_OBJECT
public:
    GpxFilePositionSource(const QString& fileName, QObject *parent = 0);

    QGeoPositionInfo lastKnownPosition(bool fromSatellitePositioningMethodsOnly = false) const;

    PositioningMethods supportedPositioningMethods() const;
    int minimumUpdateInterval() const;
    Error error() const;

public slots:
    virtual void startUpdates();
    virtual void stopUpdates();

    virtual void requestUpdate(int timeout = 5000);

private slots:
    void readNextPosition();

private:
    QFile *gpxFile;
    QTimer *timer;
    unsigned int lastPosition;
    QQueue<QGeoPositionInfo> m_posList;
private:
    QQueue<QGeoPositionInfo> readGpx();
};

#endif // GPXFILEPOSITIONSOURCE_H
