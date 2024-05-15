#!/bin/bash

rm -f *.o
rm -f a.out

gcc stack_array.c -c
gcc stack_array_methods.c -c
gcc stack_array.o stack_array_methods.o

./a.out

rm -f *.o
rm -f a.out