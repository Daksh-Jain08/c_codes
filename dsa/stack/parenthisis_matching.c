#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    char *arr;
    int size;
    int top;
} stack;

void push(stack *st, char ele){
    if(st->top>=st->size)
        printf("Stack Overflow!!\n");
    
    else{
        st->top++;
        st->arr[st->top] = ele;
    }
}

int pop(stack *st){
    if(st->top == -1)
        return 0;
    else{
        st->top--;
        return 1;
    }
}


int isBalance(char *exp){
    stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.arr = (char *)malloc(sizeof(char)*st.size);

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i]=='(')
            push(&st, exp[i]);
        
        if(exp[i]==')')
            if(!pop(&st))
                return 0;
    }

    if(st.top == -1)
        return 1;

    return 0;
}

int main(){
    char exp[1024];
    printf("Enter the expression to be checked: ");
    fgets(exp, 1024, stdin);
    if(isBalance(exp))
        printf("The number of parenthisis is balanced.\n");
    else
        printf("The number of parenthisis is not balanced.\n");
    return 0;
}