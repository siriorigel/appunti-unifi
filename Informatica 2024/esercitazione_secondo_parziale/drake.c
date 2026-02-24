#include<stdio.h>
#include<math.h>
#include<stdlib.h>



// 1)
void Ask_coef(double coef[]){
int i;

do{	
printf("Scrivi il SFR (stars/yr): ");	
scanf("%lf", &coef[0]);}while(coef[0]<=0);	

for (i=1;i<6;i++){
do{	
printf("Scrivi il coefficiente numero %d: ", (i+1));	
scanf("%lf", &coef[i]);}while(coef[i]<=0 || coef[i]>1);	
}

do{	
printf("Scrivi il tempo di vita medio di una civiltà: ");	
scanf("%lf", &coef[6]);}while(coef[6]<=0);	

}
// 2)
double Drake(double coef[]){
int i; double N=1;
for (i=0;i<7;i++){
N=N*coef[i];	
}	
return N;
}

void Ask_er(double *errore){
do{	
printf("Scrivi un errore relativo:  ");
 scanf("%lf", errore);}while(*errore<0 || *errore>0.5); 	
 }

void param(double *mu, double *sq,double coef[],double errore){
int i;
*mu=0;*sq=0;
for (i=0;i<7;i++){
*mu+=log(coef[i]);
*sq=+pow(log(coef[i])*errore,2);	
}	
}	

// 4)
double lognorm(double x, double mu, double sq){
return (1./x)*(1./sqrt( 2*M_PI*sq  ) )*exp(   - pow(   log(x) - mu, 2   )/(2*sq)       );	
}

int Ask_n(){
	int n;
do{	
printf("Numero dei punti per il grafico:  ");
 scanf("%d", &n);}while(n<1000);
 return n; 	
 }


void graf(double x[], double y[], double dx, int n, double mu, double sq){
	printf("mu %lf   sigma %lf\n", mu,sq);
int i;
for (i=0;i<n;i++){
x[i]=dx*i+0.001;	
y[i]=lognorm(x[i],mu,sq);	
}	
}

// 5)
void Print(double  x[], double y[], int N, char s[]){
	FILE *p;
	p = fopen(s,"w");
	int i;
	for(i=0; i<N; i++){
			fprintf(p,"%lf\t%lf\n",x[i],y[i]);
		}
	fclose(p);	
	}

void plotWithGnuplot(const char *datafile, const char *outputfile) {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
        exit(EXIT_FAILURE);
    }
    
    fprintf(gnuplot, "set terminal pngcairo\n"); // Output in formato PNG
    fprintf(gnuplot, "set output '%s'\n", outputfile); // File di output
    fprintf(gnuplot, "set yrange [0:1]\n"); // Titolo del grafico
    fprintf(gnuplot, "plot '%s' using 1:2 with linespoints title 'Numero di Drake'\n", datafile); // Comando per tracciare il grafico
    pclose(gnuplot);
}

int main(){

// 1)
double coef[7];
Ask_coef(coef);
// 2)
double Nd=Drake(coef);
printf("Il numero di civiltà stimate nella Galassia  è: %.0lf\n", round(Nd) );
// 3)
double mu,sq;
double errore;
Ask_er(&errore);
param(&mu,&sq,coef,errore);
// 4)
int n=Ask_n();
double *N,*p;
N=(double *) calloc(n,sizeof(double));
p=(double *) calloc(n,sizeof(double));
double max=Nd*10;
double dn=max/(n+1);
printf("dn %lf\n",dn);
graf(N,p,dn,n, mu,sq);
Print(N,p,n,"drake2.dat");
system("gnuplot < drake.gp");
plotWithGnuplot("drake2.dat,")

return 0;	
	}
