#include "regulation.h"
float regulation(int regul,float consigne,float T,float* oldT, float* oldI);


float regulationTest(int regul,float consigne,float* tabT, int nT){
    float reg;
    float oldT = 98272390;
    float oldI = 0;
    for(int i=0;i<nT;i++){
        reg = regulation(regul, consigne, tabT[i], &oldT, &oldI);
    }
    //printf("This is final reg : %f",reg);
    return reg;
}


float regulation(int regul,float consigne,float T,float* oldT, float* oldI){
    float cmd;
    if(regul == 1){ // TOR
        *oldI = 0;
        if(consigne>T){
            cmd=40;
        }
        else{
            cmd=0;
        }
    }
    else{ // PID
        float Kp=1,Ki=0.0967,Kd=0.1, dt=10;

        //P
        float e = consigne - T;
        float P = Kp*e;

        //I
        float e2 = T - consigne;
        e2 = (e2>0) ? e2 : -e2;
        float I = *oldI + Ki*(e2*dt);

        //D
        float D = Kd * (T- *oldT )/dt;

        float PID = I+P+D;
        *oldT = T;
        *oldI = I;
        return PID;
    }
}

