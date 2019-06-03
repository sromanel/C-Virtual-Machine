#include <stdio.h>
#include <stdlib.h>
#include "CVM.h"

/*
 * execute() takes a string as input and tries to open the file whose name is said string. If the file doesn't exist
 * or can't be opened, the function raises an error, closes the file stream then exits the program.
 * Otherwise, it creates a dynamic array called "instruction_array", a static one called "stack"
 * which hosts 16384 integers (which is 64KB) and one called "reg", containing 32 registers.
 * Then it allocates instruction_array for the needed amount of memory using the
 * value returned by getSize() and uses rewind() to make the file pointer point at the beginning of the file again.
 * Then, it calls the fillArray() function which fills its cells with the numbers (i.e. instructions and parameters) read from the file.
 * Ultimately, it calls exeFunctions() to execute the content of the array, as requested.
 */

void execute (char *filename){

    FILE *in;
    int *instruction_array = NULL, stack[16384] = {0}, reg[32] = {0};
    unsigned int sp = 0, ip = 0, array_size = 0;

    in = fopen(filename, "r");
    if(in){
        array_size = getSize(in);
        rewind(in);
        instruction_array = (int*)malloc(sizeof(int) * array_size);
        fillArray(in, instruction_array);
        exeFunctions(instruction_array, array_size, ip, stack, reg, sp);
    }   else {
        perror("Error: ");
        fclose(in);
        exit(1);
    }

    fclose(in);
}
