#!/bin/bash

rm -f exe
rm -f *.o

g++ main.cpp hashings.cpp -c
g++ main.o hashings.o -o exe

rm *.o
