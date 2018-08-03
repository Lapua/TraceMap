#ifndef IPREGION_H
#define IPREGION_H

#include <QObject>
#include <QtNetwork>
#include <QTextDocument>
#include <QTextBlock>

#include <QDebug>

class IPRegion : public QObject
{
    Q_OBJECT
public:
    explicit IPRegion(QObject *parent = nullptr);
    ~IPRegion();

    void setIPList(QStringList *IPList);
    void requestGetLatLng();

    QStringList* getLatlngList();

private:
    QNetworkAccessManager *manager;
    QTextDocument *textDoc;
    QTextBlock *latTextBlock;
    QTextBlock *lngTextBlock;
    QStringList *IPList;
    QStringList *latlngList;
    QString *url;

    //void getLatlngOnce();

signals:
    void locateFinished();
    void extractFinished();

private slots:
    void extractLatLng(QNetworkReply*);
    void isIPListEmpty();
};

#endif // IPREGION_H
