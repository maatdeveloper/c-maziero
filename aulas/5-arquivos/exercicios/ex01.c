#include <stdio.h>
#include <stdlib.h>
// ex 01 - arquivos de texto

int main(void)
{
    FILE *arq;
    int c, tot = 0;

    arq = fopen("dados.txt", "r");

    if (!arq) {
        perror("Erro ao tentar abrir arquivo\n");
        return EXIT_FAILURE;
    }

    c = getc(arq);
    while (c != EOF) {
        tot += 1;
        c = getc(arq);
    }

    printf("Total de caracteres no arquivo 'dados.txt': %d\n", tot);
    fclose(arq);

    return EXIT_SUCCESS;
}