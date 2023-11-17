/* 
Escribir un programa que devuelva el número complejo en formato rectangular (su parte real + j su parte imaginaria), ingresando su módulo y ángulo (fase).
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void bienvenida(void);
float ingModulo(void);
float ingAngulo(void);
void complejo(float, float);


int main() {
    bienvenida();
    float mod = ingModulo();   
    float ang = ingAngulo();
    complejo(mod, ang);

    return 0;
}

void bienvenida(void) {
    printf("Bienvenido al progama cuya funcion es devolver un numero complejo en formato rectangular al pasarle el formato polar\n\n");
}

float ingModulo(void) {
    float mod;

    printf("Ingrese el modulo: ");
    scanf("%f", &mod);

    return mod;
}

float ingAngulo(void) {
    float ang;

    printf("Ingrese el angulo (deg): ");
    scanf("%f", &ang);

    return ang;
}

void complejo(float mod, float ang) {
    printf("\nParte Real: %f\n\
Parte Imaginaria: %f",
        mod * cos(ang * PI / 180),
        mod * sin(ang * PI / 180));
}