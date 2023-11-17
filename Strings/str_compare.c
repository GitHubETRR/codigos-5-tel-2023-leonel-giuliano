#include <stdio.h>

#define STR1 0
#define STR2 1

#define STR_CANT 2
#define STR_MAX 1000

#define GRADO 248 /* ° */

void pedirStr(char [][STR_MAX], char);
char compare(char [][STR_MAX]);
void final(char);

void main() {
    char str[STR_CANT][STR_MAX] = {}; /* Array de 2 dimensiones para contener STR_CANT de strings con STR_MAX de carácteres */

    printf("Bienvenido, este programa se encarga de comparar si las 2 cadenas de texto que usted anote son iguales entre si o no\n");

    for(char i = 0; i < STR_CANT; i++) pedirStr(str, i); /* El "for" compara con STR_CANT y no directamente 2 por si cambiaba el código para comparar más de 2 strings a la vez */
    char comprob = compare(str);

    final(comprob);
}

void pedirStr(char str[STR_CANT][STR_MAX], char num) {
    printf("\nPor favor, inserte la cadena de texto n%c%d: ", GRADO, num + 1);
    gets(str[num]);
}

char compare(char str[STR_CANT][STR_MAX]) {
    char bool = 1;

    for(int i = 0; str[STR1][i] || str[STR2][i]; i++) { /* Compara cada carácter entre sí */
        if(str[STR1][i] != str[STR2][i]) { /* Si son distintos, termina la comprobación */
            bool--;
            break;
        }
    }

    return bool;
}

void final(char bool) {
    if(bool) printf("\n\nRESULTADO: Las cadenas de texto son iguales");
    else printf("\n\nRESULTADO: Las cadenas de texto son distintas");
}