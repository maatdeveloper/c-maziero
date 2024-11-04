#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *stringue;
    char nome[100];
    stringue = "pica murcha";

    puts(stringue);
    scanf("%[^\n]", nome);
    printf("%s\n", nome);

    return 0;
}