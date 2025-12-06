#include <stdio.h>
#include <stdlib.h>
// ex 5 - alocar memoria

int main(void) {
    int *mat, lin, col;

    fprintf(stdout, "Numero de linhas da matriz: ");
    scanf("%d", &lin);
    fprintf(stdout, "Numero de colunas da matriz: ");
    scanf("%d", &col);

    if (lin<=0 || col<=0) {
        fprintf(stdout, "A linha e a coluna deve ser maior que zero\n");
        exit(1);
    }

    mat = (int*) malloc(lin * col * sizeof (int));

    if (!mat) {
        fprintf(stdout, "Erro ao tentar alocar memoria\n");;
        exit(1);
    }

    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            mat[(i*col) + j] = i+j;
        }
    }

    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            fprintf(stdout, "%d ", mat[(i*col) + j]);
        }
        fprintf(stdout, "\n");
    }

    free(mat);
    mat = NULL;

    return 0;
}