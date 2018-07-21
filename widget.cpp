#include "widget.h"
#include <QtWidgets>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{    
    QLabel *label = new QLabel("alice");

    QLabel *imageLabel = new QLabel();
    QPixmap mapImage = QPixmap(":/images/staticmap.png");
    imageLabel -> setPixmap(mapImage);

    QVBoxLayout *lay = new QVBoxLayout;
    lay -> addWidget(label);
    lay -> addWidget(imageLabel);
    setLayout(lay);

    traceroute = new Traceroute;
    traceroute -> trace("8.8.8.8");
    connect(traceroute, SIGNAL(traceFinished()), this, SLOT(getTraceIPList()));
}

Widget::~Widget()
{

}

void Widget::getTraceIPList()
{
    QStringList *sl = traceroute -> getIPList();
    qDebug() << *sl;
}
