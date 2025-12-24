#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ex 01 - union

#define QUADRADO(x) (x * x)
#define STRING_SIZE 9

typedef struct {
    union {
        int i;
        char ch;
        char str[STRING_SIZE];
    };
} union_t;

typedef enum { INT, CHAR, STRING } type;

void exec(union_t *uni, type tp);
void inverte_string(char str[]);

int main(void)
{   
    union_t uni;

    exec(&uni, INT);
    exec(&uni, CHAR);
    exec(&uni, STRING);

    return EXIT_SUCCESS;
}

void exec(union_t *uni, type tp)
{
    switch (tp) {
        case INT:
            printf("Digite um numero: ");
            scanf("%d", &uni->i);
            getchar();

            printf("Quadrado de %d: %d\n\n", uni->i, QUADRADO(uni->i));
            break;

        case CHAR:
            printf("Digite um caracter qualquer: ");
            uni->ch = getchar();
            getchar();

            if (uni->ch >= 65 && uni->ch <= 90) {
                printf("Caractere %c para minusculo: %c\n\n", uni->ch, tolower(uni->ch));
            }
            else if (uni->ch >= 97 && uni->ch <= 122) {
                printf ("Caractere %c para maiusculo: %c\n\n", uni->ch, toupper(uni->ch));
            }
            else uni->ch = '*';
            break;

        case STRING:
            printf("Digite qualquer coisa: ");
            scanf("%8[^\n]s", uni->str);
            getchar();

            printf("String '%s' ao contrario: ", uni->str);
            inverte_string(uni->str);
            break;
            
        default: break;
    }
}

void inverte_string(char str[])
{
    int i;

    for (i = strlen(str); i >= 0; i--) {
        if (isalnum(str[i])) printf("%c", str[i]);
    }

    printf("\n\n");
}