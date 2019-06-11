#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CVM.h"

/*
 * The following instructions check if they're given acceptable (as in not out of bound) parameters
 * before proceeding with their tasks.
 */

/*
 * display() prints on terminal the value of the indicated register, preceded by the register number.
 */

void display(int reg[], int reg_number){
    if(reg_number >= 0 && reg_number < REG_SIZE){
        printf("R%d = %d\n", reg_number, reg[reg_number]);
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * print_stack() prints on terminal the content of the stack from the sp position to the n-th,
 * with n <= sp.
 */

void print_stack(int stack[], unsigned int sp, unsigned int n){
    if(sp >= n){
        while (sp >= n){
            printf("STACK [%3d] %d\n", sp - 1, stack[sp - 1]);
            sp -= 1;
        }
    }   else {
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }
}


/*
 * push() puts the content of the register in the reg_number position on the stack,
 * then increases the stack pointer by one position.
 */

void push(int const reg[], unsigned int *sp, int reg_number, int stack[]){
    if(reg_number >= 0 && reg_number < REG_SIZE && *sp < STACK_SIZE - 1){
        stack[*sp] = reg[reg_number];
        *sp += 1;
    }   else if (*sp >= STACK_SIZE - 1){
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * pop() decreases the stack pointer by one position, then puts the content of the
 * stack in the sp position into the register on the reg_number position.
 */

void pop(int reg[], unsigned int *sp, int reg_number, int const stack[]){
    if(reg_number >= 0 && reg_number < REG_SIZE && *sp > 0){
        *sp -= 1;
        reg[reg_number] = stack[*sp];
    }   else if(*sp <= 0){
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * mov() assigns to the reg_number register the value indicated in "value".
 */

void mov(int reg[], int reg_number, int value){
    if(reg_number >= 0 && reg_number < REG_SIZE){
        reg[reg_number] = value;
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * call() saves on the stack the position of the instruction following call() itself and increases the
 * stack pointer by one position, then returns the position where the instruction pointer will point to
 * after returning from the function.
 */

unsigned int call(unsigned int ip, int new_position, unsigned int *sp, int stack[], unsigned int array_size){
    if(ip < array_size - 2 && *sp < STACK_SIZE - 1){
        stack[*sp] = ip + 2;
        *sp += 1;
        return new_position;
    }   else if (*sp >= STACK_SIZE - 1){
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }   else {
        printf("Program terminated: out of bound instruction index.\n");
        exit(1);
    }
}


/*
 * ret() decrements the stack pointer by one position, then returns the value stored on the stack in that position.
 * Said value will be assigned to the instruction pointer.
 */

unsigned int ret(unsigned int *sp, int stack[]){
    if(*sp > 0){
        *sp -= 1;
        return stack[*sp];
    }   else {
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }
}


/*
 * jmp() returns the value of the  new position, which will be assigned to the instruction pointer after the function call.
 */

unsigned int jmp(int new_position, int array_size){
    if(new_position >= 0 && new_position < array_size){
        return (unsigned int)new_position;
    }   else {
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }
}


/*
 * jz() checks if the last element inserted in the stack is equal to 0. If so, it assigns to the instruction pointer a new position
 * (which is passed to the function), otherwise it increments the instruction pointer by two positions (skipping the instruction itself and its newPosition parameter).
 * In any case, it decrements the stack pointer by one position.
 */

void jz(unsigned int *ip, unsigned int *sp, int const stack[], int newPosition, unsigned int array_size){
    if (newPosition >= 0 && newPosition < (int)array_size && *sp > 0){
        if(stack[*sp - 1] == 0){
            *ip = newPosition;
        }   else if (*ip < array_size - 2){
            *ip += 2;
        }   else {
            printf("Program terminated: out of bound instruction index.\n");
            exit(1);
        }

        *sp -= 1;
    }   else if (*sp <= 0){
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }   else {
        printf("Program terminated: out of bound instruction index.\n");
        exit(1);
    }
}


/*
 * jpos() checks if the last element inserted in the stack is greater than 0. If so, it assigns to the instruction pointer a new position
 * (which is passed to the function), otherwise it increments the instruction pointer by two positions (skipping the instruction itself and its newPosition parameter).
 * In any case, it decrements the stack pointer by one position.
 */

void jpos(unsigned int *ip, unsigned int *sp, int const stack[], int newPosition, unsigned int array_size){
    if (newPosition >= 0 && newPosition < (int)array_size && *sp > 0){
        if(stack[*sp - 1] > 0){
            *ip = newPosition;
        }   else if (*ip < array_size - 2){
            *ip += 2;
        }   else {
            printf("Program terminated: out of bound instruction index.\n");
            exit(1);
        }

        *sp -= 1;
    }   else if (*sp <= 0){
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }   else {
        printf("Program terminated: out of bound instruction index.\n");
        exit(1);
    }
}


/*
 * jneg() checks if the last element inserted in the stack is less than 0. If so, it assigns to the instruction pointer a new position
 * (which is passed to the function), otherwise it increments the instruction pointer by two positions (skipping the instruction itself and its newPosition parameter).
 * In any case, it decrements the stack pointer by one position.
 */

void jneg(unsigned int *ip, unsigned int *sp, int const stack[], int newPosition, unsigned int array_size){
    if (newPosition >= 0 && newPosition < (int)array_size && *sp > 0){
        if(stack[*sp - 1] < 0){
            *ip = newPosition;
        }   else if (*ip < array_size - 2){
            *ip += 2;
        }   else {
            printf("Program terminated: out of bound instruction index.\n");
            exit(1);
        }

        *sp -= 1;
    }   else if (*sp <= 0){
        printf("Program terminated: out of bound stack index.\n");
        exit(1);
    }   else {
        printf("Program terminated: out of bound instruction index.\n");
        exit(1);
    }
}


/*
 * add() takes the content of the reg1 and reg2 registers, sums them, stores them in the stack and increases the stack pointer by one position.
 * However, it only does so if the sum doesn't produce any overflow, in which case it prints a message relative to the error then quits the program.
 */

void add(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if (reg1 >= 0 && reg2 >= 0 && reg1 < REG_SIZE && reg2 < REG_SIZE){
        long result = 0;
        result = (long)reg[reg1] + (long)reg[reg2];
        if (result > INT_MAX || result < INT_MIN){
            printf("Program termination due to overflow in ADD.\n");
            exit(1);
        }   else if (*sp < STACK_SIZE - 1){
            stack[*sp] = (int)result;
            *sp += 1;
        }   else {
            printf("Program terminated: out of bound stack index.\n");
            exit(1);
        }
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * sub() takes the content of the reg1 and reg2 registers, subtracts the content of the register reg2 from reg1,
 * stores the result of the operation in the stack and increases the stack pointer by one position.
 * However, it only does so if the subtraction doesn't produce any overflow,
 * in which case it prints a message relative to the error then quits the program.
 */

void sub(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if(reg1 >= 0 && reg2 >= 0 && reg1 < REG_SIZE && reg2 < REG_SIZE){
        long result = 0;
        result = (long)reg[reg1] - (long)reg[reg2];
        if (result > INT_MAX || result < INT_MIN){
            printf("Program termination due to overflow in SUB.\n");
            exit(1);
        }   else if(*sp < STACK_SIZE - 1){
            stack[*sp] = (int)result;
            *sp += 1;
        }   else {
            printf("Program terminated: out of bound stack index.\n");
            exit(1);
        }
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * mul() takes the content of the reg1 and reg2 registers, multiplies them,
 * stores the result of the operation in the stack and increases the stack pointer by one position.
 * However, it only does so if the multiplication doesn't produce any overflow,
 * in which case it prints a message relative to the error then quits the program.
 */

void mul(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if(reg1 >= 0 && reg2 >= 0 && reg1 < REG_SIZE && reg2 < REG_SIZE){
        long result = 0;
        result = (long)reg[reg1] * (long)reg[reg2];

        if (result > INT_MAX || result < INT_MIN){
            printf("Program termination due to overflow in MUL.\n");
            exit(1);
        }   else if (*sp < STACK_SIZE - 1){
            stack[*sp] = (int)result;
            *sp += 1;
        }   else {
            printf("Program terminated: out of bound stack index.\n");
            exit(1);
        }
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * divi() takes the content of the reg1 and reg2 registers, divides the content of the register reg1 by reg2,
 * stores the result of the operation in the stack and increases the stack pointer by one position.
 * However, it only does so if the division doesn't produce any overflow,
 * in which case it prints a message relative to the error then quits the program. This behaviour only occurs
 * if the dividend is equal to INT_MAX and the divisor is equal to -1: when dividing two numbers with no decimal value(which is
 * our case since an int can't have values between 0 and 1) the result will surely have a smaller absolute value than the dividend.
 * The only instance in which an overflow may occur is when the dividend takes the value of INT_MIN (which is -2147483648) and
 * the divisor is -1: this would lead to the result of +2147483648, which is equal to INT_MAX (+2147483647) plus 1, therefore out of the upper integer bound.
 * Moreover, the function checks at its beginning if the divisor is 0, in which case it prints an error on the terminal and quits the program.
 */

void divi(int const reg[], int reg1, int reg2, unsigned int *sp, int stack[]){
    if(reg1 >= 0 && reg2 >= 0 && reg1 < REG_SIZE && reg2 < REG_SIZE){
        if(reg[reg2] != 0){
            if(reg[reg1] == INT_MIN && reg[reg2] == -1){
                printf("Program termination due to overflow in DIV.\n");
                exit(1);
            }   else if (*sp < STACK_SIZE - 1){
                stack[*sp] = reg[reg1] / reg[reg2];
                *sp += 1;
            }   else {
                printf("Program terminated: out of bound stack index.\n");
                exit(1);
            }
        }   else {
            printf("Error: Division by zero.\n");
            exit(1);
        }
    }   else {
        printf("Program terminated: out of bound register index.\n");
        exit(1);
    }
}


/*
 * exeFunctions() reads the numbers stored in instruction_array using an index called ip (instruction pointer), and does so until
 * ip reaches the end of the array or the read instruction is "HALT". For every position, it reads the stored number, translates it into
 * an instruction then calls the instruction associated to said number, passing to it parameters stored after the position of the instruction itself, if expected.
 * Each of these functions will change the values of the various pointers and array elements.
 */

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
                ip = call(ip, instruction_array[ip+1], &sp, stack, array_size);
                break;
            case RET:
                ip = ret(&sp, stack);
                break;
            case JMP:
                ip = jmp(instruction_array[ip + 1], array_size);
                break;
            case JZ:
                jz(&ip, &sp, stack, instruction_array[ip+1], array_size);
                break;
            case JPOS:
                jpos(&ip, &sp, stack, instruction_array[ip+1], array_size);
                break;
            case JNEG:
                jneg(&ip, &sp, stack, instruction_array[ip+1], array_size);
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
            default:
                printf("Command not found.\n");
                exit(1);
        }
    }
}
