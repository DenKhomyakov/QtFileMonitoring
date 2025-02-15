#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QList>
#include <QTimer>
#include "file.h"

class Logger;

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring();
    ~FileMonitoring();

    void addFile(const QString& filePath);
    void deleteFile(const QString& filePath);

public slots:
    void checkFileStatus();

signals:
    void fileExists(File* file);
    void fileExistsAndModified(File* file);
    void fileNotExists(const QString& filePath);

private:
    QList<File> repository;
    Logger* logger;
    QTimer* timer;
};

#endif // FILEMONITORING_H
