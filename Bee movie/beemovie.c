#include <stdio.h>

#define SANO 0
#define ENVENENADO 1

// Nombre: Evil bueno malo good bee moovie man
// Monstruosidad: Bzzzzzz


// Daño 1: Baile (saca ganas de vivir)
// Daño 2: Polinizar (envenena (alergia))
// Daño 3: Invoca abejas por la boca (invoca minions)


// Vida: 1hp
// Poder 1: Bazinga (se activa por cada muerte: nuestro monstruo tiene 90% de probabilidades de revivir con estadísticas base y, en tal caso, un 20% de revivir con 100hp y 100df)
// Poder 2: Aguijón letal (instakill a otro monstruo y evil bueno malo good bee moovie man muere en el próximo turno)
// Armadura 1: Máscara led maldita (se activa por 1 turno y vuelve completamente inmune, pero se carga durante 3 turnos)


struct monstruo{
    char nombre[999];
    int vida;
    char estado;
    int damage[3];
    int poder;
};


void main(){
    struct monstruo bee_man = {
        'Evil bueno malo good bee moovie man',
        1,
        SANO,
        [20; 0; 0]
    };
}