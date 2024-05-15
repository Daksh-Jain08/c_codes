#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../infix_to_postfix.h"

int main(){
    char infix[] = "a+b*c-d/e";
    char *ans = postfix(infix);
    for(int i = 0; ans[i]!='\0'; i++){
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}