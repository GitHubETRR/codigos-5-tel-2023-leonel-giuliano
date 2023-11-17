/* Deberá generar una función que completa al azar cuando se comienza el juego los valores de daño, y escudos de cada monstruo. Debe llamar a una función que lo hace con un solo monstruo por los N monstruos.​ */

#include <stdio.h>

/* Seteo general */

    #define LONG_NOMBRE 36
    #define CANT_DANIOS 3
    #define CANT_PODERES 3
    #define CANT_ATRIBUTOS CANT_PODERES + CANT_DANIOS

    int numero_al_azar(int linf,int lsup); /* Función grupo 1 */

    typedef struct {
        char nombre[LONG_NOMBRE];
        int puntos;
    }atributos_t;

    typedef struct {
        char nombre[LONG_NOMBRE];
        int vida;
        atributos_t danios[CANT_DANIOS];
        atributos_t poderes[CANT_PODERES];
    }monster_t;

/* Todo eso se podría sacar de esta parte */

#define ATRIBUTOS_LINF 1
#define ATRIBUTOS_LSUP 100

void inicializar_monstruos(monster_t monsters[] ,int cantidad);
void inicializar_monstruo(monster_t monsters);

void inicializar_monstruos(monster_t monsters[] ,int cantidad) {
    for(char i = 0; i < cantidad; i++) inicializar_monstruo(monsters[i]);
}

void inicializar_monstruo(monster_t monsters) {
    for(char atributo = 0; atributo < CANT_ATRIBUTOS; atributo++) {
        int atributo_random = numero_al_azar(ATRIBUTOS_LINF, ATRIBUTOS_LSUP);

        if(atributo < CANT_DANIOS) monsters.danios[atributo].puntos = atributo_random;
        else monsters.poderes[atributo].puntos = atributo_random;
    }
}
