#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ex 3 - alocar memoria

#define SIZE 10

void *safe_malloc(int size);
void safe_free(void *ptr);
void read_arrey(int *arrey);
void write_arrey(int *arrey);

int main() {
    int *vector;

    vector = safe_malloc(SIZE * sizeof(int));
    write_arrey(vector);
    read_arrey(vector);
    safe_free(&vector);

    return 0;
}

void *safe_malloc(int size) {
    int *ptr;
    ptr = malloc(size);
    
    if (!ptr) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    memset(ptr, 0, size);

    return (ptr);
}

void safe_free(void *ptr) {
    void **ptr_aux = (void**) ptr;

    if (ptr_aux && *ptr_aux) {
        free(*ptr_aux);
        *ptr_aux = NULL;
    }
}

void read_arrey(int *arrey) {
    for (int i=0; i<SIZE; i++) {
        printf("[%d] = %d\n", i, arrey[i]);
    }
}

void write_arrey(int *arrey) {
    for (int i=0; i<SIZE; i++) {
        arrey[i] = (i+1)* 100;
    }
}