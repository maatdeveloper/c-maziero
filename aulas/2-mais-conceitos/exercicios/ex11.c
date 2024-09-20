#include <stdio.h>

#define SIZE 5
#define MAXH 3
#define MAXW 3

void printarrey(int arr[], int tam);
void printmatriz(int arr[][MAXW], int height, int width);
void learrey(int arr[], int tam);
void lematriz(int arr[][MAXW], int height, int width);
void somarrey(int arr1[], int arr2[]);
void bubblesort(int arr[], int tam);
void transpormtz(int arr[][MAXW], int height, int width);

int main() {
    //ex1
    int arr1[SIZE] = {2, 4, 6, 8, 10};
    int arr2[SIZE] = {2, 4, 6, 8, 10};
    somarrey(arr1, arr2);

    //ex2
    int arr[SIZE];
    learrey(arr, SIZE);
    bubblesort(arr, SIZE);
    printarrey(arr, SIZE);

    //ex3
    int matrix[MAXH][MAXW];
    lematriz(matrix, MAXH, MAXW);
    transpormtz(matrix, MAXH, MAXW);

    return 0;
}

void printarrey(int arr[], int tam) {
    for (int i=0; i<tam; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void printmatriz(int arr[][MAXW], int he, int wi) {
    for (int i=0; i<he; i++) {
        for (int j=0; j<wi; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void learrey(int *arr, int tam) {
    for (int i=0; i<tam; i++) {
        printf("Digite um numero: ");
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void lematriz(int arr[][MAXW], int he, int wi) {
    for (int i=0; i<MAXH; i++) {
        for (int j=0; j<MAXW; j++) {
            printf("Digite um valor: ");
            scanf("%d", &arr[i][j]);
        }
    }
}

void somarrey(int *arr1, int *arr2) {
    int arr[SIZE];
    
    for (int i=0; i<SIZE; i++) {
        arr[i] = arr1[i] + arr2[i];
    }

    printarrey(arr, SIZE);
}

void bubblesort(int *arr, int tam) {
    int aux;

    for (int i=0; i<SIZE; i++) {
        for (int c=0; c<SIZE-1; c++) {
            if (arr[c] > arr[c+1]) {
                aux = arr[c];
                arr[c] = arr[c+1];
                arr[c+1] = aux;
            }
        }
    }
}

void transpormtz(int arr[][MAXW], int he, int wi) {
    int mtz[he][wi];
    int aux;

    for (int j=0; j<wi; j++) {
        for (int i=0; i<he; i++) {
            mtz[j][i] = arr[i][j];
        }
    }

    printmatriz(mtz, he, wi);
}