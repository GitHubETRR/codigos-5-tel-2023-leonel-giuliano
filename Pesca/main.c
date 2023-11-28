/* oncurso de pesca muy exclusivo en donde participan solamente 3 pescadores. El ganador de concurso sera el que mas haya pescado durante el concurso y ademas se dara el premio a la pieza mas grande.
Se debera realizar un programa en el que se ingresaran las cantidades y longitudes de las piezas extraidas por cada pescador. Los pescadores seran identificados por numeros del 1 al 3. En caso de querer cargarle al pescador 0 (valor que no corresponde a ninguno de los 3 pescadores) se dara por finalizado el concurso.
Cuando el programa finalice, debera indicar: 
•	El pescador con mayor cantidad de piezas extraidas.
•	El pescador con la pieza mayor (y su longitud).
•	El total de piezas extraidas del agua.
•	El promedio de las longitudes de los peces extraidos.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define NAME_MAX 50
#define PESCADOR_CANT 3
#define PESCA_CANT 2
#define PEZ_MIN 12
#define MAX_LIST 4

#define PESCADOR1_IX 0
#define PESCADOR2_IX 1
#define PESCADOR3_IX 2
#define PESCADOR_LIST 3
#define MAX_IX 0

typedef struct {
    char name[NAME_MAX];
    float fish;
    uint8_t cant;
    float max;
    float prom;
} fisher_t;

void start(fisher_t fisher[]);
void bienvenida(void);
void askName(fisher_t fisher[], uint8_t num);
void contest(fisher_t fisher[]);
uint8_t select(void);
void fishF(fisher_t fisher[], uint8_t option);
void maxF(fisher_t fisher[], uint8_t option);
void sumProm(fisher_t fisher[], uint8_t option);
uint8_t repeat(void);
void end(fisher_t fisher[]);
void promF(fisher_t fisher[], uint8_t num);
void maxMin(float maxList[]);
void printMax(fisher_t fisher[], float maxCant[], float maxFish[]);
void printCant(fisher_t fisher[]);
void forProm(fisher_t fisher);
void printProm(fisher_t fisher[]);

int main(void) {
    fisher_t fisher[PESCADOR_CANT];

    start(fisher);
    contest(fisher);
    end(fisher);

    return 0;
}

void start(fisher_t fisher[]) {
    bienvenida();

    for(uint8_t i = 0; i < PESCADOR_CANT; i++) {
        askName(fisher, i);
        fisher[i].fish = 0;
        fisher[i].cant = 0;
        fisher[i].max = 0;
        fisher[i].prom = 0;
    }
}

void bienvenida(void) {
    printf("Bienvenido al programa\n");
    printf("Este se encarga de almacenar las piezas pescadas en un concurso cada vez que se captura una\n");
    printf("Una vez finalizado, se imprimen los datos de las piezas capturadas\n");
    printf("IMPORTANTE: La pieza tiene que ser mayor a %d cm para ser considerada\n\n", PEZ_MIN);
    printf("    ---    COMIENZA    ---\n");
}

void askName(fisher_t fisher[], uint8_t num) {
    printf("\nAnote el nombre y apellido del pescador %u: ", num + 1);
    scanf("%[^\n]%*c", fisher[num].name);

    if(!num) return;

    for(uint8_t i = 0; i < num; i++) {
        if(strcmp(fisher[num].name, fisher[i].name)) continue;

        while(!strcmp(fisher[num].name, fisher[i].name)) {
            i = 0;
            printf("\nEl nombre y apellido insertado corresponde a otro pescador\n");
            printf("Por favor, cambie el nombre y apellido del pescador %u: ", num + 1);
            scanf("%[^\n]%*c", fisher[num].name);
        }
    }
}

void contest(fisher_t fisher[]) {
    uint8_t comp = 0;

    do {
        uint8_t option = select();
        fishF(fisher, option);
        maxF(fisher, option);
        sumProm(fisher, option);

        comp = repeat();
    } while(comp);
}

uint8_t select(void) {
    uint8_t option;

    printf("Selecciona el pescador que atrapo la pieza ('1', '2' o '3'): ");
    scanf("%u", &option);

    while(option - 1 < PESCADOR1_IX || option - 1 > PESCADOR3_IX) {
        printf("\nEl numero insertado no corresponde a ningun pescador\n");
        printf("Por favor, inserte un pescador valido ('1', '2' o '3'): ");
        scanf("%u", &option);
    }

    return option - 1;
}

void fishF(fisher_t fisher[], uint8_t option) {
    printf("Inserte la longitud de la pieza (cm): ");
    scanf("%f", &fisher[option].fish);

    while(fisher[option].fish < PEZ_MIN) {
        printf("\nLa longitud de la pieza es menor a %d cm\n", PEZ_MIN);
        printf("Por favor, inserte una longitud valida: ");
        scanf("%f", &fisher[option].fish);
    }

    fisher[option].cant++;
}

void maxF(fisher_t fisher[], uint8_t option) {
    if(fisher[option].max >= fisher[option].fish) return;

    fisher[option].max = fisher[option].fish;
}

void sumProm(fisher_t fisher[], uint8_t option) {
    fisher[option].prom += fisher[option].fish;
}

uint8_t repeat(void) {
    uint8_t option;

    printf("\nSeleccione '0' para finalizar el concurso o '1' para anotar otra pieza: ");
    scanf("%u", &option);

    while(option != 0 && option != 1) {
        printf("\nEl numero insertado no es valido\n");
        printf("Por favor, inserte un '0' para finalizar o un '1' para seguir: ");
        scanf("%u", &option);
    }

    return option;
}

void end(fisher_t fisher[]) {
    float maxCant[PESCADOR_LIST];
    float maxFishes[PESCADOR_LIST];

    for(uint8_t i = 0; i < PESCADOR_CANT; i++) {
        promF(fisher, i);
        maxCant[i] = fisher[i].cant;
        maxFishes[i] = fisher[i].max;
    }

    maxMin(maxCant);
    maxMin(maxFishes);

    printMax(fisher, maxCant, maxFishes);
    printCant(fisher);
    for(uint8_t i = 0; i < PESCADOR_CANT; i++) forProm(fisher[i]);
    printProm(fisher);
}

void promF(fisher_t fisher[], uint8_t num) {
    if(!fisher[num].prom) return;

    fisher[num].fish = fisher[num].prom;
    fisher[num].prom /= fisher[num].cant;
}

void maxMin(float maxList[]) {
    uint8_t comp = 1, lim = PESCA_CANT - 1;
    float temp;

    while(comp) {
        comp = 0;

        for(uint8_t i = 0; i < lim; i++) {
            if(maxList[i] < maxList[i + 1]) {
                temp = maxList[i];
                maxList[i] = maxList[i + 1];
                maxList[i] = temp;
                comp = i;
            }
        }

        lim = comp;
    }
}

void printMax(fisher_t fisher[], float maxCant[], float maxFish[]) {
    printf("\n    ---    FINAL    ---    \n");
    printf("El pescador %s capturo la mayor cantidad con %u piezas\n\n",
        fisher[(uint8_t)maxCant[PESCADOR_LIST]].name,
        (uint8_t)maxCant[MAX_IX]);
    printf("El pescador %s capturo la pieza de mayor longitud siendo de %f cm\n\n",
        fisher[(uint8_t)maxFish[PESCADOR_LIST]].name,
        maxFish[MAX_IX]);
}

void printCant(fisher_t fisher[]) {
    uint8_t cant = 0;

    for(uint8_t i = 0; i < PESCADOR_CANT; i++) {
        cant += fisher[i].cant;
    }

    printf("Piezas totales: %u\n\n", cant);
}

void forProm(fisher_t fisher) {
    printf("Promedio del pescador %s: %f\n",
        fisher.name,
        fisher.prom);
}

void printProm(fisher_t fisher[]) {
    float prom = 0;
    uint8_t cant = 0;

    for(uint8_t i = 0; i < PESCA_CANT; i++) {
        prom += fisher[i].fish;
        cant += fisher[i].cant;
    }

    prom /= cant;
    printf("Promedio final: %f", prom);
}