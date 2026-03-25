#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// Costanti (Da inserire)
// resistenza nota per la parte preliminare
#define rho_v 0.0
#define err_rho_v 0.0
// r_0 sul banco
#define r_0 0.0
#define err_r_0_lin 0.0
#define err_r_0_sens 0.0
// epsilon 0 dato
#define epsilon_0 0.0
#define err_epsilon_0 0.0
// V1 e V2
#define v1 1.489 
#define v2 1.460
#define err_v1 0.0 
#define err_v2 0.0
// r'+ e r'-
#define r_prime_plus_galvanometro 0.0
#define n_prime_plus_galvanometro 0
#define r_prime_minus_galvanometro 0.0
#define n_prime_minus_galvanometro 0
// Errori linearità r'
#define err_r_x_prime_lin 0.0
// Multimetro
#define v_minus 0.0
#define v_plus 0.0
#define r_second_plus_multimetro 0.0 
#define r_second_minus_multimetro 0.0 
// Fase 5: calcolo di rho_x e R
#define R_2 0.0
#define v_minus_third 0.0
#define v_plus_third 0.0
#define r_third_plus_multimetro 0.0 
#define r_third_minus_multimetro 0.0 
#define err_r_x_second_lin 0.0
#define err_r_x_third_lin 0.0
// Parte 2 dell'esperienza
#define R_x 0.0 // Misura preliminare
#define R_0 0.0
#define r_c_plus 0.0
#define r_c_minus 0.0
#define v_c_minus 0.0
#define v_c_plus 0.0
#define err_r_c_lin 0.0
// Si sposta l'interrutore su R_x
#define err_r_x_prime_new_lin 0.0
#define r_prime_new_plus 0.0
#define n_prime_new_plus 0
#define r_prime_new_minus 0.0
#define n_prime_new_minus 0
// Si ricava adesso r_second_new
#define err_r_x_second_new_lin 0.0
#define r_second_new_plus 0.0
#define n_second_new_plus 0
#define r_second_new_minus 0.0
#define n_second_new_minus 0
// r_c_new
#define r_c_new_plus 0.0
#define r_c_new_minus 0.0
#define v_c_new_minus 0.0
#define v_c_new_plus 0.0
#define err_r_c_new_lin 0.0
// FIne
#define err_rho_x 0.0
#define err_R_x_prime 0.0
#define err_R_x_second 0.0

double rho_x_pre;
double rho_x;
double epsilon_x;
double epsilon_x_galvanometro;
double epsilon_x_multimetro;
double r_x_prime; 
double r_x_second; 
double r_x_third;
double r_c;
double r_x_prime_new;
double R_x_prime;
double r_x_second_new;
double R_x_second;
double r_c_new;

// Errori
double err_epsilon_x;
double err_epsilon_x_galvanometro;
double err_epsilon_x_multimetro;
double err_r_x_prime_sens; 
double err_r_x_second_sens; 
double err_r_x_third_sens; 
double err_r_c_sens;
double err_r_x_prime_new_sens;
double err_r_x_second_new_sens;
double err_r_c_new_sens;

// Funzione per calcolare rho_x e epsilon_x preliminarmente
void f_epsilon_x_preliminare();

// Funzione per calcolare epsilon_x con il galvanometro
void f_epsilon_x_galvanometro();

// Funzione per calcolare epsilon_x con il multimetro
void f_epsilon_x_multimetro();

// Calcolo di r_third
void f_r_third();

//calcolo di rho_x
void f_rho_x();

// calcoli per parte 2
void parte_2();

// Grafici
void graph();

// Funzione per scrivere i dati sui file
void write_file(FILE*);

int main() {
    FILE *results = fopen("galvanometro.dat", "w");
    FILE *plot1 = fopen("plot1.dat", "w");
    FILE *plot2 = fopen("plot2.dat", "w");
    FILE *plot3 = fopen("plot3.dat", "w");
    // Medie e scarti massimi
    f_epsilon_x_preliminare();
    f_epsilon_x_galvanometro();
    f_epsilon_x_multimetro();
    f_r_third();
    f_rho_x();
    parte_2();
    fprintf(plot1, "1 %lf 0", rho_x_pre);
    fprintf(plot1, "2 %lf %lf", rho_x, err_rho_x);
    fprintf(plot2, "1 %lf 0", epsilon_x);
    fprintf(plot2, "2 %lf %lf", epsilon_x_galvanometro, err_epsilon_x_galvanometro);
    fprintf(plot2, "3 %lf %lf", epsilon_x_multimetro, err_epsilon_x_multimetro);
    fprintf(plot3, "1 %lf %lf", rho_v, err_rho_v);
    fprintf(plot3, "2 %lf %lf", R_x_prime, err_R_x_prime);
    fprintf(plot3, "3 %lf %lf", R_x_second, err_R_x_second);
    fclose(plot1);
    fclose(plot2);
    fclose(plot3);
    graph();
    write_file(results);
    fclose(results);
}

