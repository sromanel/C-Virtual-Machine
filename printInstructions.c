#include <stdio.h>
#include <string.h>
#include "CVM.h"

int printInstructions(const char *input){
    int n_lines, first_read;
    FILE *in;
    char *line_buf_in = NULL, *ciao, temp_char[60];
    size_t line_in_buf_size = 0;

    in = fopen(input, "r");

    if(in){

        /*
         * Il seguente segmento di codice mi permette di saltare tutte
         * le linee che non contengono un numero.
         */
        while (fgets(temp_char, 60, in)){
            ciao = strtok(temp_char, ";");
            if((*ciao > 47) && (*ciao < 58)){
                printf("%s\n", ciao);
            }
        }


        //Problema: se il numero di linee è di due o più cifre, come lo vedo come int?


    } else {
        printf("Errore nell'apertura del file\n");
    }

    return 0;
}