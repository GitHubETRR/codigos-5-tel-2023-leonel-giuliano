/* Realizar una función que pase a mayus. Si corresponde, verificar si son letras */

#include <stdio.h>

#define STR_MAX 429496
#define MINUS_MAYUS 32

void pedirStr(char []);
char pasarMayus(char);

int main() {
    char str[STR_MAX] = {};

    printf("Bienvenido, este programa se encarga de pasar a mayusculas todas las letras en minusculas de la palabra que hayas insertado\n");
    pedirStr(str);

    for (int i = 0; str[i]; i++) str[i] = pasarMayus(str[i]);
    printf("%s", str);

    return 0;
}

void pedirStr(char str[]) {
    printf("Inserte una cadena de texto: ");
    gets(str);
}

char pasarMayus(char chara) {
    chara -= (chara >= 'a' && chara <= 'z') ? MINUS_MAYUS : 0;

    return chara;
}