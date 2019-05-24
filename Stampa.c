#include <stdio.h>
#include "CVM.h"

void Stampa(int instruction_array[], int length){
    int i = 0;

    while(i < length){
        switch(instruction_array[i]){
            case 0:
                printf("[%3d] HALT\n", i);
                i += 1;
                break;
            case 1:
                printf("[%3d] DISPLAY R%d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 2:
                printf("[%3d] PRINT_STACK %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 10:
                printf("[%3d] PUSH R%d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 11:
                printf("[%3d] POP R%d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 12:
                printf("[%3d] MOV R%d %d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case 20:
                printf("[%3d] CALL %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 21:
                printf("[%3d] RET\n", i);
                i += 1;
                break;
            case 22:
                printf("[%3d] JMP %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 23:
                printf("[%3d] JZ %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 24:
                printf("[%3d] JPOS %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 25:
                printf("[%3d] JNEG %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case 30:
                printf("[%3d] ADD R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case 31:
                printf("[%3d] SUB R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case 32:
                printf("[%3d] MUL R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case 33:
                printf("[%3d] DIV R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
        }
    }
}