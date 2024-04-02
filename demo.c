#include<stdio.h>

int main(){
    int d = 1;
    d = 2 + d++;
    printf("%d\n", d);
    return 0;
}