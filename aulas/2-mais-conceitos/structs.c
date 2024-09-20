#include <stdio.h>
#include <string.h>

struct pessoa
{
    char nome[100];
    unsigned short idade;
    float altura;
};

// & pega o endereço na memoria
// * aponta para um endereço

int main() {
    struct pessoa p1, *p2;

    strcpy(p1.nome, "Matheus Carvalho Garcia"); //uso como ponteiro
    p1.idade = 20;
    p1.altura = 1.83f;

    p2 = &p1;

    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", p1.nome, p1.idade, p1.altura);
    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", (*p2).nome, p2->idade, p2->altura);
    return 0;
}