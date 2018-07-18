#ifndef TRACEROUTE_H
#define TRACEROUTE_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class Traceroute
{
public:
    Traceroute();
    void trace(QString ip);

private:
    QProcess *tracertCmd;

};

#endif // TRACEROUTE_H
