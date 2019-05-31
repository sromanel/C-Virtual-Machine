#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CVM.h"

void display(int record[], int reg_number){
    printf("R%d = %d\n", reg_number, record[reg_number]);
}

void print_stack(int stack[], unsigned int sp, unsigned int n){
    if (sp - n > 0){
        while (sp > n){
            printf("STACK [%3d] %d\n", sp - 1, stack[sp-1]);
            sp -= 1;
        }
    }   else {
        perror("Error: ");
        exit(1);
    }
}

void push(int const record[], unsigned int *sp, int reg_number, int stack[]){
    unsigned int temp = 0;
    temp = *sp;
    if(temp < 16384){
        stack[temp] = record[reg_number];
        /*printf("Ho appena pushato %d nello stack.\n", stack[temp]);*/
        *sp += 1;
    }   else {
        perror("Error: ");
        exit(1);
    }
}

void pop(int record[], unsigned int *sp, int reg_number, int const stack[]){
    int  temp = 0;
    temp = *sp;
    if (temp > 0){
        *sp -= 1;
        record[reg_number] = stack[temp-1];
        printf("Ho appena messo nel registro %d il valore %d.\n", reg_number, stack[temp - 1]);
    }   else {
        perror("Error: ");
        exit(1);
    }
}

void mov(int record[], int reg_number, int value){
    record[reg_number] = value;
}

unsigned int call(unsigned int ip, int new_position, unsigned int *sp, int stack[]){
    stack[*sp] = ip+2;
    printf("Ho appena messo nello stack la posizione %d.\n", stack[*sp]);
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
    int temp = *sp;
    if(temp > 0){
        if(stack[temp - 1] == 0){
            *ip = newPosition;
        }   else {
            *ip += 2;
        }
        *sp -= 1;
    }   else {
        perror("Error: ");
        exit(1);
    }
}

void jpos(unsigned int *ip, unsigned int *sp, int stack[], int newPosition){
    int temp = *sp;
    if(temp > 0){
        if(stack[temp-1] > 0){
            *ip = newPosition;
        }   else {
            *ip += 2;
        }
        *sp -= 1;
    }   else {
        perror("Error: ");
        exit(1);
    }
}

void jneg(unsigned int *ip, unsigned int *sp, int stack[], int newPosition){
    int temp = *sp;
    if(temp > 0){
        if(stack[temp-1] < 0){
            *ip = newPosition;
        }   else {
            *ip += 2;
        }
        *sp -= 1;
    }   else {
        perror("Error: ");
        exit(1);
    }
}

void add(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((record[reg2] > 0) && (record[reg1] > INT_MAX - record[reg2])){
        perror("Error: ");
        exit(1);
    }   else if((record[reg2] < 0) && (record[reg1] < INT_MIN - record[reg2])){
        perror("Error: ");
        exit(1);
    }   else {
        stack[*sp] = record[reg1] + record[reg2];
        *sp += 1;
        /*printf("Ho appena inserito %d nello stack.\n", stack[*sp]);*/
    }
}

void sub(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((record[reg2] > 0) && (record[reg1] > INT_MAX - record[reg2])){
        perror("Error: ");
        exit(1);
    }   else if((record[reg2] < 0) && (record[reg1] < INT_MIN - record[reg2])){
        perror("Error: ");
        exit(1);
    }   else {
        stack[*sp] = record[reg1] - record[reg2];
        *sp += 1;
        /*printf("Ho appena inserito %d nello stack.\n", stack[*sp]);*/
    }
}

void mul(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){

    stack[*sp] = record[reg1] * record[reg2];
    *sp += 1;
}

void divi(int const record[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if(record[reg2] != 0){
        stack[*sp] = record[reg1] * record[reg2];
        *sp += 1;
    }   else {
        perror("Errore: ");
        exit(1);
    }
}

void exeFunctions(int instruction_array[], unsigned int array_size, unsigned int ip, int stack[], int record[], unsigned int sp){

    while(instruction_array[ip] != HALT && ip < array_size){

        switch (instruction_array[ip]){

            case DISPLAY:
                display(record, instruction_array[ip + 1]);
                printf("Ho appena chiamato DISPLAY, ip è %d.\n", ip);
                ip += 2;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case PRINT_STACK:
                print_stack(stack, sp, instruction_array[ip+1]);
                printf("Ho appena chiamato PRINT_STACK, ip è %d.\n", ip);
                ip += 2;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case PUSH:
                push(record, &sp,instruction_array[ip+1], stack);
                printf("Ho appena chiamato PUSH, ip è %d.\n", ip);
                ip += 2;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case POP:
                pop(record, &sp, instruction_array[ip+1], stack);
                printf("Ho appena chiamato POP, ip è %d.\n", ip);
                ip += 2;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case MOV:
                mov(record, instruction_array[ip+1], instruction_array[ip+2]);
                printf("Ho appena chiamato MOV, ip è %d.\n", ip);
                ip += 3;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case CALL:
                ip = call(ip, instruction_array[ip+1], &sp, stack);
                printf("Ho appena chiamato CALL, ip è %d.\n", ip);
                /*ip += 2;*/
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case RET:
                ip = ret(&sp, stack);
                printf("Ho appena chiamato RET, ip è %d e sp è %d.\n", ip, sp);
                /*ip += 1;*/
                break;
            case JMP:
                ip = jmp(ip, instruction_array[ip + 1]);
                printf("Ho appena chiamato JMP, ip è %d.\n", ip);
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case JZ:
                jz(&ip, &sp, stack, instruction_array[ip+1]);
                printf("Ho appena chiamato JZ, ip è %d.\n", ip);
                ip += 2;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case JPOS:
                jpos(&ip, &sp, stack, instruction_array[ip+1]);
                printf("Ho appena chiamato JPOS, ip è %d.\n", ip);
                ip += 2;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case JNEG:
                jneg(&ip, &sp, stack, instruction_array[ip+1]);
                printf("Ho appena chiamato JNEG, ip è %d.\n", ip);
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case ADD:
                add(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                printf("Ho appena chiamato ADD, ip è %d.\n", ip);
                ip += 3;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case SUB:
                sub(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                printf("Ho appena chiamato SUB, ip è %d.\n", ip);
                ip += 3;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case MUL:
                mul(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                printf("Ho appena chiamato MUL, ip è %d.\n", ip);
                ip += 3;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
            case DIV:
                divi(record, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                printf("Ho appena chiamato DIV, ip è %d.\n", ip);
                ip += 3;
                printf("Ora ip è %d, sp: %d.\n", ip, sp);
                break;
        }
    }
}
