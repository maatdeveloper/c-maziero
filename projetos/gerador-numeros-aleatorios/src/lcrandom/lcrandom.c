/* Nome: Matheus Carvalho Garcia
 * Data: 13/04/2026
 *
 * lcrandom.c: implementação das funções definidas em 'lcrandom.h'
 */

#include "lcrandom.h"

struct lcrandom {
    unsigned long seed;
    unsigned long a;
    unsigned long c;
    unsigned long m;
};

struct lcrandom lcr = {.seed = 0,
                       .a = 40692,
                       .c = 127,
                       .m = 10000000};

unsigned long x;

unsigned long lcrandom ()
{
    x = (lcr.a * x + lcr.c) % lcr.m;

    return x;
}

void lcrandom_seed (unsigned long s)
{
    if (s > lcr.m)  lcr.seed = 0;
    else            lcr.seed = s;

    x = lcr.seed;
}

void lcrandom_parms (unsigned long A, unsigned long C, unsigned long M)
{
    lcr.a = A; lcr.c = C; lcr.m = M;
}

unsigned long lcrandom_max ()
{
    return lcr.m;
}