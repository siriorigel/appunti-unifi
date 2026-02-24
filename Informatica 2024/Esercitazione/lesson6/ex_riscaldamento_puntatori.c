#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,c;
    int *p;

    a =2;
    b=3;

    p = &a;

    c= *p;

    printf("Il puntatore indica %d \n", c);
}