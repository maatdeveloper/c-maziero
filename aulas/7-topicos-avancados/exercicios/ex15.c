#include <stdio.h>
#include <stdlib.h>
// ex 05 - operacoes com bits

int numero_bits(unsigned int num);
void print_bits(unsigned int num);

int main(void)
{
    unsigned int num;

    printf("Digite um numero: ");
    scanf("%u", &num);
    getchar();

    printf("%u:\t", num);
    print_bits(num);
    printf("Numero de bits ligados: %d\n", numero_bits(num));

    return EXIT_SUCCESS;
}

void print_bits(unsigned int num)
{
    int i;

    for (i = 31; i >= 0; i--) {
        (num >> i ) & 1 ? putchar('1') : putchar('0');
        if (i % 8 == 0) putchar(' ');
    }

    putchar('\n');
}

int numero_bits(unsigned int num)
{
    unsigned int count = 0;
    int i;

    for (i = 31; i >= 0; i--) {
        (num >> i) & 1 ? count++ : count;
    }

    return count;
}