/*
 * The following file is responsible for the input from command line.
 * argc is the number of input parameters, argv[0] the name of the executable (./VM), argv[1]
 * is the instruction (either print or execute) which will be stored in the "command" string
 * and argv[2] the name of the input file, which will be stored in the "filename" string.
 * The "command" string is compared with the two default instructions (print and execute) via strcasecmp(),
 * allowing for the commands to be recognized without caring about case sensitivity.
 * If strcasecmp() returns 0 it means that the input string is either equal to "print" or "execute",
 * therefore proceeding in calling the appropriate function.
 * argc is cast to void in order to silence the "variable not used" warning.
 * 0 is then returned since main expects an integer return value.
 */

#include <stdio.h>
#include <strings.h>
#include "CVM.h"

int main(int argc, char *argv[]) {

    char *command = NULL;
    char *filename = NULL;

    command = argv[1];
    filename = argv[2];

    if(strcasecmp(command, "print") == 0){
        print(filename);
    }   else if (strcasecmp(command, "execute") == 0){
        execute(filename);
    }   else {
        printf("Wrong instruction.\n");
    }

    (void)argc;

    return 0;
}
