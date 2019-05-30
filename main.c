#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CVM.h"

int main(int argc, char *argv[]) {

    char *command;
    char *filename;

    command = argv[1];
    filename = argv[2];

    if((strcmp(command, "print") == 0) || (strcmp(command, "Print") == 0)){
        print(filename);
    }   else if ((strcmp(command, "execute") == 0) || (strcmp(command, "Execute") == 0)){
        execute(filename);
    }   else {
        printf("Wrong instruction.\n");
    }

    (void)argc;

    return 0;
}
