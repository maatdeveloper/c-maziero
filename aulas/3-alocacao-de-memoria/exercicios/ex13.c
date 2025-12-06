#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ex 3 - alocar matriz

#define NUMBER_OF_WORDS 10 
#define WORD_SIZE 30

void imprimir(char **mat);
void ordenar(char **mat);

int main(void) {
    char **palavras;

    palavras = (char**) malloc(NUMBER_OF_WORDS * sizeof(char*));

    if (!palavras) {
        fprintf(stderr, "Erro ao tentar alocar memoria\n");
        exit(1);
    }

    for (int i=0; i<NUMBER_OF_WORDS; i++) {
        palavras[i] = (char*) malloc(WORD_SIZE * sizeof(char));

        if (!palavras[i]) {
            fprintf(stderr, "Erro ao tentar alocar palavras\n");

            for (int j=0; j<i; j++)
                free(palavras[i]);
            free(palavras);
            exit(1);
        }

        scanf("%s", palavras[i]);
    }
    
    printf("\n");
    printf("\n");

    ordenar(palavras);
    imprimir(palavras);

    for (int c=0; c<NUMBER_OF_WORDS; c++) free(palavras[c]);
    free(palavras);
    palavras = NULL;

    return 0;
}

void imprimir(char **mat) {
    for (int i=0; i<NUMBER_OF_WORDS; i++) {
        printf("%s\n", mat[i]);
    }
}

void ordenar(char **mat) {
    int troca = 0;
    char *tmp;

    for (int i=0; i<NUMBER_OF_WORDS; i++) {
        for (int j=i; j<NUMBER_OF_WORDS; j++) {
            if (strcmp(mat[i], mat[j])>0) {
                troca = 1;
            }

            if (troca) {
                tmp = mat[i];
                mat[i] = mat[j];
                mat[j] = tmp;
                tmp = NULL;
                troca = 0;
            }
        }
    }
}