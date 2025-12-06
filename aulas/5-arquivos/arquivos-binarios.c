#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARQUIVO "numeros.dat"
#define NUMVAL 10

void escrita();
void leitura();

int main(int argc, char *argv[]) {
    escrita();
    leitura();

    return 0;
}

void escrita() {
    FILE* file;
    int i, ret;
    float value[NUMVAL];

    file = fopen(ARQUIVO, "a");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    srand(clock());

    for(i=0; i<NUMVAL; i++) {
        value[i] = random() / 100000.0;
    }

    ret = fwrite(value, sizeof(float), NUMVAL, file);

    if (ret) {
        printf("Arquivos gravados com sucesso!\n");
    } else {
        printf("Erro ao gravar dados.\n");
    }

    fclose(file);
}

void leitura() {
    FILE* arq;
    float value;

    arq = fopen(ARQUIVO, "r");
    if (!arq) {
        perror("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fread(&value, sizeof(float), 1 ,arq);

    while (! feof(arq)) {
        printf("%f\n", value);
        fread(&value, sizeof(float), 1 ,arq);
    }

    fclose(arq);
}