#!/bin/bash

rm -f *.o
rm -f a.out

gcc stack_ll.c -c
gcc stack_ll_methods.c -c
gcc stack_ll.o stack_ll_methods.o

./a.out

rm -f *.o
rm -f a.out