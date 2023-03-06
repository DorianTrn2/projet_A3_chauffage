#include "regulation.h"

float regulationTest(int regul,float consigne,float* tabT, int nT){
    int chauffage=0;
    if(regul == 1){ // TOR
        if(consigne<tabT[nT-1]){
            cmd=40;
        }
        else{
            cmd=0;
        }


        //if(chauffage){
        //    temp_t temp;
        //    temp.exterieure = 15;
        //    temp.interieure = 15;
        //}

    }
    else{ // PID




    }
    float cmd;

    return cmd;
}


