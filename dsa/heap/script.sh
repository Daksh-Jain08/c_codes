#!/bin/bash

rm -f *.o
rm -f exe

g++ heap_methods.cpp main.cpp -c
g++ heap_methods.o main.o -o exe
