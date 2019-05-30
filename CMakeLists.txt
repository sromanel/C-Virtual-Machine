cmake_minimum_required(VERSION 3.14)
project(C_Virtual_Machine C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Virtual_Machine main.c prntFunction.c CVM.h toArray.c execute.c exeFunctions.c print.c)