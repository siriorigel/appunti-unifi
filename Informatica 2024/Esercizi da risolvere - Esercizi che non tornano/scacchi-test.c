#include <stdio.h>

// Definizione delle costanti per i pezzi degli scacchi
#define BIANCO 'W'
#define NERO 'B'

// Struttura per rappresentare una posizione sulla scacchiera
typedef struct {
    int riga;
    int colonna;
} Posizione;

// Funzione per stampare la scacchiera
void stampaScacchiera(char scacchiera[8][8]) {
    printf("\n");
    for (int riga = 0; riga < 8; riga++) {
        for (int colonna = 0; colonna < 8; colonna++) {
            printf("%c ", scacchiera[riga][colonna]);
        }
        printf("\n");
    }
    printf("\n");
}

// Funzione per eseguire una mossa dell'utente
void eseguiMossaUtente(char scacchiera[8][8], Posizione partenza, Posizione arrivo) {
    scacchiera[arrivo.riga][arrivo.colonna] = scacchiera[partenza.riga][partenza.colonna];
    scacchiera[partenza.riga][partenza.colonna] = ' ';
}

// Funzione per eseguire una mossa della macchina
void eseguiMossaMacchina(char scacchiera[8][8]) {
    // Algoritmo molto semplice: la macchina muove un pedone casuale
    Posizione partenza = {1, 0}; // Pedone nero iniziale
    Posizione arrivo = {3, 0}; // Avanzamento di due caselle
    scacchiera[arrivo.riga][arrivo.colonna] = scacchiera[partenza.riga][partenza.colonna];
    scacchiera[partenza.riga][partenza.colonna] = ' ';
}

// Funzione per valutare se c'è uno scacco matto
int scaccoMatto(char scacchiera[8][8], char colore) {
    // Algoritmo di valutazione molto semplice: controlla se il re avversario è esposto
    char reAvversario = (colore == BIANCO) ? 'k' : 'K'; // Re avversario
    int rigaRe, colonnaRe;

    // Trova la posizione del re avversario
    for (int riga = 0; riga < 8; riga++) {
        for (int colonna = 0; colonna < 8; colonna++) {
            if (scacchiera[riga][colonna] == reAvversario) {
                rigaRe = riga;
                colonnaRe = colonna;
                break;
            }
        }
    }

    // Controlla se il re avversario è minacciato da qualche pezzo dell'utente
    // In questo esempio, consideriamo minacciato il re avversario se c'è un pezzo dell'utente in una casella adiacente
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int nuovaRiga = rigaRe + dr;
            int nuovaColonna = colonnaRe + dc;
            if (nuovaRiga >= 0 && nuovaRiga < 8 && nuovaColonna >= 0 && nuovaColonna < 8) {
                if (scacchiera[nuovaRiga][nuovaColonna] != ' ' && scacchiera[nuovaRiga][nuovaColonna] != reAvversario) {
                    return 1; // Scacco matto
                }
            }
        }
    }

    return 0; // Nessuno scacco matto
}

int main() {
    // Selezione dei pezzi per l'utente
    char coloreUtente;
    printf("Scegli il colore dei tuoi pezzi (B per bianco, N per nero): ");
    scanf(" %c", &coloreUtente);

    // Inizializzazione della scacchiera
    char scacchiera[8][8];
    if (coloreUtente == BIANCO) {
        // Inizializzazione della scacchiera per giocare con i pezzi bianchi
        char disposizioneIniziale[8][8] = {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
        };
        // Copia la disposizione iniziale per i pezzi bianchi
        for (int riga = 0; riga < 8; riga++) {
            for (int colonna = 0; colonna < 8; colonna++) {
                scacchiera[riga][colonna] = disposizioneIniziale[riga][colonna];
            }
        }
    } else if (coloreUtente == NERO) {
        // Inizializzazione della scacchiera per giocare con i pezzi neri
        char disposizioneIniziale[8][8] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
        };
        // Copia la disposizione iniziale per i pezzi neri
        for (int riga = 0; riga < 8; riga++) {
            for (int colonna = 0; colonna < 8; colonna++) {
                scacchiera[riga][colonna] = disposizioneIniziale[riga][colonna];
            }
        }
    } else {
        printf("Selezione non valida.\n");
        return 1;
    }

    // Stampa iniziale della scacchiera
    stampaScacchiera(scacchiera);

    // Loop di gioco
    while (1) {
        // Turno dell'utente
        printf("Turno dell'utente.\n");
        // Codice per l'input dell'utente e l'esecuzione della mossa

        // Stampa della scacchiera dopo la mossa dell'utente
        stampaScacchiera(scacchiera);

        // Controllo per lo scacco matto
        if (scaccoMatto(scacchiera, coloreUtente)) {
            printf("Scacco matto. Hai perso!\n");
            break;
        }

        // Turno della macchina
        printf("Turno della macchina.\n");
        eseguiMossaMacchina(scacchiera);

        // Stampa della scacchiera dopo la mossa della macchina
        stampaScacchiera(scacchiera);

        // Controllo per lo scacco matto
        if (scaccoMatto(scacchiera, (coloreUtente == BIANCO) ? NERO : BIANCO)) {
            printf("Scacco matto. Hai vinto!\n");
            break;
        }
    }

    return 0;
}