void f_epsilon_x_preliminare() {
    rho_x_pre = rho_v * (v1 - v2) / (2* v2 - v1);
    epsilon_x = (v1 * v2) / (2*v2 - v1);
    err_epsilon_x = 0.0;
}

void f_epsilon_x_galvanometro() {
    r_x_prime = r_prime_minus_galvanometro + fabs((double)n_prime_minus_galvanometro) *
        (r_prime_plus_galvanometro - r_prime_minus_galvanometro) / ((double)n_prime_plus_galvanometro + fabs((double)n_prime_minus_galvanometro));
    err_r_x_prime_sens = fmax(fabs(r_x_prime - r_prime_plus_galvanometro), fabs(r_x_prime - r_prime_minus_galvanometro));
    epsilon_x_galvanometro = (r_x_prime *  epsilon_0 ) / r_0;
    err_epsilon_x_galvanometro = epsilon_x_galvanometro * ((err_r_0_sens / r_0) + (err_r_0_lin / r_0) +
        (err_r_x_prime_sens / r_x_prime) + (err_r_x_prime_lin / r_x_prime)  + (err_epsilon_0 / epsilon_0));
}

void f_epsilon_x_multimetro() {
    r_x_second = r_second_minus_multimetro + fabs(v_minus) *
        (r_second_plus_multimetro - r_second_minus_multimetro) / (v_plus + fabs(v_minus));
    err_r_x_second_sens = fmax(fabs(r_x_second - r_second_plus_multimetro), fabs(r_x_second - r_second_minus_multimetro));
    epsilon_x_multimetro = (r_x_second * epsilon_0) / r_0;
    err_epsilon_x_multimetro = epsilon_x_multimetro * ((err_r_0_sens / r_0) + (err_r_0_lin / r_0) +
        (err_r_x_second_sens / r_x_second) + (err_r_x_prime_lin / r_x_second)  + (err_epsilon_0 / epsilon_0));
}

void f_r_third() {
    r_x_third = r_third_minus_multimetro + fabs(v_minus_third) *
        (r_third_plus_multimetro - r_third_minus_multimetro) / (v_plus_third + fabs(v_minus_third));
    err_r_x_third_sens = fmax(fabs(r_x_third - r_third_plus_multimetro), fabs(r_x_third - r_third_minus_multimetro));
}
void f_rho_x(){
    rho_x=R_2*(r_x_second -r_x_third)/r_x_third;
}

void parte_2() {
    r_c = r_c_minus + fabs(v_c_minus) *
        (r_c_plus - r_c_minus) / (v_c_plus + fabs(v_c_minus));
    err_r_c_sens = fmax(fabs(r_c - r_c_plus), fabs(r_c - r_c_minus));
    r_x_prime_new = r_prime_new_minus + fabs((double)n_prime_new_minus) *
        (r_prime_new_plus - r_prime_new_minus) / ((double)n_prime_new_plus + fabs((double)n_prime_new_minus));
    err_r_x_prime_new_sens = fmax(fabs(r_x_prime_new - r_prime_new_plus), fabs(r_x_prime_new - r_prime_new_minus));
    R_x_prime = (R_0 * r_x_prime_new) / (r_c);
    r_x_second_new = r_second_new_minus + fabs((double)n_second_new_minus) *
        (r_second_new_plus - r_second_new_minus) / ((double)n_second_new_plus + fabs((double)n_second_new_minus));
    err_r_x_second_new_sens = fmax(fabs(r_x_second_new - r_second_new_plus), fabs(r_x_second_new - r_second_new_minus));
    r_c_new = r_c_new_minus + fabs(v_c_new_minus) *
        (r_c_new_plus - r_c_new_minus) / (v_c_new_plus + fabs(v_c_new_minus));
    err_r_c_new_sens = fmax(fabs(r_c_new - r_c_new_plus), fabs(r_c_new - r_c_new_minus));
    R_x_second = (R_0 * r_x_second_new) / (r_c_new);
}

