#include <stdio.h>
#include <unistd.h>
#include "CVM.h"

/*
 * Come passare nome file?
 */

int main() {

    int ciao = 0;
    printf("Hello World!\n");
    ciao = printInstructions("factorial.txt");
    return 0;
}