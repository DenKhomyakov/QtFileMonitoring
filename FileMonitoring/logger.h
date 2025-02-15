#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

class File;

class Logger : public QObject {
    Q_OBJECT

public:
    Logger() {}
    ~Logger() {}

public slots:
    void printFileExists(File* file);
    void printFileExistsAndModified(File* file);
    void printFileNotExists(const QString& filePath);
};

#endif // LOGGER_H
