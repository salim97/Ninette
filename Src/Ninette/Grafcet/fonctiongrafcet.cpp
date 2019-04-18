
#include "fonctiongrafcet.h"
#include<QDebug>
#include<QtCore>
#include<QTimer>

#include<QTime>
#include"mygpio.h"



FonctionGrafcet::FonctionGrafcet(QObject *parent) : QObject(parent)
{


}


void FonctionGrafcet::CalculeTransition()
{
    Transitions[1]= Etapes[1] && myGPIO->rising_detProduit== true && HMarche()==1 && (HEtiq()==1 || HContreEtiq()==1);
   // Transitions[1]= Etapes[1] && myGPIO->detProduit() == true && HMarche()==1 && (HEtiq()==1 || HContreEtiq()==1);
    Transitions[2]= Etapes[2] && Te[1]==1 ;
    Transitions[3]= Etapes[3] && Te[2]==1;
    Transitions[4]= Etapes[4] && Te[3]==1 && (HRepEtiq()==1 || HRepCran()==1);    //secu reperage
    Transitions[5]= Etapes[4] && ((HRepEtiq()==0 &&HRepCran()==0)  || (HRepEtiq()==1 && myGPIO->rising_repEtiq==true) || (HRepCran()==1 && myGPIO->rising_repCran==true));

    Transitions[6]= Etapes[5] && bit_Etiq ==0 && myGPIO->moteur1()==false && bit_contre_etiq==0 && myGPIO->moteur2()==false;
            //((HEtiq()==1 && myGPIO->moteur1()==true && HContreEtiq()==1 && myGPIO->moteur2()==true)
    //||  (HEtiq()==1 && myGPIO->moteur1()==true && HContreEtiq()==0 && myGPIO->moteur2()==false)
    //||  (HEtiq()==0 && myGPIO->moteur1()==false && HContreEtiq()==1 && myGPIO->moteur2()==true));

    Transitions[7]= Etapes[5] && Te[6]==1;    // secu etiq

    Transitions[8]= Etapes[6] && myGPIO->moteur1()==false && myGPIO->moteur2()==false && HEtiqContreEtiq()==0;
    Transitions[9] = Etapes[6] && myGPIO->moteur1()==false && myGPIO->moteur2()==false && HEtiqContreEtiq()==1;

    Transitions[10] = Etapes[7] && myGPIO->moteur1()==false && HEtiqContreEtiq()==1 && bit_etiq_contre_etiq==0;

    Transitions[11]= Etapes[7] && Te[10]==1;    // secu etiqContreEtiq

    Transitions[12]= Etapes[8] && myGPIO->moteur1()==false && HEtiqContreEtiq()==1;

    Transitions[13]= Etapes[9] && Te[12]==1;


    Transitions[14]= Etapes[10] && myGPIO->lisseur()==false;



}


void FonctionGrafcet::DesactiveEtapes()
{
    if (Transitions[1]) Etapes[1]=0;
    if (Transitions[2]) Etapes[2]=0;
    if (Transitions[3]) Etapes[3]=0;

    if (Transitions[4])Etapes[4]=0;
    if (Transitions[5])Etapes[4]=0;

    if (Transitions[6])Etapes[5]=0;

    if (Transitions[7])Etapes[5]=0;
    if (Transitions[8])Etapes[6]=0;
    if (Transitions[9])Etapes[6]=0;

    if (Transitions[10])Etapes[7]=0;

    if (Transitions[11])Etapes[7]=0;
    if (Transitions[12])Etapes[8]=0;

    if (Transitions[13])Etapes[9]=0;

    if (Transitions[14])Etapes[10]=0;



}

void FonctionGrafcet::ActiveEtapes()
{
    if (Transitions[1]) Etapes[2]=1;
    if (Transitions[2]) Etapes[3]=1;
    if (Transitions[3]) Etapes[4]=1;
    if (Transitions[4]) Etapes[1]=1;
    if (Transitions[5]) Etapes[5]=1;
    if (Transitions[6]) Etapes[6]=1;
    if (Transitions[7]) Etapes[1]=1;
    if (Transitions[8]) Etapes[9]=1;
    if (Transitions[9]) Etapes[7]=1;
    if (Transitions[10]) Etapes[8]=1;
    if (Transitions[11]) Etapes[1]=1;
    if (Transitions[12]) Etapes[9]=1;
    if (Transitions[13]) Etapes[10]=1;
    if (Transitions[14]) Etapes[1]=1;


}

