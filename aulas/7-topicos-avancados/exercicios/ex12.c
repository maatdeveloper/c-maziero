#include <stdio.h>
#include <stdlib.h>
// ex 2 - operacoes com bits

int mod_2(int num);
int mod_4(int num);
int mod_16(int num);

int main(void)
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);
    getchar();

    printf("Mod 2: %d\n", mod_2(num));
    printf("Mod 4: %d\n", mod_4(num));
    printf("Mod 16: %d\n", mod_16(num));

    return EXIT_SUCCESS;
}

int mod_2(int num)
{
    return num & 0x1;
}

int mod_4(int num)
{
    return num & 0x3;
}

int mod_16(int num)
{
    return num & 0xF;
}