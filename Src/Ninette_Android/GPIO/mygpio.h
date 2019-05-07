#ifndef MYGPIO_H
#define MYGPIO_H
#include <QObject>
#include "mypropertyhelper.h"
//#include "wiringPi.h"
#include <QProcess>


class MyGPIO : public QObject
{
    Q_OBJECT

public:
    explicit MyGPIO(QObject *parent = 0);

     bool rising_detProduit;
     bool bit_rising_detProduit;

     bool rising_echenillageP1;
     bool bit_rising_echenillageP1;

     bool rising_echenillageP2;
     bool bit_rising_echenillageP2;

     bool rising_repEtiq;
     bool bit_rising_repEtiq;

     bool rising_repCran;
     bool bit_rising_repCran;


     char conditioning;

     //AUTO_PROPERTY(bool , HMarche)   // marche machine

    AUTO_PROPERTY(bool, detProduit)
    AUTO_PROPERTY(bool, repEtiq)
    AUTO_PROPERTY(bool, repCran)
    AUTO_PROPERTY(bool, echenillageP1)
    AUTO_PROPERTY(bool, echenillageP2)
    AUTO_PROPERTY(bool, aru)


    AUTO_PROPERTY(bool, marche)
    AUTO_PROPERTY(bool, moteur1)
    AUTO_PROPERTY(bool, moteur2)
    AUTO_PROPERTY(bool, lisseur)

private:
    QProcess process;




signals:


public slots:  //for input gpio
     void readAllGPIO();
     void shutdown();



};

#endif // MYGPIO_H
