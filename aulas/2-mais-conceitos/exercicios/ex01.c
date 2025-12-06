#include <stdio.h>
// ex 1 -  i/o padrao


int main() {
    int input, soma = 0;
    int maior, menor;
    float media;

    for (int i=0; i<10; i++) {
        printf("Entre com um numero: ");
        scanf("%d", &input);

        if (i == 0) {
            maior = input;
            menor = input;
        }
        
        if (input > maior) {
            maior = input;
        }
        if (input < menor) {
            menor = input;
        }

        soma += input;
    }

    media = soma / 10.0;
    printf("Soma dos valores: %d\nMaior: %d\nMenor: %d\nMedia> %.2f", soma, maior, menor, media);

    return 0;
}