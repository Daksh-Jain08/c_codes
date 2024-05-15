#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    char *arr;
    int size;
    int top;
} stack;

void create_stack(stack *st, int size){
    st->size = size;
    st->top = -1;
    st->arr = (char *)malloc(sizeof(char)*size);
}

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

int isEmpty(stack st){
    if(st.top==-1)
        return 1;
    return 0;
}

int is_operator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else
        return 0;
}

int precedence(char c){
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    
    return 0;
}

char* postfix(char *infix){
    stack st;
    create_stack(&st, strlen(infix)+1);

    char *ans = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int j = 0, i = 0;
    
    while(infix[i]!='\0'){
        if(is_operator(infix[i])){
            if(precedence(st.arr[st.top])<precedence(infix[i]))
                push(&st, infix[i++]);
            else
                ans[j++] = pop(&st);
        }
        else{
            ans[j++] = infix[i++];
        }
    }

    while(!isEmpty(st)){
        ans[j++] = pop(&st);
    }
    ans[j] = '\0';
    
    return ans;
}

int main(){
    char infix[] = "a+b*c-d/e";
    char *ans = postfix(infix);
    for(int i = 0; ans[i]!='\0'; i++){
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}