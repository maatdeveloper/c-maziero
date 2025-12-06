#include <stdio.h>
#include <stdlib.h>
// ex 6 - alocar memoria

int *alocar_matriz(int lin, int col);
void preencher_matriz(int *mtz, int lin, int col);
void imprimir_matriz(int *mtz, int lin, int col);

int main(void) {
    int *mat, lin, col;

    fprintf(stdout, "Numero de linhas da matriz: ");
    scanf("%d", &lin);
    fprintf(stdout, "Numero de colunas da matriz: ");
    scanf("%d", &col);

    if (lin<=0 || col <=0) {
        fprintf(stdout, "As linhas e/ou colunas deve ser maior que 0\n");
        exit(1);
    }

    mat = alocar_matriz(lin, col);

    if (!mat) {
        exit(1);
    }

    preencher_matriz(mat, lin, col);
    imprimir_matriz(mat, lin, col);

    free(mat);
    mat = NULL;

    return 0;
}

int *alocar_matriz(int lin, int col) {
    int *aux;

    aux = (int*) malloc(lin * col * sizeof(int));

    if (!aux) {
        fprintf(stdout, "Erro ao tentar alocar memoria\n");
        return NULL;
    }

    return aux;
}

void preencher_matriz(int *mtz, int lin, int col) {
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            mtz[(i*col) + j] = i+j;
        }
    }
}

void imprimir_matriz(int *mtz, int lin, int col) {
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            fprintf(stdout, "%d ", mtz[(i*col) + j]);
        }
        fprintf(stdout, "\n");
    }
}