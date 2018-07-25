#ifndef IPREGION_H
#define IPREGION_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDomDocument>

#include <QDebug>

class IPRegion : public QObject
{
    Q_OBJECT
public:
    explicit IPRegion(QObject *parent = nullptr);
    ~IPRegion();
    void setIPList(QStringList *IPList);
    void requestGetLatLng();

private:
    QNetworkAccessManager *manager;
    QDomDocument *domDocument;
    QString *url;

signals:

private slots:
    void extractLatLng(QNetworkReply*);
};

#endif // IPREGION_H
