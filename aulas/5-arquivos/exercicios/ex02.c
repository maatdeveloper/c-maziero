#include <stdio.h>
#include <stdlib.h>
// ex 02 - arquivos de texto

int main(void)
{
    FILE *arq;
    int ch, tot = 0;
    double media, sum = 0.0, val = 0.0;

    arq = fopen("numeros.txt", "r");

    if (!arq) {
        perror("Erro ao tentar abrir arquivo\n");
        return EXIT_FAILURE;
    }

    ch = fscanf(arq, "%lf", &val);
    while (ch != EOF) {
        tot += 1;
        sum += val;
        ch = fscanf(arq, "%lf", &val);
    }

    media = sum / tot;
    
    printf("A medias dos %d valores lidos foi de: %.2f\n", tot, media);
    fclose(arq);

    return EXIT_SUCCESS;
}