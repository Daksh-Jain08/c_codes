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
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='^')
        return 1;
    else
        return 0;
}

int precedence(char c, int inside_stack){
    /* the following operators can be used and there precedences are shown below:
        operator    outside_stack    inside_stack
        +,-              1                2
        *,/              3                4
        ^                5                6
        (                7                0
        )                0           never pushed

        This has been done to implement the right to left and left to right precedence of the operators
        +,-,*,/ have left to right precedence so their precedence is more inside the stack so that the one appearing before is given a higher preference
        ^,( have right to left precedence so their precedence is more outside the stack so that the one appearing later is given a higher preference
    */

    if(c=='+' || c=='-'){
        if(inside_stack)
            return 2;
        else
            return 1;
    }

    else if(c=='*' || c=='/'){
        if(inside_stack)
            return 4;
        else
            return 3;
    }
    
    else if(c=='^'){
        if(inside_stack)
            return 5;
        else
            return 6;
    }

    else if(c=='('){
        if(inside_stack)
            return 7;
        else
            return 0;
    }

    else if(c==')')
        return 0;
}

//the function that converts the infix expression to postfix expression
char* postfix(char *infix){
    stack st;
    create_stack(&st, strlen(infix)+1);   //creating a stack of required size

    char *ans = (char *)malloc((strlen(infix)+1)*sizeof(char));     //allocating the memory for the postfix expression
    int j = 0, i = 0;
    
    while(infix[i]!='\0'){
        //checking if the character is an operator
        if(is_operator(infix[i])){

            //pushing the operator into the stack if its precedence is higher than the operator at the top of the stack
            if(precedence(st.arr[st.top], 1)<precedence(infix[i], 0) && infix[i]!=')')
                push(&st, infix[i++]);
            
            //this case is only when ')' is outside and '(' is inside the stack, in this case we just remove the '(' from the stack to ensure that the bracket has
            //been evaluated
            else if(precedence(st.arr[st.top], 1)==precedence(infix[i], 0)){
                pop(&st);
                i++;
            }
            
            /*otherwise popping the top operator and adding it to the postfix exp, and doing this till the precedence of the top operator is
            not less than the current operator*/
            else
                ans[j++] = pop(&st);
        }
        //if the character is not operator, it is directly appended to the postfix exp
        else{
            ans[j++] = infix[i++];
        }
    }

    //adding the remaining operators to the postfix exp on completion of iterating through the infix exp
    while(!isEmpty(st)){
        ans[j++] = pop(&st);
    }
    ans[j] = '\0';     //adding the end of string character
    
    return ans;
}

int main(){
    char infix[] = "(a+b)*c-d/e";
    char *ans = postfix(infix);
    for(int i = 0; ans[i]!='\0'; i++){
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}