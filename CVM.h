#ifndef C_VIRTUAL_MACHINE_CVM_H
#define C_VIRTUAL_MACHINE_CVM_H

 /*
  * The following definitions associate the corresponding instruction to every number.
  * This makes for an easier to read code when switching cases.
  */

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

 /*
  * The following definitions define the sizes of the "reg" and "stack" arrays.
  * The former contains 32 registers, the latter 16384 integer values (one integer is 4 bytes,
  * 16384 * 4B = 64KB).
  */

#define REG_SIZE 32
#define STACK_SIZE 16384

 /*
  * Definitions of the used functions.
  */

void print(char *filename);
void prntFunction(int instruction_array[], int length);
void fillArray(FILE *in, int *instructionArray);
unsigned int getSize(FILE *in);
void exeFunctions (int instruction_array[], unsigned int array_size, unsigned int ip, int stack[], int reg[], unsigned int sp);
void execute (char *filename);


#endif
