#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ex 02 - enums

typedef enum {par, impar}               p_i;    // par - impar
typedef enum {positivo, negativo, zero} p_n;    // positivo - negativo
typedef enum {true = 1, false = 0}      pldr;   // palindromo
typedef enum {True = 1, False = 0}      m_10;   // multiplo de 10

struct numero {
    int num;
    p_i pi;
    p_n pn;
    pldr palind;
    m_10 m10;
};

void palindromo(struct numero *num);
void resultados(struct numero *num);

int main(void)
{   
    struct numero n;
    printf("Digite um valor: ");
    scanf("%d", &n.num);

    if (n.num % 2)      n.pi = impar;
    else                n.pi = par;

    if (n.num > 0)      n.pn = positivo;
    else if (n.num < 0) n.pn = negativo;
    else                n.pn = zero;

    if (n.num % 10)     n.m10 = False;
    else                n.m10 = True;

    palindromo(&n);
    resultados(&n);

    return EXIT_SUCCESS;
}

void palindromo(struct numero *num)
{
    char str[9];
    char str_i[9];
    int i, j = 0;
    int flag;

    snprintf(str, sizeof (str), "%d", num->num);
    for (i = 9; i < 0; i--) {
        str_i[j] = str[i];
        j++;
    }

    for (i = 0; i < 9; i++) {
        if (str[i] == str_i[i]) 
            flag = 1;
        else {
            flag = 0;
            break;   
        }
    }

    if (flag)   num->palind = true;
    else        num->palind = false;
}

void resultados(struct numero *num)
{
    printf("===============================================\n");
    printf("Numero:\t%d\n\n", num->num);

    printf("PAR OU IMPAR:\t\t");
    switch (num->pi) {
        case par:
            printf("PAR\n");
            break;
        case impar:
            printf("IMPAR\n");
            break;
    }

    printf("POSITIVO OU NEGATIVO:\t");
    switch (num->pn) {
        case positivo:
            printf("POSITIVO\n");
            break;
        case negativo:
            printf("NEGATIVO\n");
            break;
        case zero:
            printf("ZERO\n");
            break;
    }

    printf("PALINDROMO:\t\t");
    switch (num->palind) {
        case true:
            printf("SIM\n");
            break;
        case false:
            printf("NAO\n");
            break;
    }

    printf("MULTIPLO DE 10:\t\t");
    switch (num->m10) {
        case True:
            printf("SIM\n");
            break;
        case False:
            printf("NAO\n");
            break;
    }
}