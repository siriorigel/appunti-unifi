#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float a, b, x;

    printf("Inserisci i parametri a e b dell'equazione nella forma ax+b=0: \n");
    scanf("%f %f", &a, &b);

    if (fabs(a) < 0.0001) { // Gestisce il caso in cui 'a' è molto vicino a zero
        printf("L'equazione non è risolvibile o ha molte soluzioni.\n");
    } else {
        x = -b / a;
        printf("La soluzione all'equazione inserita è x = %.2f !\n", x);
    }

    return 0;
}
