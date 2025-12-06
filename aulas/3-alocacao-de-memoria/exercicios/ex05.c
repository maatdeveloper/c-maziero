#include <stdio.h>
#include <stdlib.h>
// ex 1 - alocacao de memoria

int *arrey;
int tam;

int main() {
    printf("Qual deve ser o tamanho do vetor? ");
    scanf("%d", &tam);
    
    arrey = malloc(tam * sizeof(int));

    if (!arrey) {
        fprintf(stderr, "falha ao alocar memoria\n");
        exit(1);
    }

    for (int i=0; i<tam; i++) {
        arrey[i] = (i+1)*tam;
    }
    for (int i=0; i<tam; i++) {
        printf("[%d] : %d\n", i, arrey[i]);
    }

    free(arrey);
    arrey = NULL;

    return 0;
}