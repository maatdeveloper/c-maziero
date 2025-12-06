#include <stdio.h>

int main() {
    int alala;
    char letra;

    printf("Sai no terminal\n"); //Saída de dados
    scanf("%d", &alala); //Entrada de dados (usamos '&' para escrever no endereço em que esta alala)
    letra = getchar(); //Entrada de dados tipo char
    putchar(letra); //Saida de dados tipo char

    return 0;
}