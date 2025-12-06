#include <stdio.h>
#include <string.h>
// ex 1 - strings

int main(void)
{
    char string[100];
    int i;

    printf("Digite algo: ");
    scanf("%99[^\n]", string);
    
    printf("Sua entrada invertida: ");

    for (i = strlen(string); i > 0; i--)
        putchar(string[i-1]);
    
    printf("\n");

    return 0;
}