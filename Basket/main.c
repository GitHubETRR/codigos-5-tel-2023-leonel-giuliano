/* Se deberá realizar un programa al que se le puedan ir ingresando los puntos que se van realizando en el partido. El programa deberá pedir a que equipo pertenece el punto (1 o 2) y el valor del punto. El partido y la carga de información finalizará cuando se ingrese que el jugador pertenece al equipo 0.
Luego de cualquier carga de datos se deberá siempre ir actualizando el puntaje del partido e indicar que equipo va ganando. 
Cuando el programa finalice, deberá indicar: 
•	Los puntos por cada equipo, y que equipo es el ganador. 
•	La cantidad simples, dobles y triples que se realizaron.
•	El porcentaje de puntos que representan los tiros simples, dobles y los triples sobre el total.
 */

#include <stdio.h>
#include <stdint.h>

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
void nameTeam(uint8_t num, char name[]);
void match(team_t teams[]);
uint8_t selectTeam(void);
uint8_t pointsF(team_t team);
uint8_t repeat(void);
void final(team_t teams[]);
void percentageF(team_t team, uint8_t point);
void endScore(team_t teams[]);
void endPoints(team_t teams[]);

int main(void) {
    team_t teams[TEAM_CANT];

    bienvenida();
    start(teams);
    match(teams);
    final(teams);

    return 0;
}

void bienvenida(void) {
    printf("Hola mundo\n\n");
}

void start(team_t teams[]) {
    for(uint8_t i = 0; i < TEAM_CANT; i++) {
        nameTeam(i + 1, teams[i].name);
        teams[i].score = 0;
        for(uint8_t j = 0; j < POINTS_CANT; j++) teams[i].points[j] = 0;
    }
}

void nameTeam(uint8_t num, char name[]) {
    printf("Inserte el string %u: ", num);
    scanf("%[^\n]%*c", name);
}

void match(team_t teams[]) {
    uint8_t choice;

    do {
        uint8_t team = selectTeam();

        teams[team].score = pointsF(teams[team]);
        choice = repeat();
    } while(choice);
}

uint8_t selectTeam(void) {
    uint8_t option;

    printf("Seleccione equipo: ");
    scanf("%u", &option);

    while(option != 1 && option != 2) {
        printf("Repita: ");
        scanf("%u", &option);
    }

    return --option;
}

uint8_t pointsF(team_t team) {
    uint8_t point;

    printf("Inserte puntaje: ");
    scanf("%u", &point);

    while(point < SIMPLE || point > TRIPLE) {
        printf("Repita: ");
        scanf("%u", &point);
    }

    team.points[point - 1]++;
    team.points[POINTS_IX]++;
    team.score += team.points[point - 1] * point;
    return team.score;
}

uint8_t repeat(void) {
    uint8_t choice;

    printf("Repetir?: ");
    scanf("%u", &choice);    

    while(choice != 0 && choice != 1) {
        printf("Repita: ");
        scanf("%u", &choice);
    }

    return choice;
}

void final(team_t teams[]) {
    for(uint8_t i = 0; i < TEAM_CANT; i++) {
        for(uint8_t j = 0; j < PERCENTAGE_CANT; j++) {
            percentageF(teams[i], j);
        }
    }

    endScore(teams);
    endPoints(teams);
}

void percentageF(team_t team, uint8_t point) {
    team.percentage[point] = team.points[POINTS_IX] * 100 / team.points[point];
}

void endScore(team_t teams[]) {
    uint8_t a = TEAM1_IX, b = TEAM2_IX;

    printf("\nFinal\n");
    printf("Puntaje final\n");
    printf("Puntaje del equipo %s: %u\n", teams[TEAM1_IX].name, teams[TEAM1_IX].score);
    printf("Puntaje del equipo %s: %u\n", teams[TEAM2_IX].name, teams[TEAM2_IX].score);

    if(teams[TEAM1_IX].score == teams[TEAM2_IX].score) {
        printf("Empate");
        return;
    }

    if(teams[TEAM1_IX].score < teams[TEAM2_IX].score) {
        a = TEAM2_IX;
        b = TEAM1_IX;
    }

    printf("Equipo %s le ganó al equipo %s\n\n", teams[a].name, teams[b].name);
}

void endPoints(team_t teams[]) {
    printf("Puntos\n");

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