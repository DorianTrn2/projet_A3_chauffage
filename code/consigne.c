#include "consigne.h"
#include <string.h>
   float consigne(float thermostatPrec_f)
   {
    //printf("CONSIGNE");
    char nb[20]= "";
    FILE* f = NULL;
    f = fopen("consigne.txt","r");
    if (f != NULL)
        {
            fgets(nb, 20, f); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
            printf("%s", nb); // On affiche la chaîne

            fclose(f);
        }
        else{
        printf("prout");}
    /*int nb=0;
    while(nb!=NULL){
    int nb;
    //fgetc(stdin);

    nb=fgetc(f);
    printf("%d",nb);
    }*/
    //printf("%d",nb);
    fclose(f);




    float thermostat_f=0;
    return thermostat_f;
   
   }
