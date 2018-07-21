#ifndef IPREGION_H
#define IPREGION_H

#include <QObject>

class IPRegion : public QObject
{
    Q_OBJECT
public:
    explicit IPRegion(QObject *parent = nullptr);
    void SetIPList(QStringList *IPList);

signals:

public slots:
};

#endif // IPREGION_H
