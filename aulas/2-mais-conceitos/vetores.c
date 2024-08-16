#include <stdio.h>

#define TAMANHO 10

int main() {
    int vetor[TAMANHO] = {46, 35, 64, 21, 65, 32, 12, 53, 98, 23};
    int matriz[3][3] = {{0,1,2},
                        {1,2,3},
                        {2,3,4}};

    for (int i=0; i<TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    for (int c=0; c<3; c++) {
        for (int m=0; m<3; m++) {
            printf("%d ", matriz[c][m]);
        }
        printf("\n");
    }

    return 0;
}