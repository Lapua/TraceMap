#include "traceroute.h"

Traceroute::Traceroute()
{
    tracertCmd = new QProcess;
}

void Traceroute::trace(QString ip)
{
    tracertCmd -> start("traceroute 8.8.8.8");
    QString str = tracertCmd -> readAllStandardOutput();
    QStringList strlist = str.split(".");
    QString str1 = strlist[0];

    qDebug() << str1;
    //qDebug() << strlist[1];
    //qDebug() << strlist[2];
}

void Traceroute::traceFinished()
{

}
