#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CVM.h"

int main(int argc, char *argv[]) {

    char *command;
    char *filename;

    command = argv[1];
    filename = argv[2];

    if(strcmp(command, "print") == 0){
        Print(filename);
    }   else if (strcmp(command, "execute") == 0){
        //fai la execute
    }   else {
        printf("Comando non riconosciuto.\n");
    }

    /*FILE *in;
    int operazione = 0, *instruction_array = NULL, arraySize = 0;
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
            rewind(in);
            instruction_array = (int*)malloc(sizeof(int) * arraySize);
            fillArray(in, instruction_array);

            Stampa(instruction_array, arraySize);
        }   else {
            printf("Errore nell'apertura del file.\n");
        }

        fclose(in);
    }*/

    return 0;
}