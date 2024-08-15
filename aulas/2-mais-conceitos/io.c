#include <stdio.h>

int main() {
    int alala;
    char letra;

    printf("Sai no terminal\n"); //Saída de dados
    scanf("%d", &alala); //Entrada de dados (usamos um ponteiro '&' para apontar no endereço em que esta alala)
    letra = getchar(); //Entrada de dados tipo char
    putchar('c'); //Saida de dados tipo char (???)

    return 0;
}