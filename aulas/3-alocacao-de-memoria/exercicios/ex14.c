#include <stdio.h>
#include <stdlib.h>
// ex 4 - alocar matriz

int main(void) {
    int ***mat;
    int soma, altu, larg, prof;

    fprintf(stdout, "Digite 3 valores nesse padrão: x x x\n");
    fprintf(stdout, "> ");
    scanf("%d %d %d", &altu, &larg, &prof);

    if ((!altu) || (!larg) || (!prof)) {
        fprintf(stdout, "Nenhum valor pode ser 0\n");
        exit(1);
    }

    soma = altu + larg + prof;

    mat = (int***) malloc(altu * sizeof(int**));

    if (!mat) {
        fprintf(stderr, "Erro ao tentar alocar altura da matriz\n");
        exit(1);
    }

    for (int i=0; i<altu; i++) {
        mat[i] = (int**) malloc(larg * sizeof(int*));

        if (!mat[i]) {
            fprintf(stderr, "Erro ao tentar alocar largura da matriz\n");

            for (int j=0; j<i; j++) free(mat[j]);
            free(mat);

            exit(1);
        }
    }

    for (int i=0; i<altu; i++) {
        for (int j=0; j<larg; j++) {
            mat[i][j] = (int*) malloc(prof * sizeof(int));

            if (!mat[i][j]) {
                fprintf(stderr, "Erro ao tentar alocar profundidado da matriz\n");

                for (int k=0; k<i; k++) {
                    for (int l=0; l<j; l++) {
                        free(mat[k][l]);
                    }
                    free(mat[k]);
                }
                free(mat);

                exit(1);
            }
        }
    }

    for (int i=0; i<altu; i++) {
        for (int j=0; j<larg; j++) {
            for (int k=0; k<prof; k++) {
                mat[i][j][k] = soma;
            }
        }
    }

    fprintf(stdout, "Matriz[%d][%d][%d] = %d + %d + %d = %d\n", altu,
                                                                larg,
                                                                prof,
                                                                altu,
                                                                larg,
                                                                prof,
                                                                soma);

    for (int i=0; i<altu; i++)                                                                 
        for (int j=0; j<larg; j++)
            free(mat[i][j]);

    for (int i=0; i<altu; i++)
        free(mat[i]);

    free(mat);
    mat = NULL;

    return 0;
}