#!/bin/bash

rm -f *.o
rm -f exe

g++ main.cpp queue_methods.cpp graph_methods.cpp -c
g++ main.o queue_methods.o graph_methods.o -o exe

rm *.o
