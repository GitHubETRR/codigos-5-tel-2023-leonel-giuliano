/* 
Escribir un programa que calcule el módulo de un número complejo y su ángulo (fase)
ingresando su parte real y su parte imaginaria. 
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

#define REAL 0
#define IMAGINARIO 1

#define MODULO 0
#define FASE 1

#define DATA_L 2
#define RESULTADO_L 2

void datos(float[DATA_L]);
void calcular(float[DATA_L], float[RESULTADO_L]);
void resultados(float[RESULTADO_L]);

void main() {
    float data[DATA_L], polar[RESULTADO_L] = {0};

    datos(data);
    calcular(data, polar);

    resultados(polar);
}

void datos(float data[DATA_L]) {
    printf("Inserte la parte real del numero complejo: ");
    scanf(" %f", &data[REAL]);
    printf("Inserte la parte imaginaria del numero complejo: ");
    scanf(" %f", &data[IMAGINARIO]);
}

void calcular(float data[DATA_L], float polar[RESULTADO_L]) {
    polar[MODULO] = sqrt(pow(data[REAL], 2) + pow(data[IMAGINARIO], 2));
    polar[FASE] = atan2(data[IMAGINARIO], data[REAL]) * 180 / PI;
}

void resultados(float polar[RESULTADO_L]) {
    printf("\n  ---   RESULTADOS   ---\n\
Modulo: %f\n\
Fase: %f", polar[MODULO], polar[FASE]);
}