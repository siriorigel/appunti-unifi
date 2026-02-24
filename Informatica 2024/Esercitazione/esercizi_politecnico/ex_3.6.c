#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float a, b, c;
    
    // Input delle tre dimensioni dei lati in cm
    printf("Inserisci le tre dimensioni dei lati in cm: ");
    scanf("%f %f %f", &a, &b, &c);

    // Verifica se il triangolo è equilatero
    if (a == b && b == c) {
        printf("Il triangolo è equilatero \n");
    } 
    // Verifica se il triangolo è isoscele
    else if (a == b || a == c || b == c) {
        printf("Il triangolo è isoscele \n");        
    } 
    // Se non è equilatero né isoscele, è scaleno
    else {
        printf("Il triangolo è scaleno \n");        
    } 

    // Verifica se il triangolo è rettangolo
    if (pow(a, 2) == pow(b, 2) + pow(c, 2) || 
        pow(b, 2) == pow(a, 2) + pow(c, 2) || 
        pow(c, 2) == pow(a, 2) + pow(b, 2)) {
        printf("Il triangolo è rettangolo \n"); 
    } else {
        printf("Il triangolo non è rettangolo \n");
    }
    
    return 0;
}
