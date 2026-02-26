/*Definire una funzione che crei una persona e ne restituisca il puntatore,
in base alla seguente dichiarazione:
struct persona* newPersona(int eta, char *nome );
Scrivere una funzione stampa_maggiorenni, tale che:
prenda in input la testa della lista e una soglia S della maggiore età
renda il numero di persone maggiorenni
stampi il nome di ogni persona maggiorenne (seguito da 'a capo')
Se la lista è vuota -> stampi la scritta "Nessuna Persona nella lista!" (a capo)
Supponiamo che la lista abbia le seguenti perone: Lucia (8 anni), Mario (23),
Luca (18), Massimo (2), Sandra (28)-> la funzione  stampa_maggiorenni
restituirà 3 e stamperà i seguenti nomi:
Mario
Luca
Sandra */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {
    char *nome;
    int eta;
    struct persona *next; // Corretto da 'elemento' a 'persona' per coerenza
};

// Funzione per creare una nuova persona
struct persona* newPersona(int eta, char *nome) {
    struct persona *nuova = (struct persona *)malloc(sizeof(struct persona));
    if (nuova == NULL) return NULL;

    // Alloco memoria per il nome e lo copio
    nuova->nome = nome;
    //nuova->nome = (char *)malloc(strlen(nome) + 1);
    // if (nuova->nome != NULL) {
    //     strcpy(nuova->nome, nome);
    // }

    nuova->eta = eta;
    nuova->next = NULL; // Inizializzo il puntatore al prossimo nodo

    return nuova;
}

// Funzione per stampare i maggiorenni e contarli
int stampa_maggiorenni(struct persona *p, int S) {
    // Gestione lista vuota
    if (p == NULL) {
        printf("Nessuna Persona nella lista!\n");
        return 0;
    }

    int contatore = 0;
    struct persona *corrente = p; // Puntatore di appoggio per scorrere la lista

    while (corrente != NULL) {
        if (corrente->eta >= S) {
            printf("%s\n", corrente->nome);
            contatore++;
        }
        corrente = corrente->next; // Passa al nodo successivo
    }

    return contatore;
}

int main() {
    struct persona* p = newPersona(20, "Pipps");
    stampa_maggiorenni(p, 18);
    return 0;
}