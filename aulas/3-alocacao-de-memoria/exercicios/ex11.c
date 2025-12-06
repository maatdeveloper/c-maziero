#include <stdio.h>
#include <stdlib.h>
// ex 1 - alocar matrizes

#define LIN 3
#define COL 3

int main(void) {
    int *mat_1, *mat_2, *mat_m;

    mat_1 = (int*) malloc(LIN * COL * sizeof(int));
    mat_2 = (int*) malloc(LIN * COL * sizeof(int));
    mat_m = (int*) malloc(LIN * COL * sizeof(int));

    if (!mat_1) {
        fprintf(stderr, "Erro ao alocar matriz 1\n");
        exit(1);
    }
    if (!mat_2) {
        fprintf(stderr, "Erro ao alocar matriz 2\n");
        exit(1);
    }
    if (!mat_m) {
        fprintf(stderr, "Erro ao alocar matriz 3\n");
        exit(1);
    }
    
    // preenche a matriz 1
    for (int i=0; i<LIN; i++) {
        for (int j=0; j<COL; j++) {
            mat_1[(i*LIN) + j] = (i+1)*(j+1);
        }
    }

    // preenche a matriz 2
    for (int i=0; i<LIN; i++) {
        for (int j=0; j<COL; j++) {
            mat_2[(i*LIN) + j] = (i+1)*(j+1);
        }
    }

    // multiplica as matrizes
    for (int i=0; i<LIN; i++) {
        for (int j=0; j<COL; j++) {
            for (int c=0; c<COL; c++) {
                mat_m[(i*COL) + j] = mat_1[(i*COL) + c] * mat_2[(c*COL) + j];
            }
        }
    }

    // imprime a matriz multiplicada
    for (int i=0; i<LIN; i++) {
        for (int j=0; j<COL; j++) {
            fprintf(stdout, "%d ", mat_m[(i*COL) + j]);
        }
        fprintf(stdout, "\n");
    }

    free(mat_1);
    free(mat_2);
    free(mat_m);
    mat_1 = NULL;
    mat_2 = NULL;
    mat_m = NULL;

    return 0;
}