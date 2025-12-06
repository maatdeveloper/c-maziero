#include <stdio.h>
#include <string.h>
// ex 03 - string

int main(void)
{
    char ch, str[100];
    int i = 0;

    printf("Digite qualquer coisa em capslock: ");
    scanf("%[^\n]", str);

    printf("Em letras minusculas: ");
    while (str[i] != '\0') {
        ch = str[i];

        if (str[i] > 64 && str[i] < 91) {
            putchar(ch + 32);
        }
        else {
            putchar(ch);
        }

        i++;
    }
    printf("\n");

    return 0;
}