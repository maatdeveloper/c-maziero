/* Nome: Matheus Carvalho Garcia
 * Data: 13/04/2026
 *
 * main.c: Ponto de entrada do gerador de numeros aleatorios
 */

/* system includes */
#include <stdio.h>
#include <stdlib.h>

/* project includes */
#include "src/lcrandom/lcrandom.h"
#include "src/histograma/histograma.h"
#include "src/periodo/periodo.h"
#include "src/input/input.h"

void input_correto();

int main(int argc, char **argv)
{
    unsigned long seed = 0;
    unsigned long a;
    unsigned long c;
    unsigned long m;
    enum input in;

    if (argc > 1) {
        switch (argc) {
            case INPUT_SEED:
                in = validar_input(argc, argv);

                if (in == ERR) {
                    input_correto();
                } else {
                    seed = atol(argv[1]);
                }

                break;

            case INPUT_A:
                in = validar_input(argc, argv);

                if (in == ERR) {
                    input_correto();
                } else {
                    seed = atol(argv[1]);
                    a = atol(argv[2]);
                }

                lc_params(in, a, NO_PARAMS, NO_PARAMS);
                break;

            case INPUT_C:
                in = validar_input(argc, argv);

                if (in == ERR) {
                    input_correto();
                } else {
                    seed = atol(argv[1]);
                    a = atol(argv[2]);
                    c = atol(argv[3]);
                }

                lc_params(in, a, c, NO_PARAMS);
                break;

            case INPUT_M:
                in = validar_input(argc, argv);

                if (in == ERR) {
                    input_correto();
                } else {
                    seed = atol(argv[1]);
                    a = atol(argv[2]);
                    c = atol(argv[3]);
                    m = atol(argv[4]);
                }

                lc_params(in, a, c, m);
                break;

            default:
                input_correto();
                break;
        }
    }

    if (in == ERR) exit(1);
    lcrandom_seed(seed);

    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());
    printf("random number: %ld \n", lcrandom());

    printf("\nmax number: %ld \n", lcrandom_max());

    gerar_histograma();

    unsigned long periodo = achar_periodo(seed);
    
    printf("Periodo da seed (%ld): %ld\n", seed, periodo);

    return (0);
}