void FonctionGrafcet::affecteSortie()

{


    if (Etapes[1]==1 && B[11]==1){
        myGPIO->marche(false);
        myGPIO->moteur1(false);
        myGPIO->moteur2(false);
        myGPIO->lisseur(false);

        B[1]=1;
        Te[3]=0;
        Te[6]=0;
       // myGPIO->conditioning=0;



        for (int i=1; i<16;i++){
            Te[i]=0;
        }
        cycle=0;
        bit_Etiq=0;
        bit_contre_etiq=0;
        bit_etiq_contre_etiq=0;


        Te[10]=0;
        Te[9]=0;
        qDebug() <<"etape1";


        B[11]=0;



    }


    if (Etapes[2]==1 && B[1]==1) {
        qDebug() <<"etape2";
        T1.start();    // retard detect

        B[11]=1;
        B[2]=1;

        cycle=1;
        B[1]=0;
        }

    if (Etapes[2]==1 && HEtiq()==1) {
        bit_Etiq=1;
        }
    if (Etapes[2]==1 && HContreEtiq()==1) {
        bit_contre_etiq=1;
        }
    if (Etapes[2]==1 && HEtiqContreEtiq()==1) {
        bit_etiq_contre_etiq=1;
        qDebug() <<"bit_etiq_contre_etiq=1;";
        }

    //

    if (Etapes[3]==1 && B[2]==1) {
        qDebug() <<"etape3";

        T2.start();      // retard repérage
        myGPIO->lisseur(true);

        Te[1]=0;

        B[3]=1;
        E3(true);
        B[2]=0;

    }

    if (Etapes[4]==1 && B[3]==1) {
        qDebug() <<"etape4";

        T3.start();     // secu repérage


        Te[2]=0;
        B[4]=1;

        B[5]=1;
        B[6]=1;

        B[7]=1;
        B[8]=1;
        B[9]=1;



        B[12]=1;
        B[13]=1;
        B[14]=1;
        B[3]=0;
    }

    // retard sortie etiq

    if (Etapes[5]==1 && B[4]==1) {
        qDebug() <<"etape5";

        T4.start();  // retard sortie etic
        T5.start();  // retard sortie contreEtiq
        T6.start();  // secu etiq

        B[4]=0;
    }

    if (Etapes[5]==1 && HEtiq()==1 && Te[4]==1 && B[12]==1){         // retard sortie etiq
        qDebug() <<"Set M1";

        myGPIO->moteur1(true);
        B[12]=0;
    }

    if (Etapes[5]==1 && Te[5]==1 && HContreEtiq()==1 && B[13]==1) {   // retard sortie contre etiq
        qDebug() <<"Set M2";

        myGPIO->moteur2(true);
        B[13]=0;
    }

    //
    if (Etapes[5]==1 && HEtiq()==1 && myGPIO->rising_echenillageP1 ==true && B[5]==1) {


        qDebug() <<"echenillage M1";
        T7.start();  // retard arret M1


        B[5]=0;
    }





    if (Etapes[5]==1 && HContreEtiq()==1 && myGPIO->rising_echenillageP2== true && B[6]==1) {

        qDebug() <<"echenillage M2";
        T8.start();  // retard arret M2



        B[6]=0;
    }

    if (Etapes[6]==1) {

        qDebug() <<"etape6";
       // myGPIO->rising_echenillageP1=false;

    }

    if (Etapes[7]==1 && B[7]==1) {

        qDebug() <<"etape7";

    }

    // retard etiqContre etiq
    if (Etapes[7]==1 && B[7]==1 ) {

        qDebug() <<"retard contre etiq-contre-etiq ";
        T9.start();  // retard contre etiq-contre-etiq
        T10.start();

        B[7]=0;
    }

    if (Etapes[7]==1 && Te[9]==1 && B[14]==1 ) {

        qDebug() <<"Moteur M1 contre etiq-contre-etiq ";

        myGPIO->moteur1(true);
        B[14]=0;
    }

    // arret etiqContreEtiq

    if (Etapes[7]==1 && HEtiqContreEtiq()==1 && myGPIO->rising_echenillageP1 == true && B[8]==1) {

        qDebug() <<"arret etiqContreEtiq ";
        T11.start();  // retard arret etiqContreEtiq   
        B[8]=0;

    }


    if (Etapes[8]==1 ) {

        qDebug() <<"etape8 ";


    }

    if (Etapes[9]==1 &&  B[9]==1 ){

        qDebug() <<"etape9 ";
        T12.start();  // temps lissage

        Te[4]=0;
        Te[5]=0;

        C1(C1()+1);
        C2(C2()+1);

        B[9]=0;

    }

    if (Etapes[10]==1  ){

        qDebug() <<"etape10 ";
        myGPIO->lisseur(false);
        myGPIO->conditioning=0;

        Te[12]=0;
    }

}

