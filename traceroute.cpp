#include "traceroute.h"

Traceroute::Traceroute()
{
    tracertCmd = new QProcess;
    inCmdProgress = new bool;
    traceOutput = new QString;
    IPList = new QStringList;
    oneLineList = new QStringList;

}

Traceroute::~Traceroute()
{
    delete tracertCmd;
    delete inCmdProgress;
    delete traceOutput;
    delete oneLineList;
    delete IPList;
}

void Traceroute::trace(QString ip)
{
    *inCmdProgress = false;
    tracertCmd -> start("traceroute -n -w 1 -q 1 " + ip);

    connect(tracertCmd, SIGNAL(readyReadStandardOutput()), this, SLOT(readTrace()));
    connect(tracertCmd, SIGNAL(finished(int)), this, SLOT(extractIP(int)));
}

QStringList* Traceroute::getIPList()
{
    return IPList;
}

void Traceroute::readTrace()
{
    if (*inCmdProgress) {
        *traceOutput += tracertCmd -> readAllStandardOutput();
    } else {
        *traceOutput = tracertCmd -> readAllStandardOutput();
        *inCmdProgress = true;
    }
}

void Traceroute::extractIP(int exitCode)
{
    *oneLineList = traceOutput -> split(QRegExp("\\n"), QString::SkipEmptyParts);

    for (QString it : *oneLineList) {
        it.replace("ms", "");
        QStringList tmpStrlist = it.split(" ", QString::SkipEmptyParts);

        if (tmpStrlist.at(0).size() < 3) {
            IPList -> append(tmpStrlist.at(1));
        }
    }

    emit traceFinished();
}
