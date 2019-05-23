#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CVM.h"

int Stampa(const char *input){
    int n_lines, first_read;
    FILE *in;
    char *textLine = NULL, *tempLine;
    size_t line_in_buf_size = 0;

    in = fopen(input, "r");

    if(in){

        /*
         * Il seguente segmento di codice mi permette di saltare tutte
         * le linee che non contengono un numero.
         *
         * USA atoi
         * USA getline
         */

        while (getline(&tempLine, &line_in_buf_size, in) >= 0){
            textLine = strtok(tempLine, ";");
            if ((*textLine >= '0') && (*textLine <= '9')) {
                first_read = atoi(textLine);
                printf("%d\n", first_read);
            }
        }

    } else {
        printf("Errore nell'apertura del file\n");
    }

    return 0;
}