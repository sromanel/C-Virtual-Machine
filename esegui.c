#include <stdio.h>
#include <stdlib.h>
#include "CVM.h"

void esegui (char *filename){

    FILE *in;
    int *instruction_array = NULL, stack[16384] = {0}, record[32] = {0};
    unsigned int sp = 0, ip = 0, array_size = 0;

    in = fopen(filename, "r");
    if(in){
        array_size = getSize(in);
        rewind(in);
        instruction_array = (int*)malloc(sizeof(int) * array_size);
        fillArray(in, instruction_array);
        execute(instruction_array, array_size, ip, stack, record, sp);
    }   else {
        perror("Errore: ");
    }
}