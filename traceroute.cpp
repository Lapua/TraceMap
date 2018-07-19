#include "traceroute.h"

Traceroute::Traceroute()
{
    tracertCmd = new QProcess;
}

Traceroute::~Traceroute()
{

}

void Traceroute::trace(QString ip)
{
    inCmdProgress = false;
    tracertCmd -> start("traceroute -n -w 1 -q 1 " + ip);

    connect(tracertCmd, SIGNAL(readyReadStandardOutput()), this, SLOT(readTrace()));
    connect(tracertCmd, SIGNAL(finished(int)), this, SLOT(traceFinished(int)));
}

void Traceroute::readTrace()
{
    if (inCmdProgress) {
        traceOutput += tracertCmd -> readAllStandardOutput();
    } else {
        traceOutput = tracertCmd -> readAllStandardOutput();
        inCmdProgress = true;
    }
}

void Traceroute::traceFinished(int exitCode)
{
    traceOutput = new
    QStringList strlist = traceOutput.split(QRegExp("\\n"), QString::SkipEmptyParts);

    for (QString it : strlist) {
        it.replace("ms", "");
        QStringList tmpStrlist = it.split(" ", QString::SkipEmptyParts);

        if (tmpStrlist.at(0).size() < 3) {
            //IPList
            //qDebug() << tmpStrlist.at(
        }
    }
}
