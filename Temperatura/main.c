/* Ingresar 10 temperaturas. Calcular prom, max, min, cant. de grados entre 10 y 20, imprimir de mayor a menor */

#include <stdio.h>
#include <stdint.h>

#define CANT_GRADOS 10

#define RANGO_MIN 10
#define RANGO_MAX 20

#define MAX_IX 0
#define MIN_IX (CANT_GRADOS - 1)

typedef struct {
    float promedio;
    float max;
    float min;
    uint8_t rango;
} tempValores_t;

void bienvenido(void);
void ingresarTemperaturas(float []);
float ingresarTemperatura(uint8_t);
void ordenar(float []);
float promedio(float []);
float max(float []);
float min(float []);
uint8_t rango(float []);
void printear(float [], tempValores_t);

int main(void) {
    float temperatura[CANT_GRADOS];
    tempValores_t valores;

    bienvenido();
    ingresarTemperaturas(temperatura);
    ordenar(temperatura);

    valores.promedio = promedio(temperatura);
    valores.max = max(temperatura);
    valores.min = min(temperatura);
    valores.rango = rango(temperatura);
    
    printear(temperatura, valores);

    return 0;
}

void bienvenido(void) {
    printf("Bienvenido al programa.\n\
    Este se encarga de anotar hasta %d de temperaturas para luego devolver esta misma organizada de mayor grado a menor.\n\
    Al final, devuelve el valor promedio, la temperatura maxima y minima; y la cantidad de temperaturas que se encuentran entre %d y %d.\n\n", CANT_GRADOS, RANGO_MIN, RANGO_MAX);
}

void ingresarTemperaturas(float temperatura[]) {
    for(uint8_t i = 0; i < CANT_GRADOS; i++) {
        temperatura[i] = ingresarTemperatura(i + 1);
    }
}

float ingresarTemperatura(uint8_t num) {
    float temperatura;

    printf("Inserte la temperatura numero %d: ", num);
    scanf("%f", &temperatura);

    return temperatura;
}

void ordenar(float temperatura[]) {
    uint8_t comp = 1, lim = CANT_GRADOS - 1;
    float temp;

    while (comp) {
        comp = 0;

        for(uint8_t i = 0; i < lim; i++) {
            if(temperatura[i] < temperatura[i + 1]) {
                temp = temperatura[i];
                temperatura[i] = temperatura[i + 1];
                temperatura[i + 1] = temp;
                comp = i;
            }
        }

        lim = comp;
    }
}

float promedio(float temperatura[]) {
    float prom = 0;

    for(uint8_t i = 0; i < CANT_GRADOS; i++) prom += temperatura[i];

    return prom / CANT_GRADOS;
}

float max(float tempeatura[]) {
    return tempeatura[MAX_IX];
}

float min(float temperatura[]) {
    return temperatura[MIN_IX];
}

uint8_t rango(float temperatura[]) {
    uint8_t cant = 0;

    for(uint8_t i = 0; i < CANT_GRADOS; i++) {
        if(temperatura[i] >= RANGO_MIN && temperatura[i] <= RANGO_MAX) cant++;
    }
    
    return cant;
}

void printear(float temperatura[], tempValores_t valores) {
    printf("Temperaturas de mayor a menor: ");
    for(uint8_t i = 0; i < CANT_GRADOS; i++) {
        printf("\n  %f", temperatura[i]);
    }
    printf("\nTemperatura promedio: %f\n", valores.promedio);
    printf("Temperatura max: %f\n", valores.max);
    printf("Temperatura min: %f\n", valores.min);
    printf("Cantidad de temperaturas entre %d y %d: %d", RANGO_MIN, RANGO_MAX, valores.rango);
}