void FonctionGrafcet::temporisateur()
{

    if(T1.elapsed()>= D1() && Etapes[2]==1 )
    {
        qDebug()<<"hello Te1";
        Te[1]=1;
    }
    if(T2.elapsed()>=D2() && Etapes[3]==1 )
    {
        qDebug()<<"hello Te2";
        Te[2]=1;
    }

    if(T3.elapsed()>=D3() && Etapes[4] && ((HRepCran()==1 || HRepEtiq()==1)) )
    {
        qDebug()<<"hello Te3  secu reperage";
        dreperage(true);

        Te[3]=1;
    }


    // retard sortie etiq

    if(T4.elapsed()>=D4() && T4.elapsed()<D4()+50 && Etapes[5] && HEtiq()==1 )
    {
        qDebug()<<"hello Te4";
        Te[4]=1;
    }
    if(T5.elapsed()>=D5() && T5.elapsed()<D5()+50 &&  Etapes[5] && HContreEtiq()==1)
    {
        qDebug()<<"hello Te5";
        Te[5]=1;
    }
    // secu etiq

    if(T6.elapsed()>=D6() && Etapes[5])
    {
        qDebug()<<"hello Te6 secu etiq";
        dechenlliage(true);
        Te[6]=1;

    }


    // retard arret etiq

    if(T7.elapsed()>=D7() && T7.elapsed()<D7()+50 && Etapes[5] && HEtiq()==1)
    {
        qDebug()<<"arret M1";
        myGPIO->moteur1(false);
        bit_Etiq=0;

    }

    if(T8.elapsed()>=D8() && T8.elapsed()<D8()+50 && Etapes[5] && HContreEtiq()==1)
    {
        qDebug()<<"arret M2";
        myGPIO->moteur2(false);
        bit_contre_etiq=0;

    }

    // retard etiqcontreEtiq

    if(T9.elapsed()>=D9() && Etapes[7]&& Te[9]==0)
    {
        qDebug()<<"hello Te9";
        Te[9]=1;
    }

    // secu etiq

    if(T10.elapsed()>=D6() && Etapes[7])
    {
        qDebug()<<"hello Te10 secu etiq ";
        dechenlliage(true);
        Te[10]=1;
    }



    // arrret etiqcontreEtiq
    if(T11.elapsed()>=D10() && T11.elapsed()<D10()+50 &&  Etapes[7] && myGPIO->moteur1()==1 )
    {
        qDebug()<<"arret M1 ECE";
        myGPIO->moteur1(false);
        bit_etiq_contre_etiq=0;
    }

    // temps lissage

    if(T12.elapsed()>=D11() && Etapes[9] )
    {
        qDebug()<<"hello lissage";
        Te[12]=1;
    }


}

void FonctionGrafcet::aru()
{
    if (myGPIO->aru()==false && HMarche()== true ){
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
            Etapes[i]=0;
        }
        // initialisation des fin timer

        for (int i=1; i<16;i++){
            Te[i]=0;
        }

        // initialisation des bits intern

        myGPIO->rising_detProduit=false;
        myGPIO->rising_echenillageP1=false;
        myGPIO->rising_echenillageP2=false;
        myGPIO->rising_repEtiq=false;
        myGPIO->rising_repCran=false;



        for (int i=1; i<16;i++){
            B[i]=0;
        }




        //
        Etapes[1]=1;  // étape initial à 1
        B[11]=1;       // bit interne à 1
        cycle=0;

    myGPIO->conditioning=1;

    }
}






