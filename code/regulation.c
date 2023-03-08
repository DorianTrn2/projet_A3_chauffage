#include "regulation.h"
float max(float a, float b);

float regulationTest(int regul,float consigne,float* tabT, int nT){
    float reg;
    float oldT = tabT[0];
    float oldI = 0;
    float oldConsigne=consigne;
    for(int i=1;i<nT;i++){
        reg = regulation(regul, consigne, tabT[i], &oldT, &oldI,&oldConsigne);
    }
    printf("This is final reg : %f",reg);
    return reg;
}


float regulation(int regul,float consigne,float T,float* oldT, float* oldI, float* oldConsigne){
    float cmd;
    if(regul == 1){ // TOR
        *oldI = 0;
        if(consigne>T){
            cmd=40;
        }
        else{
            cmd=0;
        }
        return cmd;
    }
    else{ // PID
        if(T>=consigne){
            return 0;
        }

        if(*oldConsigne!=consigne){//check si la consigne a changé entre temps
            *oldI = 0;
        }
        *oldConsigne=consigne;


        float Kp=1,Ki=0.099998875,Kd=0.1, dt=10;
        float e = consigne - T;
        //P
        float P = Kp*e;

        //I
        float I = (consigne - max(*oldT,T))*dt;
        I+=fabs(T-*oldT)*dt/2;
        I = *oldI + Ki*I;

        //D
        float D = Kd * fabs(T - *oldT)/dt;
        //printf("%f * (%f - %f)/%f\n",Kd,T,*oldT,dt);

        float PID = I+P+D;
        //printf("P : %f, I : %f, D : %f\n",P,I,D);
        *oldT = T;
        *oldI = I;
        if(PID>100){
            PID=100;
        }
        return PID;
    }
}

float max(float a, float b){return (a>b)?a:b;}
