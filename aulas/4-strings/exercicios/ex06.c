#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ex 6 - strings

#define SIZE 100

void clean_string(char *s);

int main(void)
{
    char *str;

    str = (char*) malloc(SIZE * sizeof(char));

    if (!str) {
        fprintf(stderr, "Erro ao tentar alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite algo: ");
    scanf("%99[^\n]", str);
    getchar(); // limpa '\n'

    printf("String antes: %s\n", str);
    clean_string(str);
    printf("String depois: %s\n", str);

    free(str);
    str = NULL;

    return EXIT_SUCCESS;
}

void clean_string(char *s)
{
    int i = 0;
    int j = 1;

    if (s[i] == '\0') {
        return;
    }

    while (s[j] != '\0') {
        if (s[j] != s[i]) {
            i++;
            s[i] = s[j];
        }
        
        j++;
    }

    s[i+1] = '\0';
}