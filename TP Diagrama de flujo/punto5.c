/* 
Escribir un programa que ingresada una tensión y una corriente (con su modulo y
ángulo) y la frecuencia de trabajo, informe el valor de la impedancia (parte real y parte
imaginaria, y luego el valor de los componentes asociados, resistor y capacitor o
inductor según corresponda. Para este programa deberá utilizar lo realizado en el punto
anterior como subprograma
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

#define V 0
#define I 1
#define MODULO 0
#define ANGULO 1

#define REAL 0
#define REACTIVO 1

#define VECTOR_L 2
#define MODE_L 2

#define IMPEDANCIA_L 2

void pedirVector(float[VECTOR_L][MODE_L], char, char);
float pedirFrecuencia(void);
void calcularImpedancia(float[IMPEDANCIA_L], float[VECTOR_L][MODE_L], char);
void componentes(float[IMPEDANCIA_L], float[IMPEDANCIA_L], float);
void resultado(float[IMPEDANCIA_L], float[IMPEDANCIA_L]);

void main() {
    float vector[VECTOR_L][MODE_L], impedancia[IMPEDANCIA_L], comp[IMPEDANCIA_L] = {0};

    printf("Bienvenido al programa que se encarga de mostrar la impedancia y los componentes de un circuito segun la tension y la corriente\n");

    for (char i = 0; i < VECTOR_L; i++) {
        for (char j = 0; j < MODE_L; j++) pedirVector(vector, i, j);
    }

    float f = pedirFrecuencia();

    for (char i = 0; i < IMPEDANCIA_L; i++) calcularImpedancia(impedancia, vector, i);

    componentes(comp, impedancia, f);

    resultado(comp, impedancia);
}

void pedirVector(float vector[VECTOR_L][MODE_L], char var, char mode) {
    char msgVar[10], msgMode[7];
    float val;

    if (var == V) strcpy(msgVar, "VOLTAJE");
    else if (var == I) strcpy(msgVar, "CORRIENTE");

    if (mode == MODULO) strcpy(msgMode, "modulo");
    else if (mode == ANGULO) strcpy(msgMode, "angulo");

    printf("%s ==> Inserte el valor del %s: ", msgVar, msgMode);
    scanf(" %f", &val);

    vector[var][mode] = val;
}

float pedirFrecuencia(void) {
    float f;

    printf("\nInserte el valor de la frecuencia: ");
    scanf(" %f", &f);

    return f;
}

void calcularImpedancia(float impedancia[IMPEDANCIA_L], float vector[VECTOR_L][MODE_L], char var) {
    float num;
    float mod = vector[V][MODULO] / vector[I][MODULO];
    float ang = vector[V][ANGULO] - vector[I][ANGULO];

    if (var == REAL) num = mod * cos(ang * PI / 180);
    else if (var == REACTIVO) num = mod * sin(ang * PI / 180);

    impedancia[var] = num;
}

void componentes(float comp[IMPEDANCIA_L], float impedancia[IMPEDANCIA_L], float f) {
    comp[REAL] = impedancia[REAL];

    comp[REACTIVO] = (impedancia[REACTIVO] < 0)? -1 / (2 * PI * f * impedancia[REACTIVO])
        : impedancia[REACTIVO] / (2 * PI * f);
}

void resultado(float impedancia[], float comp[]) {
    printf("    ---   RESULTADOS   ---\n");
    printf("Real: %f\n", impedancia[REAL]);
    printf("Reactivo: %f\n", impedancia[REACTIVO]);
    printf("Resistor: %f\n", comp[REAL]);

    if (impedancia[REACTIVO] < 0) printf("Capacitor: %f", comp[REACTIVO]);
    else printf("Inductor: %f", comp[REACTIVO]);
}