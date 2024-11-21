#include <stdio.h>

typedef enum cor_primara {RED, GREEN, BLUE} cor_primara;
typedef enum dia_semana {SEGUNDA,
                         TERCA,
                         QUARTA,
                         QUINTA,
                         SEXTA,
                         SABADO,
                         DOMINGO} dia_semana;

int main() {
    dia_semana dia = SEXTA;
    cor_primara cor = RED;
    char *cor_str;

    switch (cor) {
        case RED   : cor_str = "red"   ;
        case GREEN : cor_str = "green" ;
        case BLUE  : cor_str = "blue"  ;
        default    : cor_str = ""      ;
    }

    printf("cor enum: %d | cor str: %s \n", cor, cor_str);
    return 0;
}