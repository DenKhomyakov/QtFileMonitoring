#include "logger.h"
#include "file.h"
#include <QDebug>

void Logger::printFileExists(File* file) {
    qInfo() << "File " << file->getName() << " exists";
    qInfo() << "File size: " << file->getSize();
    qInfo() << "";
}

void Logger::printFileExistsAndModified(File* file) {
    qInfo() << "File " << file->getName() << " exists and modified";
    qInfo() << "File size: " << file->getSize();
    qInfo() << "";
}

void Logger::printFileNotExists(const QString& filePath) {
    qInfo() << "File on path " << filePath << "doesn't exists";
    qInfo();
}
