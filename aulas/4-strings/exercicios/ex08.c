#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
// ex 8 - strings

#define STRING_SIZE 100
#define WORD_SIZE 20

int busca(const char *agulha, const char *palhero);
int str_size(const char *str);

int main(void)
{   
    char *str;
    char *str_slice;
    int indc;

    str = (char*) malloc(STRING_SIZE * sizeof(char));
    str_slice = (char*) malloc(WORD_SIZE * ( sizeof(char)));

    if (!str || !str_slice) {
        fprintf(stderr, "Erro ao tentar alocar memoria\n");
        return EXIT_FAILURE;
    }

    printf("Digite algo: ");
    scanf("%99[^\n]", str);
    getchar();

    printf("O que voce deseja encontrar: ");
    scanf("%99[^\n]", str_slice);
    getchar();
    
    putchar('\n');
    indc = busca(str_slice, str);

    printf("Sua entrada: %s\n", str);
    printf("Palavra procurada: %s\n", str_slice);
    printf("Posicao: ");

    if (indc >= 0)
        printf("%d\n", (indc+1));

    if (indc == -1)
        printf("Nao encontrada\n");
    
    if (indc == -2)
        printf("Erro inesperado\n");

    free(str);
    free(str_slice);
    str = NULL;
    str_slice = NULL;

    return EXIT_SUCCESS;
}

int busca(const char *agulha, const char *palhero)
{
    int indc;
    int i = 0;
    int j;
    int size;
    bool continua;

    if (palhero == NULL || agulha == NULL)
        return -2;

    if (palhero[i] == '\0' || agulha[i] == '\0')
        return -1;

    size = str_size(agulha);
    while (palhero[i] != '\0') {
        indc = i;
        continua = true;

        for (j=0; j<size; j++) {
            continua = agulha[j] == palhero[j+i] ? true : false;

            if (!continua) break;
        }
        
        if (continua)
            return indc;

        i++;
    }

    return -1;
}

int str_size(const char *str)
{   
    int i = 0;
    while (str[i] != '\0') i++;

    return i;
}