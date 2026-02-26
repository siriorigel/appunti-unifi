#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/* • il coefficiente di scattering µ>0,
* la distanza della parete assorbente d>0,
* il numero di fotoni da simulare per esperimento n, con 0 <n≤ 106
,
* il numero massimo di scattering Nmax, con Nmax ≥ 99,
* il numero di esperimenti N, con 0 <N ≤ 1000.*/
void askpar(double *mu, double *d, int *n, int *Nmax, int *N){
   do{printf("inserire il coeff di scattering (>0)\n");
    scanf("%lf", mu);
     printf("inserire la distanza della parete assorbente (>0)\n");
     scanf("%lf", d);
     printf("inserire il numero di fotoni 0<n<=106\n");
     scanf("%d",n);
     printf("inserire il numero massimo di scattering Nmax, con Nmax>=99)\n");
     scanf("%d",Nmax);
     printf("inserire il numero di esperimenti 0<N<=1000\n");
     scanf("%d", N);
   }while((*mu<0 && *d<0) || (*n<0 && *n>106) || (*Nmax<99) || (*N<0 && *N>1000 ));
}

double estraiL(double *mu){
    double L, u;
    u = ((double)rand()/(double)RAND_MAX);
    return (-log(u)/ *mu);
}

double estraiang(int i){
    double teta;
    //printf("restituisco angolo scattering\n");
    if(i==1){
        teta=0;
    }else{
    teta = ((double)rand()/(double)RAND_MAX)*2*M_PI;
    }
return teta;
}

    


int main(){
    
    double mu, d, *x, L, teta;
    int *nfotrif;
    int n, Nmax, N, cont=0;
    askpar(&mu, &d, &n, &Nmax, &N);
    nfotrif = (int *)calloc(N, sizeof(int));
    srand(time(NULL));
    
   
  
    x=(double *)calloc(Nmax, sizeof(double));
    FILE *fp;
    fp = fopen("exp.dat", "w");
    for(int b=0; b<N;b++){
        cont=0;
     for(int c=0; c<n; c++){
       for(int i=1; i<=Nmax; i++){
            L = estraiL( &mu);
            teta = estraiang(i);
            x[0]=0;
            x[i]=L*cos(teta)+x[i-1];
       
        //printf("al passo %d il fotone si trova a x:%lf\n", i+1, x[i]);
        if(x[i]<0){
            printf("il fotone è riflesso\n");
            cont++;
            break;
        }
        }
        
     printf("fotone numero%d\n", c+1);
    
    }nfotrif[b]=cont;
    printf("nell'esperimento numero %d i fotoni riflessi sono %d\n", b+1, nfotrif[b]);
    fprintf(fp, "%d\n", nfotrif[b]);
    }
  
   
    fclose(fp);
    free(nfotrif);
    free(x);
    system("gnuplot -p < fotoni.gp");
   return 0;
}