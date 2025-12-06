#include <stdio.h>
#include <stdlib.h>
// ex 07 parte 2 - arquivos binarios

#define ARQUIVO "numeros.dat"
#define MINIMAL_SIZE 100

void vector_print(const long int *v, int size);
void quick_sort(long int *v, long int ini, long int fim);
long int partition(long int *v, long int ini, long int fim);

int main(void)
{
    FILE* file;
    long int num;
    long int *vector;
    long int *tmp;
    int size = MINIMAL_SIZE + 1;
    int index = 0;
    int ret;

    // Abre o arquivo;
    file = fopen(ARQUIVO, "r");
    if ( !file )
    {
        perror("Erro ao tentar abrir arquivo\n");
        return EXIT_FAILURE;
    }

    // Aloca o tamanho minimo do vetor
    vector = (long int*) malloc(size * sizeof(long int));
    if ( !vector )
    {
        perror("Erro ao tentar alocar memoria\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Le cada numero do arquivo ate chegar no final
    do {
        // Realoca o dobro do tamanho anterior se os numeros
        // no arquivo forem maiores do que o vetor possa armazenar
        if (index >= size) {
            size *= 2;

            tmp = (long int*) realloc(vector, size * sizeof(long int));
            if ( !tmp )
            {
                perror("Erro ao tentar realocar memoria\n");
                fclose(file);
                free(vector);
                return EXIT_FAILURE;
            }

            vector = tmp;
        }
        
        // Atribui o valor lido ao vetor
        fread(&num, sizeof(long int), 1, file);
        vector[index] = num;

        index++;
    } while ( !feof(file) );
    

    //vector_print(vector, size);
    quick_sort(vector, 0, size);
    //vector_print(vector, size);

    // Grava os dados ordenados no arquivo
    file = freopen(ARQUIVO, "w", file);
    ret = fwrite(vector, sizeof (long int), size, file);
    
    if ( ret ) {
        printf("Dados ordenados gravados com sucesso!\n");
    }
    else {
        perror("Erro ao gravar novos dados!\n");
        fclose(file);
        free(vector);
        return EXIT_FAILURE;
    }

    // Liberar arquivo(s) e memoria utilizados
    fclose(file);
    free(vector);

    return EXIT_SUCCESS;
}

void vector_print(const long int *v, int size)
{
    int i;

    printf("Numeros armazenados no arquivo:\n\n");
    for (i = 0; i < size; ++i)
        printf("[%3d] = %ld\n", i, v[i]);
}

void quick_sort(long int *v, long int ini, long int fim)
{
    long int pivo;

    if (fim > ini) {
        pivo = partition(v, ini, fim);
        quick_sort(v, ini, pivo - 1);
        quick_sort(v, pivo + 1, fim);
    }
}

long int partition(long int *v, long int ini, long int fim)
{
    long int esq, dir, pivo, aux;
    esq = ini;
    dir = fim;
    pivo = v[ini];

    while(esq < dir) {
        while (esq <= fim && v[esq] <= pivo) {
            esq++;
        }
        while (dir >= 0 && v[dir] > pivo) {
            dir--;
        }

        if (esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }

    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;
}