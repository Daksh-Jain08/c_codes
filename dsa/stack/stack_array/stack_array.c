#include<stdio.h>
#include "stack_array.h"

int main(){
    stack st;
    printf("Enter the size of the stack: ");
    scanf("%d", &st.size);
    create_stack(st.size, &st);
    printf("%d\n", isEmpty(st));

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    display(st);

    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    display(st);
}