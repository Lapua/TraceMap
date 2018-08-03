#include "ipregion.h"

IPRegion::IPRegion(QObject *parent) : QObject(parent)
{
    url = new QString("http://keiromichi.com/index.php?ip=");
    manager = new QNetworkAccessManager;
    textDoc = new QTextDocument;
    IPList = new QStringList;
    latTextBlock = new QTextBlock;
    lngTextBlock = new QTextBlock;
    latlngList = new QStringList;

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(extractLatLng(QNetworkReply*)));
    connect(this, SIGNAL(extractFinished()), this, SLOT(isIPListEmpty()));
}

IPRegion::~IPRegion()
{
    delete url;
    delete manager;
    delete textDoc;
    delete IPList;
    delete latTextBlock;
    delete lngTextBlock;
    delete latlngList;
}

void IPRegion::setIPList(QStringList *IPList)
{
    this -> IPList = IPList;
}

void IPRegion::requestGetLatLng()
{
    qDebug() << IPList -> first();
    manager -> get(QNetworkRequest(QUrl(*url + IPList -> takeFirst())));
}

void IPRegion::extractLatLng(QNetworkReply *reply)
{
    QString str = QString::fromUtf8(reply -> readAll().data());
    textDoc -> setHtml(str);

    for (int i = 0; i < textDoc -> blockCount(); i++) {
        qDebug() << i << " : " << textDoc -> findBlockByNumber(i).text();
    }

    *latTextBlock = textDoc -> findBlockByNumber(21);
    *lngTextBlock = textDoc -> findBlockByNumber(23);

    qDebug() << latTextBlock -> text();

    if (latlngList -> empty() ||
       (latlngList -> at(latlngList->size()-2) != latTextBlock -> text() &&
        latlngList -> at(latlngList->size()-1) != lngTextBlock -> text())) {
        latlngList -> append(latTextBlock -> text());
        latlngList -> append(lngTextBlock -> text());
    }

    emit extractFinished();
}

QStringList* IPRegion::getLatlngList()
{
    return latlngList;
}

void IPRegion::isIPListEmpty()
{
    if (! IPList -> empty()) {
        requestGetLatLng();
    } else {
        qDebug() << "--------";
        for (int i = 0; i < latlngList->size(); i++) {
            qDebug() << latlngList -> at(i);
        }

        emit locateFinished();
    }
}
