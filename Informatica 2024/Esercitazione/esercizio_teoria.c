#include <stdio.h>
#include <string.h>

#define N 20

int main(){
    char s[N];
    int i;
    int m;

    scanf("%s", s);
    int x = strlen(s);

    for (int i = 0; i < x; i++)
    {
        char n = s[i];
        
        for (m = i+1; m < x; m++)
        {
            if (s[m]==n)
            {
                printf("%s---%c", s, s[i]);
                return 0;
            }
            
        }
        
    }
    printf("Non trovato!");
    return 0;
}