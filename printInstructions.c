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
        first_read = fgetc(in);
        while ((first_read < 48) && (first_read > 57)){
            first_read = fgetc(in);
        }
        printf("ho trovato il primo numero ed è %d\n", first_read);

    } else {
        printf("Errore nell'apertura del file\n");
    }

    return 0;
}