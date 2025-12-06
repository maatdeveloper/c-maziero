#include <stdio.h>
#include <stdlib.h>
// ex 2 - alocar memoria

int main(void) {
    int *array, tam;

    printf("Digite o numero de elementos que o vetor deve ter: ");
    scanf("%d", &tam);

    if (tam <= 0) {
        fprintf(stderr, "Valores menores que zeros não são permitidos!\n");
        exit(1);
    }

    array = (int*) malloc(tam * sizeof (int));

    if (!array) {
        fprintf(stderr, "Falha ao tentar alocar %d bytes de memória\n", tam);
        exit(1);
    }

    for (int i=0; i<tam; i++) {
        array[i] = 100 * i;
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);
    array = NULL;

    return 0;
}