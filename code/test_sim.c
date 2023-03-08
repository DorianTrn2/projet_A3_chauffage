#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "simulateur.h"
#include "consigne.h"
#include "autotests.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"

int main(){
    if(access( ".verrouConsigne", F_OK ) == 1 ){
        remove(".verrouConsigne");
    }
    if(access( ".verrouData", F_OK ) == 1 ){
        remove(".verrouData");
    }
    temp_t myTemp;
    myTemp.interieure = 15.0;
    myTemp.exterieure = 5;
    struct simParam_s*  monSimulateur_ps = simConstruct(myTemp);

    float cons = 0;
    float oldT = myTemp.interieure;
    float oldI = 0;
    float oldConsigne=cons;
    for(int i=0;i< 1000;i++){
            cons = consigne(cons);//on récupère la commande en fonction de l
            float reg = regulation(0,cons, myTemp.interieure, &oldT, &oldI, &oldConsigne);
            myTemp= simCalc(reg, monSimulateur_ps);
            visualisationT(myTemp);
            visualisationC(reg);
    }
    simDestruct(monSimulateur_ps);
}
