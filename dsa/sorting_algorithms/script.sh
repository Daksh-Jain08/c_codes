#!/bin/bash

rm -f *.o
rm -f exe

gcc --debug main.c sortings.c -c
gcc main.o sortings.o -o exe

rm *.o
