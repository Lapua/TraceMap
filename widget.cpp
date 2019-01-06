#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{    
    QLabel *label = new QLabel("Traceroute MAP");

    lay = new QVBoxLayout;
    lay -> addWidget(label);
    setLayout(lay);

    traceroute = new Traceroute;
    traceroute -> trace("8.8.8.8");
    connect(traceroute, SIGNAL(traceFinished()), this, SLOT(getTraceIPList()));

    sl = new QStringList;
    sl2 = new QStringList;
    gmap = new googleMap;
    map = new QPixmap;
}

Widget::~Widget()
{

}

void Widget::getTraceIPList()
{
    sl = traceroute -> getIPList();

    ipregion = new IPRegion;
    ipregion -> setIPList(sl);
    ipregion -> requestGetLatLng();

    connect(ipregion, SIGNAL(locateFinished()), this, SLOT(getIPRegionList()));
}

void Widget::getIPRegionList()
{
    qDebug() << "getlatlng";
    sl2 = ipregion -> getLatlngList();
    gmap -> setLatlngList(sl2);

    connect(gmap, SIGNAL(finished()), this, SLOT(getGMap()));
}

void Widget::getGMap()
{
    map = gmap -> getMap();

    mapLabel = new QLabel;
    mapLabel -> setPixmap(*map);
    lay -> addWidget(mapLabel);
    setLayout(lay);

    qDebug() << "all finished";
}
