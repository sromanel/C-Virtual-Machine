#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "CVM.h"

/*
 * getSize() takes a valid file as input. It then proceeds to scan all the lines in it using getline(),
 * then creates a token from the starting point of the line to the first ';' encountered. It then analyzes
 * the first character in said line, if it is valid (i.e. a number) it gets its integer equivalent by calling
 * strtol() which takes a string as input and returns its long int equivalent.
 * If the returned value is between the upper and lower limits of the int type, the flag found is set to 1,
 * making the while loop come to a stop, then returns said number after casting it to unsigned int.
 * Otherwise, it prints the encountered error then exits the program.
 */

unsigned int getSize(FILE *in){
    char *textLine = NULL, *line_buf = NULL, *ptr = NULL;
    size_t line_in_buf_size = 0;
    long int number = 0;
    unsigned int found = 0;

    while (getline(&line_buf, &line_in_buf_size, in) >= 0 && found == 0){
        textLine = strtok(line_buf, ";");
        if ((*textLine >= '0') && (*textLine <= '9')) {
            number = strtol(textLine, &ptr, 10);
            if(INT_MIN <= number && number <= INT_MAX){
                found = 1;
            }   else {
                printf("Number is larger than INT_MAX or smaller than INT_MIN.\n");
                exit(1);
            }
        }
    }

    return (unsigned int)number;
}

/*
 * the fillArray() function takes a valid file and the pointer to an array as inputs,
 * then reads the lines in the file until it finds the first integer. Once it is found, the 'found' flag
 * is set to 1, meaning that we've just read the first number on the file which is the number of instructions.
 * Once that is done, it keeps reading lines until the end of the file, then makes tokens out of them
 * from the starting point of the line until the first ';' found. If the line is "valid" (i.e. a number
 * or the minus symbol) it calls the strtol() function using the line it just read as input.
 * Strtol() returns the long int equivalent of the string it received; if said number is between the
 * upper and lower limit of the int type it is stored at the i-th position of the instruction array,
 * otherwise, the corresponding error is printed and the program stops.
 */

void fillArray(FILE *in, int* instructionArray){
    char *textLine = NULL, *line_buf = NULL, *ptr = NULL;
    size_t line_in_buf_size = 0;
    int first_read = 0, i = 0;
    long number = 0;

    while (getline(&line_buf, &line_in_buf_size, in) >= 0){
        textLine = strtok(line_buf, ";");
        if (((*textLine >= '0') && (*textLine <= '9')) || (*textLine == '-')) {
            number = strtol(textLine, &ptr, 10);
            if(first_read == 0){
                first_read = 1;
            }   else {
                if (INT_MIN <= number && number <= INT_MAX){
                    instructionArray[i] = (int)number;
                    i++;
                }   else {
                    printf("Number is larger than INT_MAX or smaller than INT_MIN.\n");
                    exit(1);
                }

            }
        }
    }
}
