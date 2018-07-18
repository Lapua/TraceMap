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
}

Widget::~Widget()
{

}
