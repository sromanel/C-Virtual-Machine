#include <stdio.h>
#include <stdlib.h>
#include "CVM.h"

void display(int record[], int reg_number){
    printf("R%d = %d", reg_number, record[reg_number]);
}

int push(int record[], unsigned int sp, int reg_number, int stack[]){
    int success = 0;
    if(sp < sizeof(stack)/sizeof(int)){
        stack[sp] = record[reg_number];
        sp += 1;
        success = 1;
    }   else {
        perror("Errore: ");
    }

    return success;
}

void pop(int record[], unsigned int sp, int reg_number, int stack[]){

}

void mov(int record[], int reg_number, int value){
    record[reg_number] = value;
}

unsigned int jmp(unsigned int ip, int new_position){
    ip = new_position;
    return ip;
}

int jz(unsigned int ip[], unsigned int *sp, int stack[], int newPosition){
    int success = 0;
    int temp = *sp;
    if(sp > 0){
        if(stack[temp - 1] == 0){
            *ip = newPosition;
            *sp -= 1;
            success = 1;
        }
    }   else {
        perror("Error: ");
    }
    return success;
}

void add(int record[], int reg1, int reg2, unsigned int sp, int stack[]){
    int result = 0;
    result = record[reg1] + record[reg2];

}

void execute(int instruction_array[], unsigned int array_size, unsigned int ip, int stack[], int record[], unsigned int sp){

    while(instruction_array[ip] != HALT && ip < array_size){
        switch (instruction_array[ip]){
            case DISPLAY:
                display(record, instruction_array[ip + 1]);
                ip += 2;
                break;
            case PRINT_STACK:
                ip += 2;
                break;
            case PUSH:
                if(!push(record, sp,instruction_array[ip+1], stack))
                {
                    ip += 2;
                }
                break;
            case POP:
                ip += 2;
                break;
            case MOV:
                mov(record, instruction_array[ip+1], instruction_array[ip+2]);
                ip += 3;
                break;
            case CALL:
                ip += 2;
                break;
            case RET:
                ip += 1;
                break;
            case JMP:
                ip = jmp(ip, instruction_array[ip + 1]);
                break;
            case JZ:
                if(!jz(&ip, &sp, stack, instruction_array[ip+1])){
                    ip += 2;
                }
                break;
            case JPOS:
                ip += 2;
                break;
            case JNEG:
                ip += 2;
                break;
            case ADD:
                ip += 3;
                break;
            case SUB:
                ip += 3;
                break;
            case MUL:
                ip += 3;
                break;
            case DIV:
                ip += 3;
                break;
        }
    }
}