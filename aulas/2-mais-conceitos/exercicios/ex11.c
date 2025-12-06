#include <stdio.h>
// ex 7 - vetores

#define COL_A 2
#define LIN_A 3
#define COL_B 3
#define LIN_B 2

void print_matriz(int mtz[][LIN_A]);
void multiplicar_matriz(int mtz_a[][LIN_A], int mtz_b[][LIN_B], int mtz_mtp[][LIN_A]);

int main() {
    int matriz_a[COL_A][LIN_A] = {{2, 2, 2},
                                  {4, 4, 4}};

    int matriz_b[COL_B][LIN_B] = {{1, 1},
                                  {3, 3},
                                  {5, 5}};
    int matriz_mult[COL_B][LIN_A];

    // inicializando matriz_mult
    for (int i=0; i<COL_B; i++) {
        for (int j=0; j<LIN_A; j++) {
            matriz_mult[i][j] = 0;
        }
    }

    multiplicar_matriz(matriz_a, matriz_b, matriz_mult);

    return 0;
}

void print_matriz(int mtz[][LIN_A]) {
    for (int i=0; i<COL_B; i++) {
        for (int j=0; j<LIN_A; j++) {
            printf("%d ", mtz[i][j]);
        }

        printf("\n");
    }
}

void multiplicar_matriz(int mtz_a[][LIN_A], int mtz_b[][LIN_B], int mtz_mtp[][LIN_A]) {
    for (int i=0; i<COL_B; i++) {
        for (int j=0; j<LIN_A; j++) {
            for (int k=0; k<LIN_A; k++) {
                mtz_mtp[i][j] += mtz_a[i][k] * mtz_b[k][j];
            }
        }
    }

    print_matriz(mtz_mtp);
}