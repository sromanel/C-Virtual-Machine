//
// Created by Simone Romanello on 22/05/2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CVM.h"

int main() {

    FILE *in;
    int operazione = 0, *instruction_array = NULL, i, arraySize = 0;
    char instruction[7], filename[128] = " ";

    printf("Scegliere l'operazione:\n1)stampa\n2)esegui\n");
    scanf("%s", instruction);
    if(strcmp(instruction, "stampa") == 0){
        printf("Hai scelto stampa.\n");
        operazione = 1;
    }   else if(strcmp(instruction, "esegui") == 0){
        printf("hai scelto esegui.\n");
        operazione = 2;
    }   else {
        printf("Operazione non riconosciuta.\n");
    }

    if(operazione == 1 || operazione == 2){
        printf("Inserire il nome del file.\n");
        scanf("%s", filename);

        in = fopen(filename, "r");

        if(in){
            arraySize = findSize(in);
            printf("la dimensione dell'array è %d\n", arraySize);
            /*instruction_array = (int*)malloc(sizeof(int) * arraySize);
            printf("la dimensione dell'array è %d\n", (int)(sizeof(instruction_array)/ sizeof(int)));
            fillArray(in, instruction_array);
            for(i = 0; i < sizeof(instruction_array)/ sizeof(int); i++){
                printf("[%d]: %d\n", i, instruction_array[i]);
            }*/
        }   else {
            printf("Errore nell'apertura del file.\n");
        }

        fclose(in);
    }

    return 0;
}