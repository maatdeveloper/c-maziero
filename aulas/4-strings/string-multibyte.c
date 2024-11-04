#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    char *locale;
    char *frase;
    
    locale = setlocale(LC_CTYPE, "");
    frase = "Ola 😃";

    if (locale) {
        printf("Locale atual é %s\n", locale);
    } else {
        fprintf(stderr, "Não foi possivel obter o locale atual\n");
    }

    printf("%s\n", frase);
    
    return 0;
}