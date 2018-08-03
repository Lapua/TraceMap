#ifndef GOOGLEMAP_H
#define GOOGLEMAP_H

#include <QObject>
#include <QtNetwork>
#include <QPixmap>
#include "getkey.h"

class googleMap : public QObject
{
    Q_OBJECT
public:
    explicit googleMap(QObject *parent = nullptr);
    void setLatlngList(QStringList *list);


private:
    QString *url;
    QStringList *latlngList;
    QPixmap *map;
    QNetworkAccessManager *manager;

signals:
    void finished();

private slots:
    void output(QNetworkReply*);

public slots:
    QPixmap* getMap();
};

#endif // GOOGLEMAP_H
