#!/bin/bash

rm -f *.o
rm -f a.out

clang++ main.cpp bst_methods.cpp stack_methods.cpp -c
clang++ main.o bst_methods.o stack_methods.o -o exe

rm a.out
rm *.o
