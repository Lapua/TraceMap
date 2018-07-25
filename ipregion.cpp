#include "ipregion.h"

IPRegion::IPRegion(QObject *parent) : QObject(parent)
{
    url = new QString("https://www.example.com/");
    manager = new QNetworkAccessManager;
    domDocument = new QDomDocument;
}

IPRegion::~IPRegion()
{
    delete url;
    delete manager;
    delete domDocument;
}

void IPRegion::setIPList(QStringList *IPList)
{

}

void IPRegion::requestGetLatLng()
{
    manager -> get(QNetworkRequest(QUrl(*url)));

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(extractLatLng(QNetworkReply*)));
}

void IPRegion::extractLatLng(QNetworkReply *reply)
{
    qDebug() << "slot";
    //domDocument -> setContent(reply -> readAll());

    QString str =  QString::fromUtf8(reply -> readAll().data());
    qDebug() << str;
    qDebug() << reply -> error();
}
