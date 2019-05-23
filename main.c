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
            arraySize = getSize(in);
            printf("Size: %d.\n", arraySize);
            rewind(in);
            instruction_array = (int*)malloc(sizeof(int) * arraySize);
            fillArray(in, instruction_array);
        }   else {
            printf("Errore nell'apertura del file.\n");
        }
    }

    /*int size = 0;
    FILE *in;
    char filename[128] = "";

    printf("Enter the name of the file.\n");
    scanf("%s", filename);

    in = fopen(filename, "r");

    size = findSize(in);
    printf("size: %d\n", size);*/

    return 0;
}