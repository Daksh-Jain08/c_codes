#!/bin/bash

if [[ "$#" -ne 1 ]]; then
    echo "Usage: ./script.sh 1 for basic version and ./script.sh 2 for improved version and ./script.sh 3 for evaluating an infix expression"
    return 1;
fi

if [[ "$1" == "1" ]]; then
    rm -f *.o
    rm -f a.out

    gcc array_main.c -c
    gcc array_methods.c -c
    gcc array_main.o array_methods.o

    ./a.out

    rm -f a.out
    rm -f *.o

fi