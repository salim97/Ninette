#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include "mygpio.h"

#include <QObject>
#include <fonctiongrafcet.h>

#include <QTimer>


class MyThread : public QThread
{

public:
    FonctionGrafcet *grafcet;

    MyThread();
    void run();

    void setGPIO(MyGPIO *gpio){

        myGPIO= gpio;
    }


private :
 MyGPIO *myGPIO;

};

#endif // MYTHREAD_H
