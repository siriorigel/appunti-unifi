#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//RANDOM WALK FORMICA

void richiedi_lato(int *L){
    do {
        printf("inserisci il valore intero di L tale che sia maggiore di 2 e minore di 200 compresi\n");
        scanf("%d", L);
    } while(*L<2 || *L>200);
}
void genera_posizione_formica(int l, int *x, int *y){
    /* questo se volevo tutte le posizionid i partenza possibili
    x=(int * )calloc(l, sizeof(int));
    y=(int * )calloc(l, sizeof(int));
    do{
        x[i]=((double)rand()/(double)(RAND_MAX))*(l-1) +1;
        y[i]=(((double)rand()/(double)(RAND_MAX))*(l -1) +1;
      i++;
            printf("le posizoni di partenza sono x:%d y:%d", x[i], y[i]);
        }while(x[i]==l & y[i]==l);
        */
    *x=(rand() % l)+1;
    *y=(rand() % l)+1;
}

void muovi_formica(int *x, int *y, int l){
    int check = 0;
    while(check == 0) {
        int direzione = (rand()%4);
        if(direzione == 0){
            *x += 1;
            if(*x > l) {
                check = 0; 
                *x -= 1;
            } else {
                check = 1;
            }
            printf("la formica si muove avanti sulle x di 1\n");
            printf("è in posizione x:%d e y:%d", *x, *y);
        } else if(direzione == 1){
            *x -= 1;
            if(*x == 0) {
                check = 0;
                *x += 1;
            } else {
                check = 1;
            }
            printf("la formica si muove indietro sulle x di 1\n");
            printf("è in posizione x:%d e y:%d", *x, *y);
        } else if(direzione == 2){
            *y += 1;
            if(*y > l) {
                check = 0; 
                *y -= 1;
            } else {
                check = 1;
            }
            printf("la formica si muove in su sulle y di 1\n");
            printf("è in posizione x:%d e y:%d", *x, *y);
        } else {
            *y -= 1;
            if(*y == 0) {
                check = 0;
                *y += 1;
            } else {
                check = 1;
            }
            printf("la formica si muove in giu sulle y di 1\n");
            printf("è in posizione x:%d e y:%d", *x, *y);
        }
    }
}

int main(){
    int l, x, y;
    richiedi_lato(&l);
    srand(time(NULL));
    genera_posizione_formica(l, &x, &y);
    FILE *pos = fopen("formiche.dat", "w");
    if(x!=l && y!=l){
        printf("all'inizio la formica si trova nella posizione x:%d e y:%d\n", x, y);
        while((x>=0 && x<=l) && (y>=0 && y<=l)){
            muovi_formica(&x, &y, l);
            fprintf(pos, "%d %d\n", x, y);
            if(x==l && y==l){
                printf("la formica è arrivata al traguardo");
                break;
            }    
        }
        printf("la formica si torva in posizione x:%d, y:%d", x, y);
    } else printf("la formica è già al traguardo");
    fclose(pos);
    system("gnuplot -p < formiche.gp");
    return 0;
}