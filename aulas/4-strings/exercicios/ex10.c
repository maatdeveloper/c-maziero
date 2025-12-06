#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
// ex 10 - strings

#define STRING_SIZE 100

int palindromo(char *str);
void format_string(char *str);
bool valid_char(char ch);

int main(void)
{
    char str[STRING_SIZE];

    printf("Digite algo: ");
    scanf("%99[^\n]", str);
    getchar();

    if (palindromo(str))
        printf("E um palindromo\n");
    else
        printf("Nao e um palindromo\n");

    return EXIT_SUCCESS;
}

int palindromo(char *str)
{
    int i = 0;
    int j;

    if (str[i] == '\0') return 0;

    format_string(str);
    j = strlen(str);

    while (i <= j) {
        if (str[i] != str[j-1])
            return 0;

        i++;
        j--;
    }

    return 1;
}

void format_string(char *str)
{   
    int read_idx = 0;
    int write_idx = 0;
    char ch;

    while (str[read_idx] != '\0') {
        ch = str[read_idx];

        if (isalnum((unsigned char) ch)) {
            str[write_idx] = tolower((unsigned char) ch);
            write_idx++;
        }

        read_idx++;
    }

    str[write_idx] = '\0';
}

bool valid_char(char ch)
{
    return isalnum((unsigned char) ch) ? true : false;
}