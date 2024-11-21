#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 1024

void escrita();
void leitura();
void fim_do_arquivo();
int main() {
    escrita();
    leitura();
    fim_do_arquivo();

    return 0;
}

void escrita() {
    FILE* file;
    unsigned char c;
    file = fopen("file.txt", "w+");

    if (!file) {
        printf("Erro ao tentar abrir/criar arquivo x!\n");
        exit(1);
    }

    fputs("caracteres ASCII:", file);

    for (c=32; c<128; c++) {
        fputc(c, file);
        fputc(32, file);
    }
    fputc("\n", file);

    fclose(file);
}

void leitura() {
    FILE* arq;
    char line[LINESIZE-1];

    arq = fopen("dados.txt", "r");
    
    if (!arq) {
        perror("Erro ao tentar ler arquivo\n");
        exit(1);
    }

    for (int i=0; i<10; i++) {
        fgets(line, LINESIZE, arq);
        printf("%d: %s\n", i, line);
    }

    fclose(arq);
}

void fim_do_arquivo() {
    FILE* arq;
    int i;
    char line[LINESIZE-1];

    arq = fopen("sla.txt", "r");

    if (!arq) {
        perror("Errou tudo aqui\n");
        exit(1);
    }

    i = 1;
    fgets(line, LINESIZE, arq);
    while (!feof(arq)) {
        printf("%d: %s\n", i, line);
        fgets(line, LINESIZE, arq);
        i++;
    }

    fclose(arq);
}