#include "filemonitoring.h"
#include "logger.h"

FileMonitoring::FileMonitoring() {
    logger = new Logger();

    connect(this, &FileMonitoring::fileExists, logger, &Logger::printFileExists);
    connect(this, &FileMonitoring::fileExistsAndModified, logger, &Logger::printFileExistsAndModified);
    connect(this, &FileMonitoring::fileNotExists, logger, &Logger::printFileNotExists);
}

FileMonitoring::~FileMonitoring() {
    delete logger;
}

void FileMonitoring::addFile(const QString& filePath) {
    File file(filePath);
    file.refreshInfo();

    repository.push_back(file);
}

void FileMonitoring::deleteFile(const QString& filePath) {
    int index = -1;

    for (int i = 0; i < repository.size(); ++i) {
        if (repository[i].getPath() == filePath) {
            index = i;

            break;
        }
    }

    if (index != -1) {
        repository.removeAt(index);
    }
}

void FileMonitoring::checkFileStatus() {
    for (auto& currentFile : repository) {
        QFileInfo updatedFileInfo(currentFile.getPath());

        if (!updatedFileInfo.isFile()) {
            if (!currentFile.isNotExists()) {
                emit fileNotExists(currentFile.getPath());

                currentFile.setNotExists(true);
                currentFile.setExists(false);
                currentFile.setExistsAndModified(false);
            }
        } else {
            if (updatedFileInfo.lastModified() == currentFile.getTimeChanging()) {
                if (!currentFile.isExists()) {
                    emit fileExists(&currentFile);

                    currentFile.setExists(true);
                    currentFile.setNotExists(false);
                }
            } else {
                currentFile.refreshInfo();

                emit fileExistsAndModified(&currentFile);

                currentFile.setExistsAndModified(true);
                currentFile.setExists(true);
                currentFile.setNotExists(false);
            }
        }
    }
}
