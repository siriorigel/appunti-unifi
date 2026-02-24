#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100

int main(){
    char s1[N], s2[N];
    unsigned int len;

    scanf("%s", s1);

    strcpy(s2,s1);

    len = strlen(s1);

    for (int i = 0; i < len; i++)
    {
        for (int k = len-1 ; k >= 0; k--)
        {
            if (s1[i]==s2[k])
            {
                printf(" %c --- %c \n", s1[i], s2[k]);
                break;
            } else {
                printf("Le due stringhe sono diverse");
                return 0;
            }
        }
        
        
    }
    

}