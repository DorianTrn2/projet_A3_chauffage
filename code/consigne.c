#include "consigne.h"
#include <string.h>
#define MAX_TAILLE 5

float consigne(float thermostatprec_f){
   float value;
   if(access( ".verrouConsigne", F_OK ) == -1 ){ // verifier si le verrou
       fopen(".verrouConsigne","a+");
       char str[MAX_TAILLE]= "";
       char * endPtr;
       FILE* f = NULL;
       f = fopen("consigne.txt","r");
       if (!feof(f)){
           fgets(str, MAX_TAILLE, f); // on lit maximum taille_max caractères du fichier, on stocke le tout dans "nb"
           value = strtof( str, &endPtr); // transformer la chaine de caractère en float
           fclose(f);
       }

       if(value<5.0 || value>40.0){ // on regarde si la valeur est en dehors des bornes souhaitées
           value =  thermostatprec_f; // si non, on renverra l'ancienne valeur
       }
       remove(".verrouConsigne");
   }
   else{ // cas où le verrou est présent : on reprend l'ancienne valeur
       value = thermostatprec_f;
   }
   return value;
}
