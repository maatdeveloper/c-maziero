#include <stdio.h>
// ex 1 - funcoes

double quadrado(int num, int exp);
void troca(int *a, int *b);
int comparar(int a, int b);
int maior(int arr[]);

int main() {
    //ex1
    double quad = quadrado(2, 5);
    printf("%f\n", quad);

    //ex2
    int a = 5;
    int b = 10;
    troca(&a, &b);
    printf("a: %d b: %d\n", a, b);

    //ex3
    int result = comparar(63, 21);
    printf("a maior que b? %d\n", result);

    //ex4
    int vetor[5] = {5, 4, 8, 5, 3};
    int mai = maior(vetor);
    printf("maior: %d\n", mai);

    return 0;
}

double quadrado(int num, int exp) {
    double valor = num * 1.0;
    if (exp == 0) {
        return 1.0;
    }
    if (num == 0) {
        return 0.0;
    }
    
    for (int i=1; i<exp; i++) {
        valor = valor * num;
    }

    return valor;
}

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int comparar(int a, int b) {
    if (a > b) {
        return 1;
    }
    if (a < b) {
        return -1;
    }

    return 0;
}

int maior(int arr[]) {
    int m = arr[0];

    for (int i=0; i<5; i++) {
        if (m < arr[i]) {
            m = arr[i];
        }
    }

    return m;
}