#include <stdio.h>
#include <string.h>
#include "CVM.h"

int printInstructions(const char *input){
    int n_lines, first_read;
    FILE *in;
    char* line_buf_in;
    size_t line_in_buf_size = 0;

    in = fopen(input, "r");

    if(in){

        /*
         * Il seguente segmtno di codice mi permette di saltare tutte
         * le linee che non contengono un numero.
         */
        first_read = fgetc(in);
        while ((first_read < 48) || (first_read > 57)){
            printf("ho appena letto %c\n", (char)first_read);
            first_read = fgetc(in);
        }
        printf("ho trovato il primo numero ed è %d\n", first_read);

        //Problema: se il numero di linee è di due o più cifre, come lo vedo come int?

        while(getline(&line_buf_in, &line_in_buf_size, in)){

        }

    } else {
        printf("Errore nell'apertura del file\n");
    }

    return 0;
}