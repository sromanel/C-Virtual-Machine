#include <stdio.h>
#include <string.h>
#include "CVM.h"

int printInstructions(const char *input){
    int n_lines, first_read, size = 0;
    FILE *in;
    char* line_buf_in = NULL, ciao, temp_char;
    size_t line_in_buf_size = 0;

    in = fopen(input, "r");

    if(in){

        /*
         * Il seguente segmento di codice mi permette di saltare tutte
         * le linee che non contengono un numero.
         */
        temp_char = *fgets(&temp_char, strlen(&temp_char), in);
        while ((temp_char < 47) || (temp_char > 57)){
            printf("%s", &temp_char);
        }

        //Problema: se il numero di linee è di due o più cifre, come lo vedo come int?

        while(getline(&line_buf_in, &line_in_buf_size, in)){

        }

    } else {
        printf("Errore nell'apertura del file\n");
    }

    return 0;
}