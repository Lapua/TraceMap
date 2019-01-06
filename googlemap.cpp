#include "googlemap.h"
#include <QDebug>

googleMap::googleMap(QObject *parent) : QObject(parent)
{
    map = new QPixmap;
    manager = new QNetworkAccessManager;
    latlngList = new QStringList;
    url = new QString("https://maps.googleapis.com/maps/api/staticmap?path=weight%3A10%7Ccolor%3Ared");

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(output(QNetworkReply*)));
}

void googleMap::setLatlngList(QStringList *list)
{
    latlngList = list;

    while (! list -> empty()) {
        QString str = list -> takeFirst();
        if (str != "0") {
            *url += "%7C";
            *url += str;
            *url += "%2C";
            *url += list -> takeFirst();
        } else {
            list -> removeFirst();
        }
    }
    *url += "&size=640x640&key=";
    *url += GetKey::getKey();

    qDebug() << *url;

    manager -> get(QNetworkRequest(QUrl(*url)));
}

QPixmap* googleMap::getMap()
{
    return map;
}

void googleMap::output(QNetworkReply *rep)
{
    map -> loadFromData(rep -> readAll());
    emit finished();
}
