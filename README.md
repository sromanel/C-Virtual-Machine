# C-Virtual-Machine
Simple C Virtual Machine

This program takes .cvm or .txt files as input, interprets and prints or execute its functions. 
There is a dynamically allocated instructions array, a 64KB stack (16384 elements) and 32 registers stored in an array.

Example usage:
make <- this compiles the program using the flags defined in the Makefile file
./VM execute example_programs/fib.cvm <- this executes the instructions defined in the "fib.cvm" file, stored inside the "example_programs" folder
