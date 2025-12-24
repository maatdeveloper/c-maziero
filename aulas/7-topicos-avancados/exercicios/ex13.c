#include <stdio.h>
#include <stdlib.h>
// ex 3 - operacoes com bits

int maior_que(unsigned int x, unsigned int y);

int main(void)
{   
    unsigned int num;

    printf("Digite um numero: ");
    scanf("%d", &num);
    getchar();

    printf("Maior que 07? %c\n", maior_que(num, 7)  ? 'V' : 'F');
    printf("Maior que 31? %c\n", maior_que(num, 31) ? 'V' : 'F');
    printf("Maior que 63? %c\n", maior_que(num, 63) ? 'V' : 'F');

    return EXIT_SUCCESS;
}

int maior_que(unsigned int x, unsigned int y)
{   
    if (x == y) return 0;

    unsigned int aux;
    unsigned int msb;
    // suponhamos que
    // x = 01110101 (117)
    // y = 01011100 (92)

    aux = x ^ y;
    // operacao xor
    // aux = 00101001 (41)

    aux |= (aux >> 1); // aux = 00111101 (61)
    aux |= (aux >> 2); // aux = 00111111 (63)
    aux |= (aux >> 4); // etc
    aux |= (aux >> 8);
    aux |= (aux >> 16);

    msb = aux & ~(aux >> 1);
    // isola o bit mais significativo
    // aux = 11111111
    // aux >> 1 = 01111111
    // ~(aux >> 1) = 10000000
    // aux & aux = 10000000

    return (x & msb) != 0;
}