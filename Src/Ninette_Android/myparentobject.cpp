#include "myparentobject.h"

MyParentObject::MyParentObject()
{
    thisPath = QDir::toNativeSeparators(QApplication::applicationDirPath());
        settingsFilePath = thisPath +"/settings.ini" ;
        _mySettings = new QSettings(settingsFilePath, QSettings::IniFormat);

}

bool MyParentObject::msgQuestion(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(body);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
      return true ;
    }

    return false ;
}
void MyParentObject::msgCritical(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox::critical(0,title,body);
}
void MyParentObject::msgInformation(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox::information(0,title,body);
}
void MyParentObject::msgWarning(QString title ,QString body)
{
    qDebug() << "title: "+ title << "\nboady: "+ body ;
    QMessageBox::warning(0,title,body);
}

void MyParentObject::setSettings(QString key, QVariant data)
{
    _mySettings->setValue(key, data);
}

QVariant MyParentObject::getSettings(QString key)
{
    return _mySettings->value(key) ;
}
