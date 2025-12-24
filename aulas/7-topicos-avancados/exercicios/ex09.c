#include <stdio.h>
#include <stdlib.h>
// ex 02 - union

typedef union {
    unsigned int u;
    int i;
} integer;

int main(void)
{
    integer i;

    printf("Digite algum valor negativo: ");
    scanf("%d", &i.i);
    getchar();

    if (i.i >= 0) {
        printf("Numero NEGATIVO (-)\n");
        return EXIT_FAILURE;
    } 
    
    printf("Seu valor unsigned: %u\n", i.u);

    return EXIT_SUCCESS;
}