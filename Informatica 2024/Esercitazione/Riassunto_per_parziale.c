/*--------------------------------------------------------------------------------------------------------------------------------
Riassunto di tutti gli argomenti necessari per il parziale di laboratorio.

Questo è un documento free source, quindi sentitevi liberi di modificarlo a vostro piacere in modo che possa esservi utile anche
per i futuri esami di lab!
----------------------------------------------------------------------------------------------------------------------------------*/

// Librerie
#include <stdio.h>  // Standard input-output
#include <stdlib.h> // Standard library
#include <string.h> // String operations
#include <math.h>   // Math library
#include <time.h>   // Potrebbe essere utile per ottenere i seed per la generazione di numeri casuali

// Definizioni
#define K 100           // Questa è una costante (Per convenzione utilizziamo la lettera maiuscola!)
#define G 6.67408e-11   // Le costanti NON cambiano per tutto il programma!

/* Alcune costanti possono essere definite direttamente nella libreria! 
Ad esempio Pi greco "#define PI 3.14159265358979323846" non è necessario in quanto nella libreria math.h è già definito come
M_PI
*/

// Funzioni
void Ask_Something(int *pn) {
    printf("MESSAGGIO DI PROVA\n"); // Visualizza il messaggio scritto tra le virgolette "" sulla console del terminale
    scanf("%d", pn); // Scannerizza il valore inserito dall'utente tramite terminale e lo assegna alla variabile puntata da pn

    /* ATTENZIONE! */
    /* Nel mio caso sto usando una funzione "void" quindi la funzione non restituirà alcun valore! */
    /* Per ovviare a questo problema uso i "puntatori" ovvero gli indirizzi delle allocazioni di memoria! In questo caso sto
    dicendo al programma di salvare l'input immesso dall'utente all'interno dell'indirizzo di memoria puntato dal
    puntatore pn. Se non dovessi usare i puntatori la dicitura di scanf diventa:

    scanf("%d", &n);
    */

    /* ATTENZIONE! */
    /* È necessario ricordarsi di inserire il metodo di conversione corretto per il tipo di variabile richiesta!
    
    Tipo di Variabile             Tipo di Convertitore
    int                           %d
    unsigned int                  %u
    short int                     %hd
    unsigned short                %hu
    long int                      %ld
    unsigned long                 %lu
    long long int                 %lld
    unsigned long long            %llu
    float                         %f
    double                        %lf
    long double                   %Lf
    char                          %c  ATTENZIONE! È necessario che venga inserito uno spazio prima del tipo di convertitore!
    char[] (stringa)              %s
    void* (puntatore generico)    %p
    
    */
}

// Funzione per scrivere su un file
void Write_To_File(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w"); // Apri il file in modalità scrittura
    if (file == NULL) {
        printf("Errore nell'apertura del file %s\n", filename);
        return;
    }

    fprintf(file, "%s\n", content); // Scrivi il contenuto nel file
    fclose(file); // Chiudi il file
    printf("Contenuto scritto su %s\n", filename);
}

