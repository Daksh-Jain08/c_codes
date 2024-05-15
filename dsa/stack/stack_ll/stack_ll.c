#include "stack_ll.h"
#include <stdio.h>

int main(){
    stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);

    display(st);

    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
}