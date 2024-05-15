#include "stack_array.h"
#include<stdio.h>
#include<stdlib.h>

void create_stack(int size, stack *st){
    st->top = -1;
    st->arr = (int *)malloc(sizeof(int)*size);
    st->size = size;
}

int isEmpty(stack st){
    if(st.top==-1)
        return 1;
    return 0;
}

void display(stack st){
    if(st.top<0)
        printf("The stack is empty!!\n");
    for(int i = st.top; i>=0; i--){
        printf("%d,", st.arr[i]);
    }
    printf("\n");
}

void push(stack *st, int ele){
    if(st->top>st->size-1){
        printf("Stack Overflow!!\n");
        return;
    }
    st->top++;
    st->arr[st->top]=ele;
}

int pop(stack *st){
    int x = -1;
    if(st->top == -1){
        printf("Stack Underflow!!\n");
        return x;
    }
    x = st->arr[st->top];
    st->arr[st->top] = 0;
    st->top--;
    return x;
}

int peek(stack st, int pos){
    int x = -1;
    if(st.top-pos+1<0 || pos>st.top){
        printf("Invalid Position!!\n");
        return x;
    }
    x = st.arr[st.top-pos+1];
    return x;
}

int stackTop(stack st){
    int x = -1;
    if(st.top == -1){
        printf("The Stack is empty!\n");
        return x;
    }
    x = st.arr[st.top];
    return x;
}

int isFull(stack st){
    if(st.top==st.size-1)
        return 1;
    return 0;
}