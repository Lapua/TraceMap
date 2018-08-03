#ifndef WIDGET_H
#define WIDGET_H

#include "traceroute.h"
#include "ipregion.h"
#include "googlemap.h"
#include <QWidget>
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Traceroute *traceroute;
    IPRegion *ipregion;
    googleMap *gmap;
    QPixmap *map;
    QVBoxLayout *lay;
    QLabel *mapLabel;
    QStringList *sl;
    QStringList *sl2;


private slots:
    void getTraceIPList();
    void getIPRegionList();
    void getGMap();
};

#endif // WIDGET_H
