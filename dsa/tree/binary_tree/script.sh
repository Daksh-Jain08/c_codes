#!/bin/bash

if [[ "$#" -ne 1 ]]; then
    echo "Usage: ./script.sh 1 for c program to run and ./script.sh 2 for cpp program to run."
    return 1;
fi

if [[ "$1" == "1" ]]; then
    rm -f *.o
    rm -f a.out

    gcc c/main.c c/queue_methods.c c/tree_methods.c -c
    gcc main.o queue_methods.o tree_methods.o

    ./a.out

    rm -f *.o
    rm -f a.out


elif [[ "$1" == "2" ]]; then
    rm -f *.o
    rm -f a.out

    g++ cpp/main.cpp cpp/queue_methods.cpp cpp/tree_methods.cpp -c
    g++ main.o queue_methods.o tree_methods.o

    ./a.out

    rm -f *.o
    rm -f a.out
fi