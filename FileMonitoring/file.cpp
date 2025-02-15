#include "file.h"

File::File(const QString& filePath) {
    fileInfo = QFileInfo(filePath);
    this->filePath = filePath;

    fileExists = false;
    fileExistsAndModified = false;
    fileNotExists = false;
}

QString File::getName() const {
    return fileInfo.fileName();
}

QString File::getPath() const {
    return fileInfo.filePath();
}

qint64 File::getSize() const {
    return fileInfo.size();
}

QDateTime File::getTimeChanging() const {
    return fileInfo.lastModified();
}

bool File::exists() const {
    return fileInfo.exists();
}

void File::refreshInfo() {
    fileInfo.refresh();
}

void File::setExists(bool flag) {
    fileExists = flag;
}

bool File::isExists() const {
    return fileExists;
}

void File::setExistsAndModified(bool flag) {
    fileExistsAndModified = flag;
}

bool File::isExistsAndModified() const {
    return fileExistsAndModified;
}

void File::setNotExists(bool flag) {
    fileNotExists = flag;
}

bool File::isNotExists() const {
    return fileNotExists;
}
