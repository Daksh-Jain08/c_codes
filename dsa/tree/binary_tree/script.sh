#!/bin/bash

gcc main.c -c
gcc queue_methods.c -c
gcc tree_methods.c -c
gcc main.o queue_methods.o tree_methods.o

./a.out

rm -f *.o
rm -f a.out