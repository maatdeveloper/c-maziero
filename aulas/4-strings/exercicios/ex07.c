#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ex 7 - strings

#define SIZE 100

void format_string(char *s);
int valid_char(char ch);

int main(void)
{
    char *str;

    str = (char*) malloc(SIZE * sizeof(char));

    if (!str) {
        fprintf(stderr, "Erro ao tentar alocar memoria\n");
        return EXIT_FAILURE;
    }

    printf("Digite algo: ");
    scanf("%99[^\n]", str);
    getchar();

    printf("String antes: %s\n", str);
    format_string(str);
    printf("String depois: %s\n", str);

    free(str);
    str = NULL;

    return EXIT_SUCCESS;
}

void format_string(char *s)
{
    char ch_l = '[';
    char ch_r = ']';
    char ch;
    int i = 0, j;

    if (s[i] == '\0') {
        return;
    }

    while (s[i] != '\0') {
        if (!valid_char(s[i])) {
            ch = s[i];

            for (j=SIZE-2; j>i; j--) {
                //if (valid_char(s[j]))
                s[j+2] = s[j];
            }

            s[i] = ch_l;
            i++;
            s[i] = ch;
            i++;
            s[i] = ch_r;
        }

        i++;
    }
}

int valid_char(char ch)
{
    return isalnum((unsigned char) ch) || ch == ' ' || ch == '\0';
}