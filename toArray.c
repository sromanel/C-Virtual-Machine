//
// Created by rommy on 23/05/2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CVM.h"

int findSize(FILE *in){
    char *textLine = NULL, *tempLine;
    size_t line_in_buf_size = 0;
    int number;

    printf("ciao\n");
    if(in){
        printf("il file è aperto\n");
    }

    while (getline(&tempLine, &line_in_buf_size, in) >= 0){
        printf("sto analizzando %s\n", tempLine);
        textLine = strtok(tempLine, ";");
        if ((*textLine >= '0') && (*textLine <= '9')) {
            number = atoi(textLine);
            return number;
        }
    }
}

void fillArray(FILE *in, int* instructionArray){
    char *textLine = NULL, *tempLine;
    size_t line_in_buf_size = 0;
    int number, first_read = 0, i = 0;

    while (getline(&tempLine, &line_in_buf_size, in) >= 0){
        textLine = strtok(tempLine, ";");
        if ((*textLine >= '0') && (*textLine <= '9')) {
            number = atoi(textLine);
            if(first_read == 0){
                instructionArray = (int*)malloc(sizeof(int) * number);
                printf("ho appena letto il numero di righe, l'array sarà lungo %d\n", number);
                first_read = 1;
            }   else {
                instructionArray[i] = number;
                printf("[%d]: %d\n", i, instructionArray[i]);
                i++;
            }
            printf("%d\n", number);
        }
    }


}

