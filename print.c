#include <stdlib.h>
#include <stdio.h>
#include "CVM.h"

void print (char *filename){
    FILE *in;
    in = fopen(filename, "r");

    if(in){
        int *instruction_array = NULL, arraySize = 0;
        arraySize = getSize(in);
        rewind(in);
        instruction_array = (int*)malloc(sizeof(int) * arraySize);
        fillArray(in, instruction_array);
        prntFunction(instruction_array, arraySize);
    }   else {
        perror("Error: ");
    }

    fclose(in);
}

