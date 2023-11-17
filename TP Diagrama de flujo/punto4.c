/* 
Escribir un programa que al recibir una impedancia (parte real y parte imaginaria) y la
frecuencia de trabajo, indique el valor de la resistencia y el capacitor o inductor según
corresponda. 
 */

#include <stdio.h>
#include <string.h>

#define PI 3.14159265358979323846

float pedirVariable(char);
void resultado(float, float, float);

int main() {
    printf("Bienvenido al programa que se encarga de indicar los componentes de un circuito segun su impedancia y su frecuencia\n\n");

    float real = pedirVariable(0);
    float img = pedirVariable(1);
    float freq = pedirVariable(2);
    resultado(real, img, freq);

    return 0;
}

float pedirVariable(char bool) { /* Determina através de una char la variable que se pide */
    char var[34];
    float val;

    if(!bool) strcpy(var, "parte real de la impedancia");
    else if(bool == 1) strcpy(var, "parte imaginaria de la impedancia");
    else strcpy(var, "frecuencia del circuito");

    printf("Inserte la %s: ", var);
    scanf("%f", &val);

    return val;
}

void resultado(float real, float img, float freq) {
    char comp[14];

    if(img < 0 && img != 0) {
        img = -1 / (2 * PI * freq * img);
        strcpy(comp, "Capacitor (F)");
    } else if(img > 0) {
        img = img / (2 * PI * freq);
        strcpy(comp, "Inductor (H)");
    }

    printf("\nResistor (Ω): %f", real);
    if (img != 0) printf("\n%s: %f", comp, img);
}