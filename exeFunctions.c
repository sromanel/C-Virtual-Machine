#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CVM.h"

void display(int record[], int reg_number){
    printf("R%d = %d\n", reg_number, record[reg_number]);
}

void print_stack(int stack[], unsigned int sp, unsigned int n){
    while (sp >= n){
        printf("STACK [%3d] %d\n", sp - 1, stack[sp - 1]);
        sp -= 1;
    }
}

void push(int const record[], unsigned int *sp, int reg_number, int stack[]){
    stack[*sp] = record[reg_number];
    *sp += 1;
}

void pop(int record[], unsigned int *sp, int reg_number, int const stack[]){
    *sp -= 1;
    record[reg_number] = stack[*sp];
}

void mov(int record[], int reg_number, int value){
    record[reg_number] = value;
}

unsigned int call(unsigned int ip, int new_position, unsigned int *sp, int stack[]){
    stack[*sp] = ip + 2;
    *sp += 1;
    return new_position;
}

unsigned int ret(unsigned int *sp, int stack[]){
    *sp -= 1;
    return stack[*sp];
}

unsigned int jmp(unsigned int ip, int new_position){
    ip = new_position;
    return ip;
}

void jz(unsigned int *ip, unsigned int *sp, int const stack[], int newPosition){
    if(stack[*sp - 1] == 0){
        *ip = newPosition;
    }   else {
        *ip += 2;
    }

    *sp -= 1;
}

void jpos(unsigned int *ip, unsigned int *sp, int const stack[], int newPosition){
    if(stack[*sp - 1] > 0){
        *ip = newPosition;
    }   else {
        *ip += 2;
    }

    *sp -= 1;
}

void jneg(unsigned int *ip, unsigned int *sp, int const stack[], int newPosition){
    if(stack[*sp - 1] < 0){
        *ip = newPosition;
    }   else {
        *ip += 2;
    }

    *sp -= 1;
}

void add(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((record[reg1] > INT_MAX - record[reg2]) || (record[reg1] < INT_MIN - record[reg2])){
        printf("Program termination due to overflow in ADD.\n");
        exit(1);
    }   else {
        stack[*sp] = record[reg1] + record[reg2];
        *sp += 1;
    }
}

void sub(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((record[reg1] > (INT_MAX + record[reg2])) || (record[reg1] < (INT_MIN + record[reg2]))){
        printf("Program termination due to overflow in SUB.\n");
        exit(1);
    }   else {
        stack[*sp] = record[reg1] - record[reg2];
        *sp += 1;
    }
}

void mul(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((record[reg1] == 0) || (record[reg2] == 0)){
        stack[*sp] = 0;
        *sp += 1;
    }   else {
        if ((record[reg1] > (INT_MAX / record[reg2])) || (record[reg1] < (INT_MIN / record[reg2]))){
            printf("Program termination due to overflow in MUL.\n");
            exit(1);
        }   else {
            stack[*sp] = record[reg1] * record[reg2];
            *sp += 1;
        }
    }
}

void divi(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if(record[reg2] != 0){
        if(record[reg1] == INT_MIN && record[reg2] == -1){
            printf("Program termination due to overflow in DIV.\n");
            exit(1);
        }   else {
            stack[*sp] = record[reg1] / record[reg2];
            *sp += 1;
        }

    }   else {
        printf("Error: Division by zero.\n");
        exit(1);
    }
}

void exeFunctions(int instruction_array[], unsigned int array_size, unsigned int ip, int stack[], int record[], unsigned int sp){

    while(instruction_array[ip] != HALT && ip < array_size){

        switch (instruction_array[ip]){

            case DISPLAY:
                display(record, instruction_array[ip + 1]);
                ip += 2;
                break;
            case PRINT_STACK:
                print_stack(stack, sp, instruction_array[ip+1]);
                ip += 2;
                break;
            case PUSH:
                push(record, &sp,instruction_array[ip+1], stack);
                ip += 2;
                break;
            case POP:
                pop(record, &sp, instruction_array[ip+1], stack);
                ip += 2;
                break;
            case MOV:
                mov(record, instruction_array[ip+1], instruction_array[ip+2]);
                ip += 3;
                break;
            case CALL:
                ip = call(ip, instruction_array[ip+1], &sp, stack);
                break;
            case RET:
                ip = ret(&sp, stack);
                break;
            case JMP:
                ip = jmp(ip, instruction_array[ip + 1]);
                break;
            case JZ:
                jz(&ip, &sp, stack, instruction_array[ip+1]);
                break;
            case JPOS:
                jpos(&ip, &sp, stack, instruction_array[ip+1]);
                break;
            case JNEG:
                jneg(&ip, &sp, stack, instruction_array[ip+1]);
                break;
            case ADD:
                add(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
            case SUB:
                sub(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
            case MUL:
                mul(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
            case DIV:
                divi(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
        }
    }
}
