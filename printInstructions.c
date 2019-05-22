#include <stdio.h>
#include <string.h>

int printInstructions(char *input){
    int n_lines;
    FILE *in;

    in = fopen(input, "r");

    if(in){

    } else {
        printf("Errore nell'apertura del file\n");
    }

    return 0;
}