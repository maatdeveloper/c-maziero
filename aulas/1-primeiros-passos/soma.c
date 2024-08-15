#include <stdio.h>

int main() {
    int a, b, soma;
    float media;

    a = 15;
    b = 12;
    soma = a + b;
    media = soma / 2.0;

    printf("A soma de %d e %d vale %d\n", a, b, soma);
    printf("A soma de %d e %d vale %.2f\n", a, b, media);

    return 0;
}