void graph() {
    system("gnuplot -p < grafico1.gp");
    system("gnuplot -p < grafico2.gp");
    system("gnuplot -p < grafico3.gp");
}

void write_file(FILE* values) {
    fprintf(values, "Analisi dati esperienza: \n");
    fprintf(values, "Prima parte dell'esperienza:\n");
    fprintf(values, "Costanti note:\n");
    fprintf(values, "Resistenza nota per la parte preliminare (R) : %lf ± %lf\n", rho_v, err_rho_v);
    fprintf(values, "r_0 sul banco: %lf, con errore di sens: %lf, e errore di lin: %lf\n", r_0, err_r_0_sens, err_r_0_lin);
    fprintf(values, "ϵ_0 dato della pila: %lf ± %lf\n", epsilon_0, err_epsilon_0);
    fprintf(values, "Errore di linearità r primo: %lf\n", err_r_x_prime_lin);
    fprintf(values, "Errore di linearità r secondo: %lf\n", err_r_x_second_lin);
    fprintf(values, "Errore di linearità r terzo: %lf\n", err_r_x_third_lin);
    fprintf(values, "Resistenza nota per la parte 5(R_0 nel file): %lf\n\n", R_2);
    fprintf(values, "Misure preliminari:\n");
    fprintf(values, "Tensione V_1: %lf ± %lf\n", v1, err_v1);
    fprintf(values, "Tensione V_2: %lf ± %lf\n", v2, err_v2);
    fprintf(values, "Valore resistenza ρ_x: %lf\n", rho_x_pre);
    fprintf(values, "Valore tensione ϵ_x: %lf\n\n", epsilon_x);
    fprintf(values, "Misura con il galvanometro: \n");
    fprintf(values, "Resistenza r_x primo: %lf\n", r_x_prime);
    fprintf(values, "Errore sensibilità r_x primo: %lf\n", err_r_x_prime_sens);
    fprintf(values, "ϵ_x: %lf ± %lf\n\n", epsilon_x_galvanometro, err_epsilon_x_galvanometro);
    fprintf(values, "Misura con multimetro: \n"); 
    fprintf(values, "Resistenza r_x secondo: %lf\n", r_x_second); 
    fprintf(values, "Errore di sensibilità r_x secondo: %lf\n", err_r_x_second_sens); 
    fprintf(values, "ϵ_x: %lf ± %lf\n\n", epsilon_x_multimetro, err_epsilon_x_multimetro);
    fprintf(values, "Resistenza r_x terza: %lf\n", r_x_third); 
    fprintf(values, "Resistenza incognita ρ_x: %lf\n\n", rho_x); 
    fprintf(values, "Seconda parte dell'esperienza:\n");
    fprintf(values, "Costanti note: \n");
    fprintf(values, "Resistenza R_0 nota: %lf\n", R_0);
    fprintf(values, "Errore di linearità per r_c: %lf\n", err_r_c_lin);
    fprintf(values, "Errore linearità di r_x primo nuovo: %lf\n", err_r_x_prime_new_lin);
    fprintf(values, "Errore linearità di r_x secondo nuovo: %lf\n", err_r_x_second_new_lin);
    fprintf(values, "Errore linearità per r_c nuovo: %lf\n\n", err_r_c_new_lin);
    fprintf(values, "Misura della resistenza R_x preliminare: %lf\n", R_x);
    fprintf(values, "r_c: %lf\n", r_c);
    fprintf(values, "Errore sensibilità r_c: %lf\n", err_r_c_sens);
    fprintf(values, "r_x primo nuovo: %lf\n", r_x_prime_new);
    fprintf(values, "Errore sensibilità r_x primo nuovo: %lf\n", err_r_x_prime_new_sens);
    fprintf(values, "R_x primo: %lf\n", R_x_prime);
    fprintf(values, "r_x secondo nuova: %lf\n", r_x_second_new);
    fprintf(values, "Errore sensibilità r_x secondo nuova: %lf\n", err_r_x_second_new_sens);
    fprintf(values, "Valore r_c nuova: %lf\n", r_c_new);
    fprintf(values, "Errore sensibilità r_c nuova: %lf\n", err_r_c_new_sens);
    fprintf(values, "R_x secondo: %lf", R_x_second);
}