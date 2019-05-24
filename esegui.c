#include <stdio.h>
#include <stdlib.h>
#include "CVM.h"

void esegui (char *filename){

    FILE *in;
    int *instruction_array = NULL, arraySize = 0, stack[16384] = {0}, record[32] = {0}, *sp = NULL, *ip = NULL;

    in = fopen(filename, "r");
    if(in){
        arraySize = getSize(in);
        rewind(in);
        instruction_array = (int*)malloc(sizeof(int) * arraySize);
        fillArray(in, instruction_array);
        ip = instruction_array;
        sp = ip;
        exe
    }   else {
        perror("Errore: ");
    }
}