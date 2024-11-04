#include <stdio.h>
#include <stdlib.h>

#define LIN 4
#define COL 6

void alocacao_unica();
void vetor_de_ptr();
void vetor_ptr_separados();
void area_unica_vetor();

int main() {
    alocacao_unica();
    vetor_de_ptr();
    vetor_ptr_separados();
    area_unica_vetor();

    return 0;
}

void alocacao_unica() {
    int *matriz;
    int i, j;

    matriz = malloc(LIN * COL * sizeof(int));

    for (i=0; i<LIN; i++) {
        for (j=0; j<COL; j++) {
            matriz[(i*COL) + j] = 0;
        }
    }

    for (i=0; i<LIN; i++) {
        for (j=0; j<COL; j++) {
            printf("%d ", matriz[(i*COL) + j]);
        }
        printf("\n");
    }

    free(matriz);
    matriz = NULL;
}

void vetor_de_ptr() {
    int **matriz;
    int i, j;

    matriz = malloc(LIN * sizeof(int*));

    for (i=0; i<LIN; i++) {
        matriz[i] = malloc(COL * sizeof(int));
    }

    for (i=0; i<LIN; i++) {
        for (j=0; j<COL; j++) {
            matriz[i][j] = 0;
        }
    }

    for (i=0; i<LIN; i++) {
        free(matriz[i]);
    }

    free(matriz);
    matriz = NULL;
}

void vetor_ptr_separados() {
    int **mat;
    int i, j;

    mat = malloc(LIN * sizeof(int*));
    mat[0] = malloc(LIN * COL * sizeof(int));

    for (i=1; i<LIN; i++) {
        mat[i] = mat[0] + i * COL;
    }
    for (i=0; i<LIN; i++) {
        for (j=0; j<COL; j++) {
            mat[i][j] = 0;
        }
    }

    free(mat[0]);
    free(mat);
    mat = NULL;
}

void area_unica_vetor() {
    int **mat;
    int i, j;

    mat = malloc(LIN * sizeof(int*) + LIN * COL * sizeof(int));
    mat[0] = (int*) (mat+LIN);

    for (i=1; i<LIN; i++) {
        mat[i] = mat[0] + (i * COL);
    }
    for (i=0; i<LIN; i++) {
        for (j=0; j<COL; j++) {
            mat[i][j] = i;
        }
    }

    free(mat);
    mat = NULL;
}