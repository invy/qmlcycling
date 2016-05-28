#ifndef SLOPEDATA_H
#define SLOPEDATA_H

#include <QObject>

#include "devicelocation.h"

class SlopeData : public QObject
{

    Q_OBJECT
    Q_PROPERTY(qreal slope READ slope NOTIFY slopeChanged)
    Q_PROPERTY(qreal alpha READ alpha WRITE setAlpha NOTIFY alphaChanged)
    Q_PROPERTY(qreal smoothedSlope READ smoothedSlope NOTIFY slopeChanged)
    Q_PROPERTY(qreal alphaSlope READ alphaSlope WRITE setAlphaSlope NOTIFY alphaSlopeChanged)

public:
    explicit SlopeData(QObject *parent = 0);

    qreal slope() const {
        return m_slopeData;
    }
    qreal smoothedSlope() const {
        return m_smoothedSlopeData;
    }

    void setAlpha(const qreal &alpha) {
        this->m_alpha = alpha;
        emit alphaChanged();
    }
    void setAlphaSlope(const qreal &alpha) {
        this->m_alphaSlope = alpha;
        emit alphaSlopeChanged();
    }


    qreal alpha() const {
        return m_alpha;
    }
    qreal alphaSlope() const {
        return m_alphaSlope;
    }

public:
    qreal getSlopeData() {
        return m_slopeData;
    }

public:
    void locationUpdated(const DeviceLocation &location);

signals:
    void slopeChanged();
    void alphaChanged();
    void alphaSlopeChanged();

public slots:

private:
    double calculateSlope(double distance, double altitudeDifference, double defaultSlope);
private:
    qreal m_slopeData;
    qreal m_smoothedSlopeData;

    qreal m_alpha;
    qreal m_alphaSlope;
    qreal m_previousAltitude;
    qreal m_previousSlopeData;
};

#endif // SLOPEDATA_H
