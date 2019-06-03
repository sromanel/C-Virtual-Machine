#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "CVM.h"

unsigned int getSize(FILE *in){
    char *textLine = NULL, *line_buf = NULL;
    size_t line_in_buf_size = 0;
    unsigned int number = 0, found = 0;

    while (getline(&line_buf, &line_in_buf_size, in) >= 0 && found == 0){
        textLine = strtok(line_buf, ";");
        if ((*textLine >= '0') && (*textLine <= '9')) {
            number = atoi(textLine);
            found = 1;
        }
    }

    return number;
}

void fillArray(FILE *in, int* instructionArray){
    char *textLine = NULL, *line_buf = NULL, *ptr = NULL;
    size_t line_in_buf_size = 0;
    int first_read = 0, i = 0;
    /*
     * number non è più int
     */
    long number = 0;

    while (getline(&line_buf, &line_in_buf_size, in) >= 0){
        textLine = strtok(line_buf, ";");
        if (((*textLine >= '0') && (*textLine <= '9')) || (*textLine == '-')) {
            /*number = atoi(textLine);*/
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
