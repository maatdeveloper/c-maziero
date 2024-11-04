#include <stdio.h>
#include <stdlib.h>

int *vetor; //ponteiro que vai apontar pra memoria alocada
int *arrey;
int tam;


void *safe_malloc(unsigned int size);
void safe_free(void *ptr);
int main() {
    tam = 10;
    vetor = malloc(tam * sizeof(int)); // int(32 bits) entao 10 * 4b = 40b alocados na heap
    vetor = realloc(vetor, 10 * sizeof(int));
    arrey = calloc(10, sizeof(int)); 

    if (!vetor || !arrey) {
        printf("Erro ao alocar vetor!\n");
        exit(1);
    }

    for (int i=0; i<tam; i++) {
        vetor[i] = i;
    }
    for (int j=0; j<tam; j++) {
        printf("%d ", vetor[j]);
    }
    printf("\n");
    for (int n=0; n<tam; n++) {
        printf("%d ", arrey[n]);
    }
    printf("\n");

    free(vetor); //libera a memoria alocada na heap
    vetor = NULL;
    free(arrey);
    arrey = NULL;

    return 0;
}

void *safe_malloc(unsigned int size) {
    void *ptr;

    ptr = malloc(size);

    if (!ptr) {
        fprintf(stderr, "malloc of %d bytes failed\n", size);
        exit(1);
    }

    memset(ptr, 0, size); //preenche a memoria alocada com zeros

    return (ptr);
}

void safe_free(void *ptr) {
    void **ptr_aux = (void**) ptr;
    
    if (ptr_aux && *ptr_aux) {
        free(*ptr_aux);
        *ptr_aux = NULL;
    }
}