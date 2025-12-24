#include <stdio.h>
#include <stdlib.h>
// ex 04 - operacoes com bits

int mod_16(unsigned int num) { return num & 0xF; }
int div_16(unsigned int num) { return num >> 0x4; }

int main(void)
{
    unsigned int num;

    printf("Digite um numero: ");
    scanf("%u", &num);
    getchar();

    printf("%d / 16: %d\n", num, div_16(num));
    printf("%d mod 16: %d\n", num, mod_16(num));

    return EXIT_SUCCESS;
}
