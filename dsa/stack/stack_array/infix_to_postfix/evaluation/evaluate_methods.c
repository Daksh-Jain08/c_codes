#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"../stack_array.h"
#include"infix_to_postfix.h"

int evaluate(char *postfix){
    stack st;
    create_stack(strlen(postfix)+1, &st);

    int i = 0;
    while(postfix[i]!='\0'){
        if(!is_operator(postfix[i]))
            push(&st, postfix[i++]-'0');  // converting the '5' to 5 by subtracting the ascii value of '0' from the ascii value of the digit
        else{
            char b = pop(&st);
            char a = pop(&st);
            switch(postfix[i++]){
                case '+':
                    push(&st, a+b);
                    break;
                
                case '-':
                    push(&st, a-b);
                    break;
                
                case '*':
                    push(&st, a*b);
                    break;
                
                case '/':
                    push(&st, a/b);
                    break;
                
                case '^':
                    push(&st, pow(a,b));
                    break;
            }
        }
    }

    return pop(&st);
}