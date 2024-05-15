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

char pop(stack *st){
    if(st->top == -1)
        return 'n';
    else{
        char x = st->arr[st->top];
        st->top--;
        return x;
    }
}


int isBalance(char *exp){
    stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.arr = (char *)malloc(sizeof(char)*st.size);

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(&st, exp[i]);
        
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            char x = pop(&st);
            if(x=='n')
                return 0;
            else if(x == '(' && exp[i] == ')')
                continue;
            else if(x == '{' && exp[i] == '}')
                continue;
            else if(x == '[' && exp[i] == ']')
                continue;
            else
                return 0;
        }
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