#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CVM.h"

/*
 * display() prints on terminal the value of the indicated register, preceded by the register number.
 */

void display(int reg[], int reg_number){
    printf("R%d = %d\n", reg_number, reg[reg_number]);
}


/*
 * print_stack() prints on therminal the content of the stack from the sp position to the n-th,
 * with n <= sp.
 */

void print_stack(int stack[], unsigned int sp, unsigned int n){
    while (sp >= n){
        printf("STACK [%3d] %d\n", sp - 1, stack[sp - 1]);
        sp -= 1;
    }
}


/*
 * push() puts the content of the register in the reg_number position on the stack,
 * then increases the stack pointer by one position.
 */

void push(int const reg[], unsigned int *sp, int reg_number, int stack[]){
    stack[*sp] = reg[reg_number];
    *sp += 1;
}


/*
 * pop() decreases the stack pointer by one position, then puts the content of the
 * stack in the sp position into the register on the reg_number position.
 */

void pop(int reg[], unsigned int *sp, int reg_number, int const stack[]){
    *sp -= 1;
    reg[reg_number] = stack[*sp];
}


/*
 * mov() assigns to the reg_number register the value indicated in "value".
 */

void mov(int reg[], int reg_number, int value){
    reg[reg_number] = value;
}


/*
 * call() saves on the stack the position of the instruction following call() itself and increases the
 * stack pointer by one position, then returns the position where the instruction pointer will point to
 * after returning from the function.
 */

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

void add(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((reg[reg1] > INT_MAX - reg[reg2]) || (reg[reg1] < INT_MIN - reg[reg2])){
        printf("Program termination due to overflow in ADD.\n");
        exit(1);
    }   else {
        stack[*sp] = reg[reg1] + reg[reg2];
        *sp += 1;
    }
}

void sub(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((reg[reg1] > (INT_MAX + reg[reg2])) || (reg[reg1] < (INT_MIN + reg[reg2]))){
        printf("Program termination due to overflow in SUB.\n");
        exit(1);
    }   else {
        stack[*sp] = reg[reg1] - reg[reg2];
        *sp += 1;
    }
}

void mul(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if ((reg[reg1] == 0) || (reg[reg2] == 0)){
        stack[*sp] = 0;
        *sp += 1;
    }   else {
        if ((reg[reg1] > (INT_MAX / reg[reg2])) || (reg[reg1] < (INT_MIN / reg[reg2]))){
            printf("Program termination due to overflow in MUL.\n");
            exit(1);
        }   else {
            stack[*sp] = reg[reg1] * reg[reg2];
            *sp += 1;
        }
    }
}

void divi(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if(reg[reg2] != 0){
        if(reg[reg1] == INT_MIN && reg[reg2] == -1){
            printf("Program termination due to overflow in DIV.\n");
            exit(1);
        }   else {
            stack[*sp] = reg[reg1] / reg[reg2];
            *sp += 1;
        }

    }   else {
        printf("Error: Division by zero.\n");
        exit(1);
    }
}

void exeFunctions(int instruction_array[], unsigned int array_size, unsigned int ip, int stack[], int reg[], unsigned int sp){

    while(instruction_array[ip] != HALT && ip < array_size){

        switch (instruction_array[ip]){

            case DISPLAY:
                display(reg, instruction_array[ip + 1]);
                ip += 2;
                break;
            case PRINT_STACK:
                print_stack(stack, sp, instruction_array[ip+1]);
                ip += 2;
                break;
            case PUSH:
                push(reg, &sp,instruction_array[ip+1], stack);
                ip += 2;
                break;
            case POP:
                pop(reg, &sp, instruction_array[ip+1], stack);
                ip += 2;
                break;
            case MOV:
                mov(reg, instruction_array[ip+1], instruction_array[ip+2]);
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
                add(reg, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
            case SUB:
                sub(reg, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
            case MUL:
                mul(reg, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
            case DIV:
                divi(reg, instruction_array[ip+1], instruction_array[ip+2], &sp, stack);
                ip += 3;
                break;
        }
    }
}
