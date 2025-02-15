#ifndef FILE_H
#define FILE_H

#include <QFileInfo>
#include <QDateTime>

class File {
public:
    File(const QString& filePath);

    QString getName() const;
    QString getPath() const;
    qint64 getSize() const;
    QDateTime getTimeChanging() const;

    bool exists() const;
    void refreshInfo();

    void setExists(bool flag);
    bool isExists() const;

    void setExistsAndModified(bool flag);
    bool isExistsAndModified() const;

    void setNotExists(bool flag);
    bool isNotExists() const;

private:
    QFileInfo fileInfo;
    QString filePath;

    bool fileExists;
    bool fileExistsAndModified;
    bool fileNotExists;
};

#endif // FILE_H
