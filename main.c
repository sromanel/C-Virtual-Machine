#include <stdio.h>
#include <string.h>
#include "CVM.h"

/*
 * Come passare nome file?
 */

int main() {

    FILE *in;
    int operazione = 0;
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
            printf("File aperto con successo.\n");
        }   else {
            printf("Errore nell'apertura del file.\n");
        }

        fclose(in);
    }

    return 0;
}