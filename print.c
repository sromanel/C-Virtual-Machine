#include <stdlib.h>
#include <stdio.h>
#include "CVM.h"

/*
 * print() takes a string as input and tries to open the file whose name is said string. If the file doesn't exist
 * or can't be opened, the function raises an error, closes the file stream then exits the program.
 * Otherwise, it creates a dynamic array called "instruction_array", allocates the needed amount of memory using the
 * value returned by getSize() and uses rewind() to make the file pointer point at the beginning of the file again.
 * Then, it calls the fillArray() function which fills its cells with the numbers (i.e. instructions and parameters) read from the file.
 * Ultimately, it calls prnfFunctions() to print the content of the array, as requested.
 */

void print (char *filename){
    FILE *in;
    in = fopen(filename, "r");

    if(in){
        int *instruction_array = NULL, arraySize = 0;
        arraySize = getSize(in);
        instruction_array = (int*)malloc(sizeof(int) * arraySize);
        rewind(in);
        fillArray(in, instruction_array);
        prntFunction(instruction_array, arraySize);
    }   else {
        perror("Error: ");
        fclose(in);
        exit(1);
    }

    fclose(in);
}

