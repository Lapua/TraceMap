#ifndef WIDGET_H
#define WIDGET_H

#include "traceroute.h"
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Traceroute *traceroute;
};

#endif // WIDGET_H
