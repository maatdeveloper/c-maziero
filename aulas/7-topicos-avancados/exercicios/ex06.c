#include <stdio.h>
#include <stdlib.h>
// ex 03 - enums

#define STRING_SIZE 100

// '-' caracteres nao usados (exceto o 45)
const char ascii_table[] = {'0', '-', '-', '-', '-', '-', '-', 'a', 'b', 't', 'n', 'v', 'f', 'r', '-', '-',
                          '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
                          ' ', '!', '"', '#', '$', '%', '&', '\'','(', ')', '*', '+', ',', '-', '.', '/',
                          '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
                          '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                          'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\',']', '^', '_',
                          '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                          'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', 'D'};

typedef enum {letra, numero, pontuacao, especial} char_t;
typedef enum {maiscula, minuscula, NA} letra_t;
typedef enum {vogal, consoante, na} letra_ty;

// nao pensei muito nos nomes dos enums :p
struct tipo_char {
    char ch;
    char_t tipo;
    letra_t tipo_l;
    letra_ty tipo_ly;
};

void tipo_caracter(char ch, struct tipo_char *ch_t);

int main(void)
{
    struct tipo_char ch;
    char str[STRING_SIZE];
    int i;

    printf("Digite algo: ");
    scanf("%99[^\n]", str);
    getchar();

    printf("\n\n=====================================================\n");
    for (i = 0; i < STRING_SIZE; ++i) {
        if (str[i] == '\0') break;

        tipo_caracter(str[i], &ch);
        printf("Caracter: %c\tTipo: ", ch.ch);

        switch (ch.tipo) {
            case letra:
                printf("LETRA\t");

                switch (ch.tipo_l) {
                    case maiscula:
                        printf("MAISCULA\t");
                        break;

                    case minuscula:
                        printf("MINUSCULA\t");
                        break;

                    case NA:
                        printf("NA\n");
                        break;
                }

                switch (ch.tipo_ly) {
                    case vogal:
                        printf("VOGAL\n");
                        break;

                    case consoante:
                        printf("CONSOANTE\n");
                        break;
                    
                    case na:
                        printf("NA\n");
                        break;
                }
                break;

            case numero:
                printf("NUMERO\n");
                break;

            case pontuacao:
                printf("PONTUACAO\n");
                break;

            case especial:
                printf("ESPECIAL\n");
                break;

            default:
                printf("DESCONHECIDO\n");
                break;
        }
    }

    return EXIT_SUCCESS;
}

void tipo_caracter(char ch, struct tipo_char *ch_t)
{
    ch_t->ch = ch;

    if (ch >= 49 && ch <=  57)  {
        ch_t->tipo = numero;
        ch_t->tipo_l = NA;
        ch_t->tipo_ly = na;

        return;
    }
    if (ch >= 65 && ch <=  90) {
        ch_t->tipo = letra;
        ch_t->tipo_l = maiscula;

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') ch_t->tipo_ly = vogal;
        else ch_t->tipo_ly = consoante;

        return;
    }
    if (ch >= 97 && ch <= 122) {
        ch_t->tipo = letra;
        ch_t->tipo_l = minuscula;

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ch_t->tipo_ly = vogal;
        else ch_t->tipo_ly = consoante;

        return;
    }
    
    if (ch == '.' || ch == '?' || ch == '!' || ch == ';' || ch == ':') {
        ch_t->tipo = pontuacao;
        ch_t->tipo_l = NA;
        ch_t->tipo_ly = na;

        return;
    }
    
    ch_t->tipo = especial;
    ch_t->tipo_l = NA;
    ch_t->tipo_ly = na;
}