#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ex 07 parte 01 - arquivos binarios

#define ARQUIVO "numeros.dat"
#define MINIMAL_SIZE 100

int main(void)
{
    FILE* file;
    int i;
    int size;
    int ret;

    file = fopen(ARQUIVO, "a");
    if ( !file )
    {
        perror("Erro ao tentar abrir arquivo\n");
        return EXIT_FAILURE;
    }

    srand(clock());

    printf("Quantos numeros aleatorios deseja gerar? (minimo: 100) ");
    scanf("%d", &size);
    getchar();

    if (size < 100)
        size = MINIMAL_SIZE;
    
    long int nums[size];

    for (i = 0; i < size; ++i)
        nums[i] = rand() % 10000;

    ret = fwrite(nums, sizeof(long int), size, file);
    if ( ret )
        printf("Dados gravados com sucesso!\n");
    else {
        perror("Erro ao gravar dados\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);
    return EXIT_SUCCESS;
}