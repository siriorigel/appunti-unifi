#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 20

int main(){
    char ordine[N], parola1[N], parola2[N], parola3[N];
    int x,y,z;

    printf("Inserisci 3 parole \n");
    scanf("%s %s %s", parola1, parola2, parola3);

    x = strcmp(parola1, parola2);
    y = strcmp(parola2, parola3);
    z = strcmp(parola1, parola3);

    printf("%d %d %d \n", x,y,z);

    if (x<y && y<z)
    {
        printf("%s \n%s\n%s \n", parola3, parola2, parola1);
    } else if (y>z && z>x)
    {
        printf("%s \n%s\n%s \n", parola2, parola3, parola1);
    } else if (x > y && y>z)
    {
        printf("%s \n%s\n%s \n", parola1, parola2, parola3);

    }
    
    
    
}   