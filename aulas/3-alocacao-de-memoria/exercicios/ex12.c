#include <stdio.h>
#include <stdlib.h>
// ex 2 - alocar matriz

#define LIN 3
#define COL 3
#define SOMA_RESULTADO 15

void imprimir(int **mat);

int main(void) {
    int **mat;
    int soma_l, soma_c, soma_d1=0, soma_d2=0;
    int is_magic = 1;

    // aloca uma vetor de ponteiros
    mat = (int**) malloc(LIN * sizeof(int*));

    if (!mat) {
        fprintf(stderr, "Erro ao tentar alocar uma matriz\n");
        exit(1);
    }

    // aloca um vetor para cada ponteiro alocado anteriormente
    for (int i=0; i<LIN; i++) {
        mat[i] = (int*) malloc(COL * sizeof(int));

        if (!mat[i]) {
            fprintf(stderr, "Erro ao tentar alocar vetor\n");

            for (int j=0; j<i; j++)
                free(mat[j]);
            
            free(mat);
            exit(1);
        }
    }

    // preenche a matriz com o padrao funcional
    // 8 | 1 | 6
    // 3 | 5 | 7
    // 4 | 9 | 2

    mat[0][0] = 8;
    mat[0][1] = 1;
    mat[0][2] = 6;
    mat[1][0] = 3;
    mat[1][1] = 5;
    mat[1][2] = 7;
    mat[2][0] = 4;
    mat[2][1] = 9;
    mat[2][2] = 2;

    imprimir(mat);

    // realize a soma
    for (int i=0; i<LIN; i++) {
        soma_l = 0;
        soma_c = 0;
        for (int j=0; j<COL; j++) {
            soma_l += mat[i][j];
            soma_c += mat[j][i];
        }

        if (soma_l != SOMA_RESULTADO && soma_c != SOMA_RESULTADO) {
            is_magic = 0;
            break;
        }

        soma_d1 += mat[i][i];
        soma_d2 += mat[i][COL - 1 - i];
    }

    if (is_magic && (soma_d1 != SOMA_RESULTADO && soma_d2 != SOMA_RESULTADO)) {
        is_magic = 0;
    }

    if (is_magic) {
        fprintf(stdout, "Matriz verificada: o quadrado E MAGICO e seu resultado e: %d\n", SOMA_RESULTADO);
    } else {
        fprintf(stdout, "Matriz verificada: o quadrado NAO E MAGICO, abortando\n");
    }

    // liberando a memoria
    for (int i=0; i<LIN; i++)
        free(mat[i]);
    free(mat);
    mat = NULL;
    
    return 0;
}

void imprimir(int **mat) {
    for (int i=0; i<LIN; i++) {
        for (int j=0; j<COL; j++) {
            fprintf(stdout, "%d ", mat[i][j]);
        }

        fprintf(stdout, "\n");
    }
}