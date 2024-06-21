#!/bin/bash

rm -f *.o
rm -f a.out

clang++ main.cpp avl_methods.cpp -c
clang++ --debug main.o avl_methods.o -o exe

rm -f *.o
rm -f a.out
