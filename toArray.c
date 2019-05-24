//
// Created by Simone Romanello on 23/05/2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CVM.h"

int getSize(FILE *in){
    char *textLine = NULL, *line_buf = NULL;
    size_t line_in_buf_size = 0;
    int number = 0, found = 0;

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
    char *textLine = NULL, *line_buf = NULL;
    size_t line_in_buf_size = 0;
    int number = 0, first_read = 0, i = 0;

    while (getline(&line_buf, &line_in_buf_size, in) >= 0){
        textLine = strtok(line_buf, ";");
        if ((*textLine >= '0') && (*textLine <= '9')) {
            number = atoi(textLine);
            if(first_read == 0){
                first_read = 1;
            }   else {
                instructionArray[i] = number;
                i++;
            }
        }
    }
}