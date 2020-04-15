#!/bin/bash

echo "Enter the name of your library to compile it (without .c extension or lib in front):"

read -r library
echo "Compiling the library..."
gcc -Wall -O3 -pedantic -c -o lib${library}.o lib${library}.c

echo "Compiling main function..."
gcc -Wall -O3 -pedantic -c main.c -o main.o

echo "Archiving the library..."
ar rcs lib${library}.a lib${library}.o

echo "Compiling the program..."
gcc -Wall -O3 -pedantic -o main.x main.o -L. -l${library}
./main.x
echo "\n Don't forget to check if you have errors"
