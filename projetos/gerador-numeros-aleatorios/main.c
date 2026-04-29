/* Nome: Matheus Carvalho Garcia
 * Data: 13/04/2026
 *
 * 
 */

#include <stdio.h>
#include "src/lcrandom/lcrandom.h"
#include "src/histograma/histograma.h"
#include "src/periodo/periodo.h"

#define SEED 0

int main(void)
{
    lcrandom_seed(SEED);

    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());

    printf("\nmax number: %ld \n", lcrandom_max());

    gerar_histograma();

    unsigned long periodo = achar_periodo(SEED);
    
    printf("Periodo da seed (%ld): %ld\n", SEED, periodo);

    return (0);
}