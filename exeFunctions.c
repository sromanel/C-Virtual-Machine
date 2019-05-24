#include <stdio.h>
#include <stdlib.h>
#include "CVM.h"

void display(int record[], int reg_number){
    printf("R%d = %d", reg_number, record[reg_number]);
}

void mov(int record[], int reg_number, int value){
    record[reg_number] = value;
}

void jmp(int *ip, int new_position){

}

void add(int record[], int reg1, int reg2, int *sp, int stack[]){
    int result = 0;
    result = record[reg1] + record[reg2];


}

void execute(int array_size, int *ip, int stack[], int record[], int *sp){
    int i = 0;

    while(*ip != HALT && i < array_size){
        switch (ip[i]){
            case DISPLAY:
                display(record, ip[i + 1]);
                i += 2;
                break;
            case PRINT_STACK:
                i += 2;
                break;
            case PUSH:
                i += 2;
                break;
            case POP:
                i += 2;
                break;
            case MOV:
                mov(record, ip[i+1], ip[i+1]);
                i += 3;
                break;
            case CALL:
                i += 2;
                break;
            case RET:
                i += 1;
                break;
            case JMP:

                i += 2;
                break;
            case JZ:
                i += 2;
                break;
            case JPOS:
                i += 2;
                break;
            case JNEG:
                i += 2;
                break;
            case ADD:
                i += 3;
                break;
            case SUB:
                i += 3;
                break;
            case MUL:
                i += 3;
                break;
            case DIV:
                i += 3;
                break;
        }
    }
}