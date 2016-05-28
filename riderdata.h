#ifndef RIDERDATA_H
#define RIDERDATA_H

#include <QObject>

class RiderData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(qint32 bikeWeight READ bikeWeight WRITE setBikeWeight NOTIFY bikeWeightChanged)
    Q_PROPERTY(qint32 tireWidth READ tireWidth WRITE setTireWidth NOTIFY tireWidthChanged)
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

    qint32 weight() { return m_weight; }
    qint32 bikeWeight() { return m_bikeWeight; }
    qint32 tireWidth() { return m_tireWidth; }


public:
    explicit RiderData(QObject *parent = 0);

signals:
    void weightChanged();
    void bikeWeightChanged();
    void tireWidthChanged();
public slots:

private:
    qint32 m_weight;
    qint32 m_bikeWeight;
    qint32 m_tireWidth;
};

#endif // RIDERDATA_H
