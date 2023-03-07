#include <stdio.h>
#include "consigne.h"
#include "autotests.h"
#include "regulation.h"

int main(){
    /*remove(".verrouConsigne");
    float a=19;
    while(1){
        sleep(1);
        a = consigne(a);//on récupère la commande en fonction de l
        printf("cmd : %f\n",a);
    }*/

    /*float b = testConsigne();
    printf("%f", b);*/

    //printf("%f",testRegulationTOR());
    printf("\n%f", testRegulationPID());
    /*int nT = 3;
    float tab[3] = {12,13,14};
    float test = regulationTest(1,10,&tab,nT);
    printf("%f", test);*/

    /*temp_t temperature;
    temperature.exterieure = 14.0;
    temperature.interieure = tabT[nT-1];
    struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
    //int i=0; // increment de boucle
    //float puissance = 70.0; // puissance de chauffage
    //for(i=0;i< 30;i++){
    temperature = simCalc(cmd,monSimulateur_ps); // simulation de l'environnement
    //}
    simDestruct(monSimulateur_ps); // destruction de simulateur
    return temperature.interieure;*/

    //BLOC DE TEST
    /*float score1=0,score2=0,score3=0,score4=0,score5=0;
    score1 = testVisualisationT();
    score2 = testConsigne();
    score3 = testVisualisationC();Z
    score4 = testRegulationTOR();
    score5 = testRegulationPID();
    printf("----- Auto tests results: -----\n");
    printf("testVisualisationT\t:score=%g%%\n",score1*100);
    printf("testConsigne \t\t: score=%g %%\n",score2*100);
    printf("testVisualisationC\t:score=%g %%\n",score3*100);
    printf("testRegulationTOR\t:score=%g %%\n",score4*100);
    printf("testRegulationPID\t:score=%g %%\n",score5*100);
    return EXIT_SUCCESS;*/
}
