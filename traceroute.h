#ifndef TRACEROUTE_H
#define TRACEROUTE_H

#include <QObject>
#include <QProcess>

#include <QDebug>

class Traceroute : public QObject
{
    Q_OBJECT

public:
    Traceroute();
    ~Traceroute();
    void trace(QString ip);
    QStringList* getIPList();

private:
    QProcess *tracertCmd;
    QString *traceOutput;
    QStringList *IPList;
    QStringList *oneLineList;
    bool *cmdInProgress;

signals:
    void traceFinished();

private slots:
    void readTrace();
    void extractIP(int exitCode);
};

#endif // TRACEROUTE_H
