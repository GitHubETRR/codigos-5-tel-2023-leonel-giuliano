/* Se debera realizar un programa al que se le puedan ir ingresando los puntos que se van realizando en el partido. El programa debera pedir a que equipo pertenece el punto (1 o 2) y el valor del punto. El partido y la carga de informacion finalizara cuando se ingrese que el jugador pertenece al equipo 0.
Luego de cualquier carga de datos se debera siempre ir actualizando el puntaje del partido e indicar que equipo va ganando. 
Cuando el programa finalice, debera indicar: 
•	Los puntos por cada equipo, y que equipo es el ganador. 
•	La cantidad simples, dobles y triples que se realizaron.
•	El porcentaje de puntos que representan los tiros simples, dobles y los triples sobre el total.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define TEAM_CANT 2
#define STR_MAX 50
#define POINTS_CANT 4
#define PERCENTAGE_CANT 4
#define SIMPLE 1
#define DOBLE 2
#define TRIPLE 3

#define TEAM1_IX 0
#define TEAM2_IX 1
#define SIMPLE_IX 0
#define DOBLE_IX 1
#define TRIPLE_IX 2
#define POINTS_IX 3

typedef struct {
    char name[STR_MAX];
    uint8_t score;
    uint8_t points[POINTS_CANT];
    float percentage[PERCENTAGE_CANT];
} team_t;

void bienvenida(void);
void start(team_t teams[]);
void nameTeam(team_t teams[], uint8_t num);
void match(team_t teams[]);
uint8_t selectTeam(void);
void pointsF(team_t teams[], uint8_t team);
uint8_t repeat(void);
void end(team_t teams[]);
void percentageF(team_t teams[], uint8_t team, uint8_t point);
void endScore(team_t teams[]);
void endPoints(team_t teams[]);

int main(void) {
    team_t teams[TEAM_CANT];

    bienvenida();
    start(teams);
    match(teams);
    end(teams);

    return 0;
}

void bienvenida(void) {
    printf("Bienvenido al programa\n");
    printf("Este se encarga de anotar los puntos de un partido de basket\n");
    printf("La idea es que, cada vez que se meta un punto en el partido, anote su valor. Este sera interpretado como un simple, doble o triple automaticamente\n");
    printf("Al finalizar el partido, mostrara al equipo ganador y los datos del mismo.\n\n");
}

void start(team_t teams[]) {
    for(uint8_t i = 0; i < TEAM_CANT; i++) {
        nameTeam(teams, i);
        teams[i].score = 0;
        for(uint8_t j = 0; j < POINTS_CANT; j++) teams[i].points[j] = 0;
    }
}

void nameTeam(team_t teams[], uint8_t num) {
    printf("Inserte el nombre del equipo %u: ", num + 1);
    scanf("%[^\n]%*c", teams[num].name);

    if(!num) return;

    while(!strcmp(teams[TEAM2_IX].name, teams[TEAM1_IX].name)) {
        printf("\nEl nombre tiene que ser distinto del anterior equipo\n");
        printf("Por favor, inserte el nombre correcto: ");
        scanf("%[^\n]%*c", teams[TEAM2_IX].name);
    }
}

void match(team_t teams[]) {
    uint8_t choice;

    do {
        uint8_t team = selectTeam();

        pointsF(teams, team);
        choice = repeat();
    } while(choice);
}

uint8_t selectTeam(void) {
    uint8_t option;

    printf("\n\nInserte el equipo que realizo el punto ('1' o '2'): ");
    scanf("%u", &option);

    while(option != 1 && option != 2) {
        printf("\nPor favor, inserte el equipo disponible ('1' o '2'): ");
        scanf("%u", &option);
    }

    return --option;
}

void pointsF(team_t teams[], uint8_t team) {
    uint8_t point;

    printf("\nInserte el punto que se realizo, ya sea un Simple ('1'), Doble ('2') o Triple ('3'): ");
    scanf("%u", &point);

    while(point < SIMPLE || point > TRIPLE) {
        printf("Por favor, inserte un punto valido ('1', '2' o '3'): ");
        scanf("%u\n", &point);
    }

    teams[team].points[point - 1]++;
    teams[team].points[POINTS_IX]++;
    teams[team].score += teams[team].points[point - 1] * point;
}

uint8_t repeat(void) {
    uint8_t choice;

    printf("\n\nSeleccione '0' para finalizar el partido o '1' si se ha realizado otro punto: ");
    scanf("%u", &choice);

    while(choice != 0 && choice != 1) {
        printf("Por favor, inserte una opcion valida ('0' o '1'): ");
        scanf("%u", &choice);
    }

    return choice;
}

void end(team_t teams[]) {
    for(uint8_t i = 0; i < TEAM_CANT; i++) {
        for(uint8_t j = 0; j < PERCENTAGE_CANT; j++) {
            percentageF(teams, i, j);
        }
    }

    endScore(teams);
    endPoints(teams);
}

void percentageF(team_t teams[], uint8_t team, uint8_t point) {
    teams[team].percentage[point] = (teams[team].points[point]) ?
        teams[team].points[point] * 100 / teams[team].points[POINTS_IX] :
        0;
}

void endScore(team_t teams[]) {
    uint8_t a = TEAM1_IX, b = TEAM2_IX;

    printf("\n\n  ---    FINAL   ---\n");
    printf("PUNTAJE\n");
    printf("Puntaje del equipo %s: %u\n", teams[TEAM1_IX].name, teams[TEAM1_IX].score);
    printf("Puntaje del equipo %s: %u\n", teams[TEAM2_IX].name, teams[TEAM2_IX].score);

    printf("RESULTADO: ");

    if(teams[TEAM1_IX].score == teams[TEAM2_IX].score) {
        printf("Empate");
        return;
    }

    if(teams[TEAM1_IX].score < teams[TEAM2_IX].score) {
        a = TEAM2_IX;
        b = TEAM1_IX;
    }

    printf("El equipo %s le gano al equipo %s\n\n", teams[a].name, teams[b].name);
}

void endPoints(team_t teams[]) {
    printf("PUNTOS\n");

    for(uint8_t i = 0; i < TEAM_CANT; i++) {
        printf("Cantidad de puntos del equipo %s:\n", teams[i].name);
        printf("    Simples: %u (%f%%)\n",
            teams[i].points[SIMPLE_IX],
            teams[i].percentage[SIMPLE_IX]
        );
        printf("    Dobles: %u (%f%%)\n",
            teams[i].points[DOBLE_IX],
            teams[i].percentage[DOBLE_IX]
        );
        printf("    Triples: %u (%f%%)\n\n",
            teams[i].points[TRIPLE_IX],
            teams[i].percentage[TRIPLE_IX]
        );
    }
}