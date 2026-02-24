#include <stdio.h>
#define N 10
int main() {
int A[N];//array A contenente N variabili di tipo int
int i, sum;
sum=0;
for (i = 0; i < N; i++) {//algoritmo inserimento nell’array
A[i] = (i+1)*2;
printf("Ho inserito il valore A[%d]: %d\n", i, A[i]);
}
i=0; //assegno di nuovo il valore 0 a i perché?
while (i<N) {//algoritmo calcolo somma elementi
printf("somma parziale: %d\n", sum);
sum = sum + A[i];
i = i + 1;
}
printf("Somma: %d \n", sum);
//NOTA: si poteva usare 1solo ciclo…
}