#include "mythread.h"
#include<QDebug>
#include "fonctiongrafcet.h"
#include<QtCore>
#include <QObject>
#include<QTime>



using namespace std;
MyThread::MyThread()
{


}

void MyThread::run()
{


    // récupérer les GPIO de grafcet
    grafcet->setGPIO(myGPIO);

    // initialisation des entrées
    myGPIO->detProduit()==false;
    myGPIO->repEtiq()==false;
    myGPIO->repCran()==false;
    myGPIO->echenillageP1()==false;
    myGPIO->echenillageP2()==false;
    //myGPIO->aru()==false;

    // initialisation des sortie
    myGPIO->marche(false);
    myGPIO->moteur1(false);
    myGPIO->moteur2(false);
    myGPIO->lisseur(false);

    // initialisation des étapes

    for (int i=1; i<16;i++){
        grafcet->Etapes[i]=0;
    }
    // initialisation des fin timer

    for (int i=1; i<16;i++){
        grafcet->Te[i]=0;
    }

    // initialisation des bits intern

    myGPIO->rising_detProduit=false;
    myGPIO->rising_echenillageP1=false;
    myGPIO->rising_echenillageP2=false;
    myGPIO->rising_repEtiq=false;
    myGPIO->rising_repCran=false;



    for (int i=1; i<16;i++){
        grafcet->B[i]=0;
    }





    //
    grafcet->Etapes[1]=1;  // étape initial à 1
    grafcet->B[11]=1;       // bit interne à 1
    grafcet->cycle=0;

myGPIO->conditioning=1;



    while (1) {


       sleep(0.1);

        if ((grafcet->HMarche()==true || grafcet->cycle==1) && myGPIO->aru()== true && myGPIO->conditioning==1 ){
            grafcet->CalculeTransition();
            grafcet->DesactiveEtapes();
            grafcet->ActiveEtapes();
            grafcet->affecteSortie();
            grafcet->temporisateur();

        }

     grafcet->aru();


   }



     qDebug() <<"break";






}














