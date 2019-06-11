# C-Virtual-Machine
Simple C Virtual Machine

This program takes .cvm or .txt files as input, interprets and prints or execute its functions. 
There is a dynamically allocated instructions array, a 64KB stack (16384 elements) and 32 registers stored in an array.

Usage example:
make <- this compiles the code
./VM execute example_programs/fib.cvm <- this executes the content of the file "fib.cvm", stored inside the "example_programs" folder.
