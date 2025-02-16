#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "filemonitoring.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qInfo() << "\tFile Monitoring Program\n";

    FileMonitoring fileMonitoring1;
    fileMonitoring1.addFile("../file1.txt");

    FileMonitoring fileMonitoring2;
    fileMonitoring2.addFile("../file2.txt");

    QTimer timer;

    QObject::connect(&timer, &QTimer::timeout, &fileMonitoring1, &FileMonitoring::checkFileStatus);
    QObject::connect(&timer, &QTimer::timeout, &fileMonitoring2, &FileMonitoring::checkFileStatus);

    timer.start(1000);

    return a.exec();
}
