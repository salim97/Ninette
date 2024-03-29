#ifndef MYPARENTOBJECT_H
#define MYPARENTOBJECT_H

#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QDir>
#include <QApplication>

class MyParentObject
{
public:
    MyParentObject();
    bool msgQuestion(QString title, QString body);
    void msgCritical(QString title, QString body);
    void msgInformation(QString title, QString body);
    void msgWarning(QString title, QString body);
    void setSettings(QString key, QVariant data);
    QVariant getSettings(QString key);

private:
    QSettings *_mySettings;
    QString thisPath, settingsFilePath;
};

#endif // MYPARENTOBJECT_H
