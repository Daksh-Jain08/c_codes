#include"infix_to_postfix.h"
#include"../stack_array.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    char infix[] = "5+3*4-6/3";
    char *ans = postfix(infix);
    for(int i = 0; ans[i]!='\0'; i++){
        printf("%c,", ans[i]);
    }
    printf("\n");

    int answer = evaluate(ans);
    printf("%d\n", answer);
    return 0;
}