#include <stdio.h>
#include <stdlib.h>
// ex 07 parte 3 - arquivo binario

#define ARQUIVO "numeros.dat"

int main(void)
{
    FILE* file;
    long int num;
    int i;

    file = fopen(ARQUIVO, "r");
    if ( !file ) {
        perror("Erro ao tentar abrir arquivo\n");
        return EXIT_FAILURE;
    }

    printf("Os 10 primeros (menores) numeros em %s\n", ARQUIVO);
    for (i = 0; i < 10; ++i) {
        fread(&num, sizeof(long int), 1, file);
        printf("[%2d] = %ld\n", i+1, num);
    }

    puts("\n");
    fseek(file, -1 * (sizeof(long int) * 10), SEEK_END); // reposiciona

    printf("Os 10 ultimos (maiores) numeros em %s\n", ARQUIVO);
    for (i = 0; i < 10; ++i) {
        fread(&num, sizeof (long int), 1, file);
        printf("[%2d] = %ld\n", i+1, num);
    }

    fclose(file);
    return EXIT_SUCCESS;
}