#include <stdio.h>
#include <stdlib.h>
// ex 6 - operacoes com bits

int potencia_de_dois(unsigned int num);

int main(void)
{   
    unsigned int num;

    printf("Digite um numero: ");
    scanf("%u", &num);
    getchar();

    printf("%u e uma potencia de 2? %c\n", num, potencia_de_dois(num) ? 'V' : 'F');

    return EXIT_SUCCESS;
}

int potencia_de_dois(unsigned int num)
{   
    /* explicacao:
     * suponhamos que
     * num =     00001000 (8)
     * num - 1 = 00000111 (7)
     * 
     * num & (num - 1) = 00001000
     * logo 'num' é uma pontencia de 2
     */
    return (num > 0) && ((num & (num - 1)) == 0);
}