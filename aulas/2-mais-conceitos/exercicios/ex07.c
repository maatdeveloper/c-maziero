#include <stdio.h>
// ex 3 -  vetores

void print_arrey();
int main() {
    int arrey[] = {6, 3, 7, 2, 5, 4, 1, 0, 8, 9};
    int tam = sizeof(arrey) / sizeof(arrey[0]);
    int aux;

    for (int i=0; i<tam; i++) {
        printf("%d ", arrey[i]);
    }
    printf("\n");

    for (int i=0; i<tam-1; i++) {
        for (int c=0; c<tam-i-1; c++) {
            if (arrey[c] > arrey[c+1]) {
                aux = arrey[c];
                arrey[c] = arrey[c+1];
                arrey[c+1] = aux;
            }
        }
    }

    for (int i=0; i<tam; i++) {
        printf("%d ", arrey[i]);
    }
    printf("\n");

    return 0;
}

void print_arrey(int *arr) {
    int tam = sizeof(arr) / sizeof(arr[0]);

    for (int c=0; c<tam; c++) {
        printf("%d ", arr[c]);
    }

    printf("\n");
}