// Funzione per leggere da un file
void Read_From_File(const char *filename) {
    FILE *file = fopen(filename, "r"); // Apri il file in modalità lettura
    if (file == NULL) {
        printf("Errore nell'apertura del file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); // Stampa ogni linea del file
    }
    fclose(file); // Chiudi il file
}

// Esempio di utilizzo di malloc e free
void Dynamic_Memory_Example() {
    int *arr = (int*)malloc(K * sizeof(int)); // Alloca memoria per un array di interi
    if (arr == NULL) {
        printf("Errore nell'allocazione della memoria\n");
        return;
    }

    for (int i = 0; i < K; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < K; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Libera la memoria allocata
}

// Funzione per generare un numero randomico in un intervallo
int Random_Number(int min, int max) {
    int intervallo = max -min; // Calcola l'intervallo tra min e max
    ((double)rand() / (double)RAND_MAX) * intervallo + min; // Genera un numero casuale tra min e max inclusi
}

// Funzione per riempire un array con numeri randomici in un intervallo
void Fill_Array_With_Random_Numbers(int *array, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        array[i] = Random_Number(min, max);
    }
}

// Funzione per calcolare il seno
double Calculate_Sine(double angle) {
    return sin(angle); // Calcola il seno dell'angolo in radianti
}

// Funzione per calcolare il coseno
double Calculate_Cosine(double angle) {
    return cos(angle); // Calcola il coseno dell'angolo in radianti
}

// Funzione per calcolare la potenza
double Calculate_Power(double base, double exponent) {
    return pow(base, exponent); // Calcola base^esponente
}

//Questo è un esempio di come utilizzare un ciclo for annidato
void Nested_For_Loop() {
    //Immaginiamo di voler stampare una tavola pitagorica fino al 10

    for (int i = 1; i <= 10; i++) { //Ciclo esterno
        for (int j = 1; j <= 10; j++) { //Cilo interno
            printf("%3d ", i * j);
        }
        printf("\n");
    }
}

//Funzione per verificare ed eseguire un file Gnuplot
void Gnuplot(){
    int error;
    error = system("ls scr.gp"); //Verifica il valore restituito dal terminale
    if (error!=0)
    {
        printf("Script per l'esecuzione di gnuplot non trovato! \n");
        exit(0); //Uscita con errore!
    } else {
        printf("Visualizzazione del risultato… \n");
        system("gnuplot < scr.gp"); //Esegue il comando tra "" nel terminale
    }
}

// Main - Il programma principale
int main() {
    // Inizializzazione del generatore di numeri casuali
    srand(time(NULL)); // Imposta il seme per la generazione di numeri casuali usando il tempo corrente

    int n;           // Variabile di tipo integer -> È un numero INTERO
    float f;         // Variabile di tipo float -> È un numero "con la virgola"
    double d;        // Variabile di tipo double -> È un numero "con la virgola" che occupa più spazio
    char c;          // Variabile di tipo character -> È un carattere
    char s[100];     // Stringa -> È un array di caratteri
    double k[K];     // Array riempibile con valori di tipo Double

    // Esempio di utilizzo della funzione Ask_Something
    Ask_Something(&n);
    printf("Il valore inserito è: %d\n", n);

    // Esempi di scanf per altri tipi di variabili
    printf("Inserisci un float: ");
    scanf("%f", &f);
    printf("Hai inserito il float: %f\n", f);

    printf("Inserisci un double: ");
    scanf("%lf", &d);
    printf("Hai inserito il double: %lf\n", d);

    printf("Inserisci un carattere: ");
    scanf(" %c", &c);  // Nota lo spazio prima di %c
    printf("Hai inserito il carattere: %c\n", c);

    printf("Inserisci una stringa: ");
    scanf("%s", s);
    printf("Hai inserito la stringa: %s\n", s);

    // Esempio di utilizzo della funzione Write_To_File
    Write_To_File("output.txt", "Questo è un esempio di contenuto scritto su un file.");

    // Esempio di utilizzo della funzione Read_From_File
    printf("Contenuto del file output.txt:\n");
    Read_From_File("output.txt");

    // Esempio di utilizzo di malloc e free
    Dynamic_Memory_Example();

    // Esempio di generazione di un numero randomico in un intervallo
    int min = 1, max = 100;
    int random_number = Random_Number(min, max);
    printf("Numero randomico generato tra %d e %d: %d\n", min, max, random_number);

    // Esempio di riempimento di un array con numeri randomici
    int arr[K];
    Fill_Array_With_Random_Numbers(arr, K, min, max);
    printf("Array riempito con numeri randomici tra %d e %d:\n", min, max);
    for (int i = 0; i < K; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Esempi di utilizzo delle funzioni matematiche
    double number = 25.0;
    printf("La radice quadrata di %.2f è: %.2f\n", number, Calculate_Square_Root(number));

    double angle = M_PI / 4; // 45 gradi in radianti
    printf("Il seno di %.2f radianti è: %.2f\n", angle, Calculate_Sine(angle));
    printf("Il coseno di %.2f radianti è: %.2f\n", angle, Calculate_Cosine(angle));

    double base = 2.0, exponent = 3.0;
    printf("%.2f elevato alla potenza %.2f è: %.2f\n", base, exponent, Calculate_Power(base, exponent));

    Nested_For_Loop();

    Gnuplot();

    /* Come si può osservare le funzioni possono essere richiamate più volte all'interno del programma principale,
    anche con parametri diversi */

    return 0; // Termina il programma con successo
}
