
#include <QXmlStreamReader>
#include <QDateTime>
#include <QDebug>

#include "gpxfilepositionsource.h"


GpxFilePositionSource::GpxFilePositionSource(const QString& fileName, QObject *parent)
    : QGeoPositionInfoSource(parent),
      gpxFile(new QFile(this)),
      timer(new QTimer(this)),
      lastPosition(0)
{

    gpxFile->setFileName(fileName);
    if (!gpxFile->open(QIODevice::ReadOnly))
        qWarning() << "Error: cannot open source file" << gpxFile->fileName();

    m_posList = this->readGpx();

    connect(timer, SIGNAL(timeout()), this, SLOT(readNextPosition()));

}

void GpxFilePositionSource::startUpdates()
{
    int interval = updateInterval();
    if (interval < minimumUpdateInterval())
        interval = minimumUpdateInterval();

    timer->start(interval);
}

void GpxFilePositionSource::stopUpdates()
{
    timer->stop();
}

void GpxFilePositionSource::requestUpdate(int /*timeout*/)
{
    // For simplicity, ignore timeout - assume that if data is not available
    // now, no data will be added to the file later
    readNextPosition();
//    else
//        emit updateTimeout();
}

void GpxFilePositionSource::readNextPosition()
{
    if(lastPosition < m_posList.length()) {
        QGeoPositionInfo info = this->m_posList.at(lastPosition++);
        if (info.isValid()) {
            emit positionUpdated(info);
        }
    }
}

QQueue<QGeoPositionInfo> GpxFilePositionSource::readGpx() {
    QQueue<QGeoPositionInfo> posList;
    QXmlStreamReader reader(gpxFile);

    while(!reader.atEnd() && !reader.hasError()) {
        reader.readNext();
        if (reader.isStartElement() && reader.name() == "trkseg") {
            while(reader.readNextStartElement()) {
                if(reader.name() == "trkpt") {
                    double latitude = 0;
                    double longitude = 0;
                    double altitude = 0.0;
                    double speed = 0.0;
                    bool hasLatitude = false;
                    bool hasLongitude = false;
                    QDateTime timestamp;

                    latitude = reader.attributes().value("lat").toDouble(&hasLatitude);
                    longitude = reader.attributes().value("lon").toDouble(&hasLongitude);

                    while(reader.readNextStartElement()) {
                        if(reader.name() == "time") {
                            timestamp = QDateTime::fromString(reader.readElementText(), Qt::ISODate);
                        } else if(reader.name() == "speed") {
                            speed = reader.readElementText().toDouble();
                        } else if(reader.name() == "ele") {
                            altitude = reader.readElementText().toDouble(&hasLongitude);
                        } else {
                            break;
                        }
                    }
                    QGeoCoordinate coordinate(latitude, longitude, altitude);
                    QGeoPositionInfo info(coordinate, timestamp);
                    info.setAttribute(QGeoPositionInfo::GroundSpeed, speed);
                    if (info.isValid()) {
                        posList.push_back(info);
                    }
                }
                else {
                    reader.skipCurrentElement();
                }
            }
        }
    }
    return posList;
}

QGeoPositionInfo GpxFilePositionSource::lastKnownPosition(bool /*fromSatellitePositioningMethodsOnly*/) const
{
    return m_posList.at(lastPosition);
}

GpxFilePositionSource::PositioningMethods GpxFilePositionSource::supportedPositioningMethods() const
{
    return AllPositioningMethods;
}

int GpxFilePositionSource::minimumUpdateInterval() const
{
    return 500;
}

QGeoPositionInfoSource::Error GpxFilePositionSource::error() const
{
    return QGeoPositionInfoSource::NoError;
}

