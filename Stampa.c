#include <stdio.h>
#include "CVM.h"

void Stampa(int instruction_array[], int length){
    int i = 0;

    while(i < length){
        switch(instruction_array[i]){
            case HALT:
                printf("[%3d] HALT\n", i);
                i += 1;
                break;
            case DISPLAY:
                printf("[%3d] DISPLAY R%d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case PRINT_STACK:
                printf("[%3d] PRINT_STACK %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case PUSH:
                printf("[%3d] PUSH R%d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case POP:
                printf("[%3d] POP R%d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case MOV:
                printf("[%3d] MOV R%d %d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case CALL:
                printf("[%3d] CALL %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case RET:
                printf("[%3d] RET\n", i);
                i += 1;
                break;
            case JMP:
                printf("[%3d] JMP %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case JZ:
                printf("[%3d] JZ %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case JPOS:
                printf("[%3d] JPOS %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case JNEG:
                printf("[%3d] JNEG %d\n", i, instruction_array[i+1]);
                i += 2;
                break;
            case ADD:
                printf("[%3d] ADD R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case SUB:
                printf("[%3d] SUB R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case MUL:
                printf("[%3d] MUL R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
            case DIV:
                printf("[%3d] DIV R%d R%d\n", i, instruction_array[i+1], instruction_array[i+2]);
                i += 3;
                break;
        }
    }
}
