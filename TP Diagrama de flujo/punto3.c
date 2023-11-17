/* 
Escribir un programa que sume dos números complejos en formato rectangular y pregunte al final como desea ver el resultado si en polar o rectangular y lo muestre en el formato que el usuario quiera. 
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

float real(char);
float imaginario(char);
void complejo(float, float, float, float);

int main() {
    printf("Bienvenido al progama cuya funcion es sumar dos numeros complejos en formato rectangular\n\n");

    float real1 = real(0);
    float img1 = imaginario(0);
    float real2 = real(1);
    float img2 = imaginario(1);
    complejo(real1, img1, real2, img2);

    return 0;
}

float real(char bool) {
    float real;

    printf("Numero real de Z%d: ", bool + 1);
    scanf("%f", &real);

    return real;
}

float imaginario(char bool) {
    float img;

    printf("Numero imaginario de Z%d: ", bool + 1);
    scanf("%f", &img);

    return img;
}

void complejo(float r1, float img1, float r2, float img2) {
    char bool;
    float r = r1 + r2;
    float i = img1 + img2;

    printf("\n\nPuede visualizar el complejo en rectangular (1) o en polar (2): ");
    scanf(" %c", &bool);
    while(bool != '1' && bool != '2') {
        printf("ERROR - Por favor, inserte '1' si quiere visualizarlo en rectangular o '2' si en polar: ");
        scanf(" %c", &bool);
    }

    if(bool == '1') {
        printf("\nZ = %f J%f", r, i);
        return;
    }

    float mod = sqrt(pow(r, 2) + pow(i, 2));
    float ang = atan2(i, r) * 180 / PI;

    printf("Z = %f*e^(J%f)", mod, ang);
}