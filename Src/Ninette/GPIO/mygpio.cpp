#include "mygpio.h"
#include<QtCore>
#include<QDebug>
#include <iostream>
#include "fonctiongrafcet.h"
#include "mypropertyhelper.h"
#include <QProcess>


//--------------------------------------------------------------------------------
// touche pas a ca ...
MyGPIO *myGPIO = nullptr;

void MyGPIO::isrCatcher()
{
    QMetaObject::invokeMethod(myGPIO, "readAllGPIO", Qt::QueuedConnection);

}
//--------------------------------------------------------------------------------


MyGPIO::MyGPIO(QObject *parent) : QObject(parent)
{

    wiringPiSetup();
    myGPIO = this ;// use for input connection

    CALL_THIS_IN_CONSTRACTEUR_FOR_INPUT_OUTPUT_GPIO

    readAllGPIO();
}

void MyGPIO::readAllGPIO() // use for input connection  // when the state change 0 to 1 or 1 to 0 for all gpio input , this function start
{
   //  detProduit(digitalRead(pin_detProduit));
//    detProduit()==0;

//    if (detProduit() != digitalRead(pin_detProduit))
//    {
//        rising = true;
//        QThread::msleep(5);
//        if (detProduit()==0 && digitalRead(pin_detProduit)==1)
//        {
//            rising=false;
//            falling = false;

//        }
//        else {
//            rising = false;
//            falling= true ;

//        }
//        detProduit(digitalRead(pin_detProduit));

//    }



//    detProduit(digitalRead(pin_detProduit));
//        if (digitalRead(pin_detProduit)==1){
//            conditioning=true;
//        }

    if (digitalRead(pin_detProduit)==1 && bit_rising_detProduit==1){
        rising_detProduit=true;
        conditioning=1;
        qDebug() << "tising true";
        delay(10);
        rising_detProduit=false;
        bit_rising_detProduit=0;
    }
    if (digitalRead(pin_detProduit)==0){

        rising_detProduit=false;
        bit_rising_detProduit=1;
        qDebug() << "tising false";
    }


    //repEtiq(digitalRead(pin_repEtiq));



            if (digitalRead(pin_repEtiq)==1 && bit_rising_repEtiq==1){
                rising_repEtiq=true;
                delay(10);
                rising_repEtiq=false;
                bit_rising_repEtiq=0;
            }
            if (digitalRead(pin_repEtiq)==0){
                rising_repEtiq=false;
                bit_rising_repEtiq=1;

            }


    //repCran(digitalRead(pin_repCran));

            if (digitalRead(pin_repCran)==1 && bit_rising_repCran==1){
                rising_repCran=true;
                delay(10);
                rising_repCran=false;
                bit_rising_repCran=0;
            }
            if (digitalRead(pin_repCran)==0){
                rising_repCran=false;
                bit_rising_repCran=1;

            }


   // echenillageP1(digitalRead(pin_echenillageP1));

    if (digitalRead(pin_echenillageP1)==1 && bit_rising_echenillageP1==1){
        rising_echenillageP1=true;
        qDebug() << "avant T";
        delay(10);
        qDebug() << "aprés T";
        rising_echenillageP1=false;
        bit_rising_echenillageP1=0;
    }
    if (digitalRead(pin_echenillageP1)==0){

        rising_echenillageP1=false;

        bit_rising_echenillageP1=1;

    }


    //echenillageP2(digitalRead(pin_echenillageP2));

    if (digitalRead(pin_echenillageP2)==1 && bit_rising_echenillageP2==1){
        rising_echenillageP2=true;

        delay(10);

        rising_echenillageP2=false;
        bit_rising_echenillageP2=0;
    }
    if (digitalRead(pin_echenillageP2)==0){

        rising_echenillageP2=false;
        bit_rising_echenillageP2=1;

    }


    aru(digitalRead(pin_aru));

}

void MyGPIO::shutdown()
{
    process.start("poweroff",QStringList());
}




