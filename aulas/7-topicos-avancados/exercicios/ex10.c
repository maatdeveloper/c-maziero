#include <stdio.h>
#include <stdlib.h>
// ex 03 - union


typedef union {
    int i;
    unsigned char b[sizeof (int)];
} integer;


int main(void)
{
    integer i;
    unsigned char mod;

    printf("Digite um numero inteiro: ");
    scanf("%d", &i.i);
    getchar();

    mod = i.b[0];
    
    printf("Valor original: %d\n", i.i);
    printf("Modulo de 256 (via %%): %d\n", i.i % 256);
    printf("Modulo de 256 via union: %d\n", mod); // mais eficiente !!!
    
    return EXIT_SUCCESS;
}