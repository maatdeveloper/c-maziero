#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
// ex 07 parte 4 - arquivos binarios

#define ARQUIVO "numeros.dat"

int main(void)
{
    struct stat st;

    if (stat(ARQUIVO, &st) == -1) {
        perror("Erro ao preencher estrutura st\n");
        return EXIT_FAILURE;
    }

    printf("Tamanho de %s: ", ARQUIVO);
    printf("%ld bytes\n", (long) st.st_size);

    return EXIT_SUCCESS;
}