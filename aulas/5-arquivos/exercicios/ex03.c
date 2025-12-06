#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// ex 03 - arquivos de texto

int main(void)
{
    FILE *arq_min, *arq_mai;
    int read, write;

    arq_min = fopen("minusc.txt", "r");
    arq_mai = fopen("maiusc.txt", "w");

    if (!arq_mai && !arq_min) {
        perror("Erro ao tentar abrir ambos os arquivos\n");
        return EXIT_FAILURE;
    }
    else if (!arq_min) {
        perror("Erro ao tentar abrir o primeiro arquivo\n");
        fclose(arq_mai);
        return EXIT_FAILURE;
    }
    else if (!arq_mai) {
        perror("Erro ao tentar abrir o segundo arquivo\n");
        fclose(arq_min);
        return EXIT_FAILURE;
    }

    read = getc(arq_min);

    while (read != EOF) {
        write = toupper(read);
        fputc((char) write, arq_mai);
        read = getc(arq_min);
    }

    fclose(arq_min);
    fclose(arq_mai);

    return EXIT_SUCCESS;
}