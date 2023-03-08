#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationC.h"


void visualisationC(float puissance_f)
{
    if(access( ".verrouData", F_OK ) == -1 ) { // verifier si le verrou

        fopen(".verrouData", "a+");
        FILE *fichier = NULL;
        fichier = fopen("data.txt", "r");
        if (fichier != NULL) {
            float temp_ext;
            float temp_int;

            char* temoin_chauffe_read;

            fscanf(fichier, "%f\n%f",&temp_ext,&temp_int);
            //printf("%f\n", temp_int);
            fclose(fichier);

            fichier = fopen("data.txt", "w");
            if(puissance_f == 0){
                temoin_chauffe_read = "false";
            }
            else{
                temoin_chauffe_read = "true";
            }
            fprintf(fichier, "%.2f\n%.2f\n%s", temp_ext, temp_int, temoin_chauffe_read);
        }
        fclose(fichier);
        remove(".verrouData");
    }

}
