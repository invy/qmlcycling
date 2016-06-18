#ifndef RIDERDATA_H
#define RIDERDATA_H

#include <QObject>

class RiderData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(qint32 bikeWeight READ bikeWeight WRITE setBikeWeight NOTIFY bikeWeightChanged)
    Q_PROPERTY(qint32 tireWidth READ tireWidth WRITE setTireWidth NOTIFY tireWidthChanged)
    Q_PROPERTY(qint32 largeChainRing READ largeChainRing WRITE setLargeChainRing NOTIFY largeChainRingChanged)
    Q_PROPERTY(qint32 smallChainRing READ smallChainRing WRITE setSmallChainRing NOTIFY smallChainRingChanged)
    Q_PROPERTY(qint32 smallestCog READ smallestCog WRITE setSmallestCog NOTIFY smallestCogChanged)
    Q_PROPERTY(qint32 biggestCog READ biggestCog WRITE setBiggestCogh NOTIFY biggestCogChanged)
public:
    void setWeight(qint32 w) {
        this->m_weight = w;
        emit weightChanged();
    }
    void setBikeWeight(qint32 w) {
        this->m_bikeWeight = w;
        emit weightChanged();
    }
    void setTireWidth(qint32 w) {
        this->m_tireWidth = w;
        emit tireWidthChanged();
    }
    void setLargeChainRing(qint32 v) {
        this->m_largeChainRing = v;
        emit largeChainRingChanged();
    }
    void setSmallChainRing(qint32 v) {
        this->m_smallChainRing = v;
        emit smallChainRingChanged();
    }
    void setSmallestCog(qint32 v) {
        this->m_smallestCog = v;
        emit smallestCogChanged();
    }
    void setBiggestCogh(qint32 v) {
        this->m_biggestCog = v;
        emit biggestCogChanged();
    }

    qint32 weight() { return m_weight; }
    qint32 bikeWeight() { return m_bikeWeight; }
    qint32 tireWidth() { return m_tireWidth; }
    qint32 largeChainRing() { return m_largeChainRing; }
    qint32 smallChainRing() { return m_smallChainRing; }
    qint32 smallestCog() { return m_smallestCog; }
    qint32 biggestCog() { return m_biggestCog; }

public:
    explicit RiderData(QObject *parent = 0);

signals:
    void weightChanged();
    void bikeWeightChanged();
    void tireWidthChanged();
    void largeChainRingChanged();
    void smallChainRingChanged();
    void smallestCogChanged();
    void biggestCogChanged();
public slots:

private:
    qint32 m_weight;
    qint32 m_bikeWeight;
    qint32 m_tireWidth;
    qint32 m_largeChainRing;
    qint32 m_smallChainRing;
    qint32 m_smallestCog;
    qint32 m_biggestCog;
};

#endif // RIDERDATA_H
