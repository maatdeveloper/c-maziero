/* Nome: Matheus Carvalho Garcia
 * Data: 14/04/2025
 *
 * histograma.c: implemetação do histograma dos numeros aleaotorios gerados
 */

#include <stdio.h>
#include <string.h>
#include "../lcrandom/lcrandom.h"
#include "histograma.h"

#define NUMBERS_RANGE 100

int numbers[NUMBERS_RANGE];
int maior;

// gera 10^6 valores aleatorios (>100) e contabiliza a em
// 'numbers' quantas vezes foi gerado 'x' numero
void gerar_numeros_aleatorios()
{
    int num;

    // ------------ 10 milhões!
    for (int i = 0; i < 10000000; i++) {
        num = (int) lcrandom() % 100;

        numbers[num] += 1;
    }
}

void maior_ocorrencia()
{
    maior = numbers[0];

    for (int i = 1; i < NUMBERS_RANGE; i++) {
        if (numbers[i] > maior) maior = numbers[i];
    }
}

void gerar_histograma()
{
    int num_of_asterisk;

    // define todos os elementos de 'numbers' como 0;
    memset(numbers, 0, sizeof (int) * NUMBERS_RANGE);
    gerar_numeros_aleatorios();

    // fazer regra de 3 com os valores no array para o
    // histograma imprimir corretamente
    maior_ocorrencia();

    printf("   0   10   20   30   40   50   60   70   80   90  100\n");
    printf("   +****+****+****+****+****+****+****+****+****+****+\n");

    for (int i = 0; i < NUMBERS_RANGE; i++) {
        num_of_asterisk = ((numbers[i] * 100) / maior) / 2;

        printf("%2d |", i);
        for (int j = 0; j < num_of_asterisk; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("   +****+****+****+****+****+****+****+****+****+****+\n");
}