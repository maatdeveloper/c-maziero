#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ex 04 - string

#define SIZE 100
#define WORDS 10

int main(void)
{
    char **palavras, *aux;

    palavras = (char**) malloc(WORDS * sizeof (char*));

    if (!palavras) {
        printf("Erro ao tentar alocar memoria da lista\n");
        exit(1);
    }

    for (int i=0; i<WORDS; i++) {
        palavras[i] = (char*) malloc(SIZE * sizeof (char));

        if (!palavras[i]) {
            printf("Erro ao alocar memoria da palavra\n");

            for (int j=0; j<i; j++)
                free(palavras[j]);
            free(palavras);
            exit(1);
        }
    }

    for (int i=0; i<WORDS; i++) {
        printf("Digite uma palavra: ");
        scanf("%99[^\n]", palavras[i]);
        getchar();
    }

    for (int i=0; i<WORDS; i++) {
        for (int j=i; j<WORDS; j++) {
            if (strcmp(palavras[i], palavras[j]) > 0) {
                aux = palavras[j];
                palavras[j] = palavras[i];
                palavras[i] = aux;
            }
        }
    }

    printf("Suas entradas ordenadas:\n");
    for (int i=0; i<WORDS; i++)
        puts(palavras[i]);
    
    // liberando memoria
    for (int i=0; i<WORDS; i++)
        free(palavras[i]);
    free(palavras);
    palavras = NULL;

    return 0;
}