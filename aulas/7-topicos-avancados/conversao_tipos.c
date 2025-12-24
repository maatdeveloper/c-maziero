#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compara_int (const void* a, const void* b);     // conversao de ponteiros void*

int main(void)
{
    /* conversao implicita que o compilador faz para operacoes logicas/aritmeticas
     * ordem da conversao:
     * char < short < int < long < long long < float < double < long double
     */
    char ch;
    int i;
    float f;
    double d;
    char buf[8];

    ch = 10;
    i = ch;     // correto, pois int > char
    f = i;      // depende, float > int, mas a mantissa de float (padrao IEEE 754) vai ate valores de 23 bits

    d = (float) i / ch; // conversao explicita

    //conversao de 'string' para tipos numericos;
    i = atoi("123");

    // conversao de tipos numericos para 'string'
    sprintf(buf, "%d", i);
    printf("%s\n", buf);
    printf("%d\n", compara_int(&i, &ch));

    return EXIT_SUCCESS;
}

int compara_int (const void* a, const void* b)
{
    int *x, *y;
    x = (int*) a;
    y = (int*) b;

    if (*x > *y) return 1;
    if (*x < *y) return -1;

    return 0;
}