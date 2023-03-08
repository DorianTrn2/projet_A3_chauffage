#include "visualisationT.h"
#include <string.h>
#include <stdio.h>

void visualisationT(temp_t myTemp)
{
   float temp_int = myTemp.interieure;
   float temp_ext = myTemp.exterieure;
    if(access( ".verrouData", F_OK ) == -1 ) { // verifier si le verrou
        fopen(".verrouData", "a+");
        FILE *fichier = NULL;
        fichier = fopen("data.txt", "r");
        if (fichier != NULL) {
            char *temoin_chauffe_read = malloc(8 * sizeof(char));
            fgets(temoin_chauffe_read, 8, fichier);
            fgets(temoin_chauffe_read, 8, fichier);
            fgets(temoin_chauffe_read, 8, fichier);
            fclose(fichier);
            fichier = fopen("data.txt", "w");

            fprintf(fichier, "%.2f\n%.2f\n%s", temp_ext, temp_int, temoin_chauffe_read);
        }
        fclose(fichier);
        remove(".verrouData");
    }
}
