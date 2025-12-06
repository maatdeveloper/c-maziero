#include <stdio.h>
#include <string.h>
// ex 02 - string

int main(void)
{
    char str[100];
    int tam = 0, i = 0;

    printf("Digite apenas digite: ");
    if (scanf("%99[^\n]", str) == 1) {
        while (str[i] != '\0')
        {
            tam++;
            i++;
        }
    }
    else {
        printf("Nao foi feita nenhuma entrada!\n");
        return 1;
    }

    printf("Tamanho da string: %d\n", tam);

    return 0;
}