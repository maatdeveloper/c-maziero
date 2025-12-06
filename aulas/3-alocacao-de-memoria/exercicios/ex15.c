#include <stdio.h>
#include <stdlib.h>
// ex 5 - alocar matriz

int main(void) {
    int *mat;
    int soma, altu, larg, prof;

    fprintf(stdout, "Digite 3 valores nesse padrão: x x x\n");
    fprintf(stdout, "> ");
    scanf("%d %d %d", &altu, &larg, &prof);

    if (!altu || !larg || !prof) {
        fprintf(stdout, "Nenhum valor pode ser 0\n");
        exit(1);
    }

    soma = altu + larg + prof;

    mat = (int*) malloc(soma * sizeof (int));

    if (!mat) {
        fprintf(stdout, "Erro ao tentar alocar matriz\n");
        exit(1);
    }

    for (int i=0; i<soma; i++) {
        mat[i] = soma;
    }

    fprintf(stdout, "Matriz[%d][%d][%d] = %d + %d + %d = %d\n", altu,
                                                                larg,
                                                                prof,
                                                                altu,
                                                                larg,
                                                                prof,
                                                                soma);

    free(mat);
    mat = NULL;

    return 0;
}