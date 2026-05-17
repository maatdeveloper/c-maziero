/* Nome: Matheus Carvalho Garcia
 * Data: 14/05/2026
 *
 * input.c: implemetação das funções de input.h
 */

/* system includes */
#include <stdio.h>

/* project includes */
#include "input.h"
#include "../lcrandom/lcrandom.h"

enum input validar_input(int argc, char **argv)
{
    enum input in = S;
    int i;
    long num;

    switch (argc) {
        case INPUT_SEED:
            if (sscanf(argv[1], "%ld", &num) == 1) {
                if (num >= 0)
                    in = S;
                else
                    in = ERR;

            } else {
                in = ERR;
            }

            break;

        case INPUT_A:
            for (i = 1; i < INPUT_A; i++) {
                if (sscanf(argv[i], "%ld", &num) == 1) {
                    if (num < 0) {
                        in = ERR;
                        break;
                    }

                } else {
                    in = ERR;
                    break;
                }
            }
            
            if (in != ERR) {
                in = SA;
            }

            break;

        case INPUT_C:
            for (i = 1; i < INPUT_C; i++) {
                if (sscanf(argv[i], "%ld", &num) == 1) {
                    if (num < 0) {
                        in = ERR;
                        break;
                    }

                } else {
                    in = ERR;
                    break;
                }
            }
            
            if (in != ERR) {
                in = SAC;
            }

            break;

        case INPUT_M:
            for (i = 1; i < INPUT_M; i++) {
                if (sscanf(argv[i], "%ld", &num) == 1) {
                    if (num < 0) {
                        in = ERR;
                        break;
                    }

                } else {
                    in = ERR;
                    break;
                }
            }
            
            if (in != ERR) {
                in = SACM;
            }

            break;

        default:
            in = ERR;
            break;
    }

    return in;
}

void lc_params(enum input in, long a, long c, long m)
{
    switch (in) {
        case SA:
            lcrandom_parms(a, NO_PARAMS, NO_PARAMS);
            break;

        case SAC:
            lcrandom_parms(a, c, NO_PARAMS);
            break;

        case SACM:
            lcrandom_parms(a, c, m);
            break;

        default:
            lcrandom_parms(NO_PARAMS, NO_PARAMS, NO_PARAMS);
            break;
    }
}

void input_correto()
{
    fprintf(stderr, "Use: ./lcr (seed) (a) (c) (m)\n\nSOMENTE NUMEROS INTEIROS! MAIORES QUE ZERO (exceto seed)!\n");
}