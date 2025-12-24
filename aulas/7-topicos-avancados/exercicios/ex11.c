#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
// ex 1 - operacoes com bits

#define LETRA_MINUSCULA(x) (x - 97)
#define VOLTAR_MINUSCULA(x) (x + 97)
#define LETRA_MAIUSCULA(x) (x - 65)
#define VOLTAR_MAIUSCULA(x) (x + 65)

typedef struct {
    unsigned letra      : 5;
    unsigned ate_ult    : 5;
    unsigned e_vogal    : 1;
    unsigned e_maisc    : 1;
    unsigned depois_m   : 1;
    unsigned ult_prim   : 1;
    unsigned vogal_v    : 1;
} letra;

int is_vogal(char ch);
int vogal_vizinha(char ch, int maiusc);
int ate_final(char ch);
void preenche_letra(letra *lt, char ch);
void mostrar_letra(letra *lt);

int main(void)
{
    letra l;
    char ch;

    printf("Digite uma letra: ");
    scanf("%c", &ch);
    getchar();

    if (!isalpha(ch)) {
        printf("Digite uma letra!\n");
        return EXIT_FAILURE;
    }

    system("clear");
    preenche_letra(&l, ch);
    mostrar_letra(&l);

    return EXIT_SUCCESS;
}

void preenche_letra(letra *lt, char ch)
{
    if (islower(ch)) {
        lt->letra = LETRA_MINUSCULA(ch);
        lt->e_vogal = is_vogal(ch);
        lt->e_maisc = 0;
        lt->depois_m = lt->letra > 13 ? 1 : 0;
        lt->ult_prim = lt->letra == 0 || lt->letra == 25 ? 1 : 0;
        lt->vogal_v = vogal_vizinha(lt->letra, lt->e_maisc);
        lt->ate_ult = ate_final(lt->letra);
    }
    else {
        lt->letra = LETRA_MAIUSCULA(ch);
        lt->e_vogal = is_vogal(ch);
        lt->e_maisc = 1;
        lt->depois_m = lt->letra > 13 ? 1 : 0;
        lt->ult_prim = lt->letra == 0 || lt->letra == 25 ? 1 : 0;
        lt->vogal_v = vogal_vizinha(lt->letra, lt->e_maisc);
        lt->ate_ult = ate_final(lt->letra);
    }
}

void mostrar_letra(letra *lt)
{
    if (lt->e_maisc)
        printf("Letra:\t%c\n\n", VOLTAR_MAIUSCULA(lt->letra));
    else
        printf("Letra:\t%c\n\n", VOLTAR_MINUSCULA(lt->letra));

    printf("Vogal:\t\t%c\n", lt->e_vogal ? 'V' : 'F');
    printf("Maiscula:\t%c\n", lt->e_maisc ? 'V' : 'F');
    printf("Depois do 'M':\t%c\n", lt->depois_m ? 'V' : 'F');
    printf("Vogal vizinha:\t%c\n", lt->vogal_v ? 'V' : 'F');
    printf("Quantas letras para o final? %d\n", lt->ate_ult);
}

int ate_final(char ch)
{
    return abs(ch - 25);
}

int vogal_vizinha(char ch, int maiusc)
{
    char aux;

    if (maiusc) aux = VOLTAR_MAIUSCULA(ch);
    else        aux = VOLTAR_MINUSCULA(ch);

    switch (aux) {
        case 'b': return 1;
        case 'B': return 1;
        case 'd': return 1;
        case 'D': return 1;
        case 'f': return 1;
        case 'F': return 1;
        case 'h': return 1;
        case 'H': return 1;
        case 'j': return 1;
        case 'J': return 1;
        case 'n': return 1;
        case 'N': return 1;
        case 'o': return 1;
        case 'O': return 1;
        case 't': return 1;
        case 'T': return 1;
        case 'v': return 1;
        case 'V': return 1;
        default:  return 0;
    }
}

int is_vogal(char ch)
{
    switch (ch) {
        case 'a': return 1;
        case 'A': return 1;
        case 'e': return 1;
        case 'E': return 1;
        case 'i': return 1;
        case 'I': return 1;
        case 'o': return 1;
        case 'O': return 1;
        case 'u': return 1;
        case 'U': return 1;
        default:  return 0;
    }
}