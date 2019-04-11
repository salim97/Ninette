#ifndef MYGPIO_H
#define MYGPIO_H
#include <QObject>
#include "mypropertyhelper.h"
#include "wiringPi.h"
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

    INPUT_GPIO_PROPERTY(detProduit, 2)
    INPUT_GPIO_PROPERTY(repEtiq, 3)
    INPUT_GPIO_PROPERTY(repCran, 4)
    INPUT_GPIO_PROPERTY(echenillageP1, 5)
    INPUT_GPIO_PROPERTY(echenillageP2, 10)
    INPUT_GPIO_PROPERTY(aru, 31)


    OUTPUT_GPIO_PROPERTY(marche, 22)
    OUTPUT_GPIO_PROPERTY(moteur1, 23)
    OUTPUT_GPIO_PROPERTY(moteur2, 25)
    OUTPUT_GPIO_PROPERTY(lisseur, 26)

private:
    QProcess process;




signals:


public slots:  //for input gpio
     void readAllGPIO();
     void shutdown();



};

#endif // MYGPIO_H
