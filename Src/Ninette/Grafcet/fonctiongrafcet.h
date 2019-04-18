#ifndef FONCTIONGRAFCET_H
#define FONCTIONGRAFCET_H
#include<QtCore>
#include "mygpio.h"
#include <QObject>
#include "thread"
#include<QTime>
#include<QString>
#include"mypropertyhelper.h"
#include"myparentobject.h"


class FonctionGrafcet : public QObject, public MyParentObject
{
    Q_OBJECT



public:

    explicit FonctionGrafcet(QObject *parent = nullptr);




    char Etapes[15];
    char Transitions[15];
    char B[15];
    char Te[15];
    bool cycle;
    bool bit_Etiq;
    bool bit_contre_etiq;
    bool bit_etiq_contre_etiq;






    void CalculeTransition();
    void DesactiveEtapes();
    void ActiveEtapes();
    void affecteSortie();
    void temporisateur();
    void aru();
    void setGPIO(MyGPIO *gpio){
        myGPIO= gpio;}

    //zones mémoires D
    AUTO_PROPERTY(int , D1) // temps retard detect
    AUTO_PROPERTY(int , D2) // temps retard reperage
    AUTO_PROPERTY(int , D3) // temps secu reperage
    AUTO_PROPERTY(int , D4) // temps retard etiq 1
    AUTO_PROPERTY(int , D5) // temprs retard etiq 2
    AUTO_PROPERTY(int , D6) // temps secu etiq
    AUTO_PROPERTY(int , D7) // temps arret etiq E
    AUTO_PROPERTY(int , D8) // temps arret etiq CE
    AUTO_PROPERTY(int , D9) // temps retard etiq ECE
    AUTO_PROPERTY(int , D10) // temps arret etiq ECE
    AUTO_PROPERTY(int , D11) // temps lissage

    // les compteurs :
    AUTO_PROPERTY(int , C1) // Compteur temporaire
    AUTO_PROPERTY(int , C2) // Compteur général

    // les defauts

    AUTO_PROPERTY(bool , dreperage)
    AUTO_PROPERTY(bool , dechenlliage)


    // les activations    H: HMI

    AUTO_PROPERTY(bool , HMarche)   // marche machine
    AUTO_PROPERTY(bool , HRepEtiq) // validation Reperage etiquette
    AUTO_PROPERTY(bool , HRepCran) // validation Reperage Cran
    AUTO_PROPERTY(bool , HEtiq)    // validation etiquette
    AUTO_PROPERTY(bool , HContreEtiq)   // validation contre etiquette
    AUTO_PROPERTY(bool , HEtiqContreEtiq)   // validation etiquette contre etiquette

    // button top momentané

    AUTO_PROPERTY(bool , TopDetc)



    AUTO_PROPERTY(bool , E3)


    QTime T1; // retard detect
    QTime T2; // retard reperage
    QTime T3; // secu reperage
    QTime T4; // retard etiq 1
    QTime T5; // retard etiq 2
    QTime T6; // secu etiq
    QTime T7; // arret etiq E
    QTime T8; // arret etiq CE
    QTime T9; // retard etiq ECE
    QTime T10; // secu etiq CE
    QTime T11; // arret etiq ECE
    QTime T12; // lissage



private :
 MyGPIO *myGPIO;

signals:

};



#endif // FONCTIONGRAFCET_H
