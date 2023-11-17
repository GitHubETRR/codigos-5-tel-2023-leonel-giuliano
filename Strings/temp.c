/* Calcular el promedio entre 10 temperaturas y mostrar cuando valen entre 10 y 20 grados */

#include <stdio.h>
#include <stdint.h> 

#define TEMP_CANT 10
#define TEMP_IX (TEMP_CANT - 1)

#define PROM_L 2
#define GRADO_I 10
#define GRADO_F 20

#define PROM_IX 0
#define GRADO_IX 1

#define GRADO 248

void pedirTemp(float[], uint8_t);
void promedio(float[], float[]);
void final(float[]);

int main(void) {
    float temp[TEMP_CANT] = {};
    printf("Bienvenido, este programa se encarga de promediar entre las (10) temperaturas ingresadas y mostrar los que pertenecen a un rango (10 a 20)\n");
    for(uint8_t i = 0; i < TEMP_CANT; i++) pedirTemp(temp, i);

    float prom[PROM_L] = {0};
    promedio(temp, prom);

    final(prom);

    return 0;
}

void pedirTemp(float temp[], uint8_t num) {
    printf("Inserte temperatura numero %d: ", num + 1);
    scanf("%f", &temp[num]);
}

void promedio(float temp[], float prom[]) {
    for(uint8_t i = 0; i < TEMP_CANT; i++) {
        prom[PROM_IX] += temp[i];

        if(temp[i] > GRADO_I && temp[i] < GRADO_F) prom[GRADO_IX]++;
    }
    prom[PROM_IX] /= TEMP_CANT;
}

void final(float prom[]) {
    printf("Grado promedio: %f\n", prom[PROM_IX]);
    printf("Cantidad de grados entre 10 y 20: %d", (int)prom[GRADO_IX]);
}