#include <stdio.h>

// Funzione per calcolare il determinante di una matrice 2x2
float determinante(float matrice[2][2]) {
    return (matrice[0][0] * matrice[1][1]) - (matrice[0][1] * matrice[1][0]);
}

int main() {
    // Dichiarazione di una matrice 2x2
    float matrice[2][2];
    
    // Inserimento degli elementi della matrice
    printf("Inserisci i valori della matrice 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matrice[i][j]);
        }
    }
    
    // Visualizzazione della matrice
    printf("Matrice inserita:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f ", matrice[i][j]);
        }
        printf("\n");
    }
    
    // Calcolo e visualizzazione del determinante
    float det = determinante(matrice);
    printf("Il determinante della matrice è: %.2f\n", det);
    
    return 0;
}
