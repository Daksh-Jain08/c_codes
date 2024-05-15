#!/bin/bash

if [[ "$#" -ne 1 ]]; then
    echo "Usage: ./script.sh 1 for basic version and ./script.sh for improved version"
    return 1;
fi

if [[ "$1" == "1" ]]; then
    rm -f *.o
    rm -f a.out

    gcc conversion/infix_to_postfix.c -c
    gcc conversion/methods.c -c
    gcc infix_to_postfix.o methods.o

    ./a.out

    rm -f a.out
    rm -f *.o

elif [[ "$1" == "2" ]]; then
    rm -f *.o
    rm -f a.out

    gcc conversion/improved_infix_to_postfix.c -c
    gcc conversion/methods.c -c
    gcc improved_infix_to_postfix.o methods.o

    ./a.out

    rm -f a.out
    rm -f *.o

elif [[ "$1" == "3" ]]; then
    rm -f *.o
    rm -f a.out

    gcc evaluation/evaluate_main.c -c
    gcc evaluation/evaluate_methods.c -c
    gcc conversion/methods.c -c
    gcc ../stack_array_methods.c -c
    gcc evaluate_main.o evaluate_methods.o methods.o stack_array_methods.o -lm

    ./a.out

    rm -f a.out
    rm -f *.o

else
    echo "Please pass 1 or 2 as the argument!!"
fi