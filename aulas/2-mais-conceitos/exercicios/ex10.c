#include <stdio.h>
// ex 6 - vetores

#define MAX_COL 3
#define MAX_LIN 3

void print_matriz(int mtz[][MAX_LIN]);
void transpor_matriz(int mtz[][MAX_LIN], int mtz_t[][MAX_LIN]);

int main() {
    int matriz[MAX_COL][MAX_LIN] = {{1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9}};
    int matriz_transp[MAX_LIN][MAX_COL];

    printf("Matriz original: \n");
    print_matriz(matriz);

    printf("\n\n");
    printf("Matriz tranposta: \n");
    transpor_matriz(matriz, matriz_transp);

    return 0;
}

void print_matriz(int mtz[][MAX_LIN]) {
    for (int i=0; i<MAX_COL; i++) {

        for (int j=0; j<MAX_LIN; j++) {
            printf("%d ", mtz[i][j]);

        }

        printf("\n");
    }
}

void transpor_matriz(int mtz[][MAX_LIN], int mtz_t[][MAX_LIN]) {
    for (int i=0; i<MAX_LIN; i++) {
        for (int j=0; j<MAX_COL; j++) {
            mtz_t[j][i] = mtz[i][j];
        }
    }

    print_matriz(mtz_t);
}