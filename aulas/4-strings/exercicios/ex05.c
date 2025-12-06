#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ex 5 - strings

#define SIZE 100

void clean_string(char *s);
int valid_char(char ch);

int main(void)
{
    char *str;

    str = (char*) malloc(SIZE * sizeof (char));

    if (!str) {
        fprintf(stderr, "Erro ao tentar alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite qualquer coisa: ");
    scanf("%99[^\n]", str);

    printf("String antes: %s\n", str);
    clean_string(str);
    printf("String depois: %s\n", str);

    free(str);
    str = NULL;

    return 0;
}

void clean_string(char *s)
{   
    int i = 0, j;
    
    while (s[i] != '\0') {
        if (!valid_char(s[i])) {
            for (j=i; j<SIZE; j++) {
                if (s[j+1] == '\0') {
                    s[j] = s[j+1];
                    break;
                }
                s[j] = s[j+1];
            }
        }
        else {
            i++;
        }
    }
}

int valid_char(char ch)
{
    return isalnum((unsigned char)ch) || ch == ' ';
}