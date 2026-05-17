/* Nome: Matheus Carvalho Garcia
 * Data: 21/04/2026
 *
 * periodo.c: implementação da biblioteca 'periodo.h'
 */

/* system includes */
#include <stdlib.h>

/* project includes */
#include "periodo.h"
#include "../lcrandom/lcrandom.h"

#define RANGE 100000

typedef struct list_of_random_numbers {
    unsigned long number;
    struct list_of_random_numbers *next;
} list_of_random_numbers;

list_of_random_numbers *init()
{
    list_of_random_numbers *temp;

    temp = malloc(sizeof (list_of_random_numbers));

    if (!temp) return NULL;

    temp->number = 0;
    temp->next = NULL;

    return temp;
}

void add(list_of_random_numbers *l, unsigned long number)
{
    list_of_random_numbers *tmp;
    
    tmp = malloc(sizeof (list_of_random_numbers));

    if (!tmp) return;

    tmp->number = number;
    tmp->next = l->next;

    l->next = tmp;
}

void remove(list_of_random_numbers *l)
{
    list_of_random_numbers *bye;

    bye = l->next;
    l->next = bye->next;

    free(bye);
}

list_of_random_numbers *search(list_of_random_numbers *l, unsigned long number)
{
    list_of_random_numbers *aux = l;

    while (aux != NULL && aux->number != number)
        aux = aux->next;

    return aux;
}

void delete(list_of_random_numbers *l)
{
    list_of_random_numbers *aux = l;
    
    while (aux != NULL) {
        l = l->next;
        free(aux);
        aux = l;
    }

    free(aux);
}

unsigned long achar_periodo(unsigned long seed)
{
    list_of_random_numbers *list = init();
    list_of_random_numbers *aux;
    unsigned long num;
    unsigned long periodo = 0;

    lcrandom_seed(seed);

    list->number = lcrandom();

    for (int i = 0; i < RANGE; ++i) {
        num = lcrandom();
        aux = search(list, num);

        if (aux != NULL) break;

        add(list, num);
        periodo++;
    }

    delete(list);

    return periodo;
}