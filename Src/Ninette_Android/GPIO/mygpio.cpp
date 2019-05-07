#include "mygpio.h"
#include<QtCore>
#include<QDebug>
#include <iostream>
#include "fonctiongrafcet.h"
#include "mypropertyhelper.h"
#include <QProcess>

using namespace std;


namespace{    // use for input connection

MyGPIO *myGPIO;

    void gpioTrigger_INT1(void)
    {
        //qDebug() << "void gpioTrigger_INT1(void)";
        QMetaObject::invokeMethod(myGPIO, "readAllGPIO", Qt::QueuedConnection);
    }

}

MyGPIO::MyGPIO(QObject *parent) : QObject(parent)
{

/*
    wiringPiSetup();
    myGPIO = this ;// use for input connection
    pinMode(pin_detProduit, INPUT);// use for input connection
    wiringPiISR(pin_detProduit, INT_EDGE_BOTH, &gpioTrigger_INT1); // use for input connection
    pullUpDnControl(pin_detProduit, PUD_DOWN);


    pinMode(pin_repEtiq, INPUT);// use for input connection
    wiringPiISR(pin_repEtiq, INT_EDGE_BOTH, &gpioTrigger_INT1); // use for input connection
    pullUpDnControl(pin_repEtiq, PUD_DOWN);


    pinMode(pin_repCran, INPUT);// use for input connection
    wiringPiISR(pin_repCran, INT_EDGE_BOTH, &gpioTrigger_INT1); // use for input connection
    pullUpDnControl(pin_repCran, PUD_DOWN);


    pinMode(pin_echenillageP1, INPUT);// use for input connection
    wiringPiISR(pin_echenillageP1, INT_EDGE_BOTH , &gpioTrigger_INT1); // use for input connection
    pullUpDnControl(pin_echenillageP1, PUD_DOWN);



    pinMode(pin_echenillageP2, INPUT);// use for input connection
    wiringPiISR(pin_echenillageP2, INT_EDGE_BOTH, &gpioTrigger_INT1); // use for input connection
    pullUpDnControl(pin_echenillageP2, PUD_DOWN);

    pinMode(pin_aru, INPUT);// use for input connection
    wiringPiISR(pin_aru, INT_EDGE_BOTH, &gpioTrigger_INT1); // use for input connection
    pullUpDnControl(pin_aru, PUD_DOWN);




    pinMode(pin_marche, OUTPUT);
    pinMode(pin_moteur1, OUTPUT);
    pinMode(pin_moteur2, OUTPUT);
    pinMode(pin_lisseur, OUTPUT);

    readAllGPIO();


*/


}


void MyGPIO::readAllGPIO() // use for input connection  // when the state change 0 to 1 or 1 to 0 for all gpio input , this function start
{
    /*
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
    */

}

void MyGPIO::shutdown()
{
    process.start("poweroff",QStringList());
}




