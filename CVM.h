#ifndef C_VIRTUAL_MACHINE_CVM_H
#define C_VIRTUAL_MACHINE_CVM_H

#define HALT 0
#define DISPLAY 1
#define PRINT_STACK 2
#define PUSH 10
#define POP 11
#define MOV 12
#define CALL 20
#define RET 21
#define JMP 22
#define JZ 23
#define JPOS 24
#define JNEG 25
#define ADD 30
#define SUB 31
#define MUL 32
#define DIV 33

void Print(char *filename);
void Stampa(int instruction_array[], int length);
void fillArray(FILE *in, int *instructionArray);
unsigned int getSize(FILE *in);
void execute (int instruction_array[], unsigned int array_size, unsigned int ip, int stack[], int record[], unsigned int sp);


#endif
