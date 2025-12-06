#include <stdio.h>

int main() {
    int num = 0;

    num += 10; // + para soma, += para atribuição
    num -= 5;  // - para substracao, -= para atribuicao
    num *= 12; // * para multiplicacao, *= para atribuicao
    num /= 4;  // / para divisao, /= para atribuicao
    num = num % 3; // % resto da divisao inteira
    num++; // mais 1
    num--; // menos 1

    // && AND || OR ! NOT
    printf("%d\n", num >= 10 && num >= 12); // maior igual
    printf("%d\n", num <= 5);  // menor igual
    printf("%d\n", num == 7 || num == 4);  // igual
    printf("%d\n", num != 2);  // diferente
    printf("%d\n", !num < 3);   // menor
    printf("%d\n", num > 8);   // maior

    //Operadores binarios (0b para dizermos que o número está em binário)
    int a = 0b00010001; //17
    int b = 0b01100110; //99
    printf("%d\n", a & b);  // AND bit-a-bit
    printf("%d\n", a | b);  // OR binario
    printf("%d\n", a ^ b);  // XOR binario
    printf("%d\n", ~a);     // complemento de 1
    printf("%d\n", a << 2); // Desloca a ESQUERDA n bits
    printf("%d\n", a >> 2); // Desloca a DIREITA n bits

    int *ptr = &num; // * declara um ponteiro, & o endereco de uma variavel
    int op_ter = num > 0 ? 1 : 0; // ? operador ternario, vem apos uma condicao
                                  // se verdadeira, considera antes do ':', se falsa, depois
    printf("%d\n", sizeof num); // Tamanho da variavel em bytes

    return 0;
}