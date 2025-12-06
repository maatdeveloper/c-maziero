#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ex 13 - strings multibyte

#define STRING_SIZE 1024

char* utf8strn(char* s, int n);

int main(void)
{   
    char str[STRING_SIZE];
    char* ch;
    int pos;

    if (!setlocale(LC_CTYPE, "pt-BR.utf8"))
        fprintf(stderr, "Erro ao tentar definir locale\n");

    printf("Dê sua entrada: ");
    if (scanf("%1023[^\n]", str) != 1) {
        fprintf(stderr, "Nao foi possivel guardar a entrada\n");
        return EXIT_FAILURE;
    }
    getchar();

    printf("Posicao a procurar: ");
    if (scanf("%d", &pos) != 1) {
        fprintf(stderr, "Nao foi possivel guardar a entrada\n");
        return EXIT_FAILURE;
    }
    getchar();

    ch = utf8strn(str, pos);
    printf("%c esta na posicao %d\n", *ch, pos);

    return EXIT_SUCCESS;
}

char* utf8strn(char* s, int n)
{
    if (n <= 0) return NULL;

    char* ptr = s;
    int char_count = 0;

    while (*ptr != '\0') {
        char_count++;

        if (char_count == n) return ptr;

        unsigned char byte = (unsigned char)*ptr;
        size_t bytes_to_advance = 0;

        if (byte <= 0x7F)
            bytes_to_advance = 1;
        else if ((byte & 0xE0) == 0xC0)
            bytes_to_advance = 2;
        else if ((byte & 0xF0) == 0xE0)
            bytes_to_advance = 3;
        else if ((byte & 0xF8) == 0xF0)
            bytes_to_advance = 4;
        else
            bytes_to_advance = 1;

        ptr += bytes_to_advance;
    }   

    return NULL;
}   