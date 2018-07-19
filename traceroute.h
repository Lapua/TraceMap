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

private:
    QProcess *tracertCmd;
    QString *traceOutput;
    bool *inCmdProgress;
    QStringList IPList;
    QStringList getIPList();

private slots:
    void readTrace();
    void traceFinished(int exitCode);
};

#endif // TRACEROUTE_H
