#include <stdio.h>
#include <unistd.h>
#include "CVM.h"

/*int main() {

    int ciao = 0;
    printf("Hello World!\n");
    ciao = printInstructions("factorial.txt");
    return 0;
}*/

int main(void) {
    char buf[255];
    getcwd(buf, sizeof(buf));
    printf("Current working directory is %s\n", buf);
    return 0;
}