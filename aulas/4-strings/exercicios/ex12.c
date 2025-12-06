#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// ex 12 - strings multibyte

#define STRING_SIZE 1024

size_t iso_to_utf(const unsigned char *str_i, unsigned char *str_u, size_t dest_size);

int main(void)
{   
    char *locale;
    unsigned char str_iso[STRING_SIZE];
    unsigned char str_utf[STRING_SIZE * 2];
    
    locale = setlocale(LC_CTYPE, "pt_BR.utf8");
    if (!locale)
        fprintf(stderr, "Erro ao tentar definir locale\n");
    

    printf("Conversor de texto ISO-8859-1 para UTF-8\n\n");
    scanf("%1023[^\n]", str_iso);
    getchar();

    size_t utf8_tam = iso_to_utf(str_iso, str_utf, sizeof (str_utf));

    printf("Seu texto em ISO-8859-1: %s\n", str_iso);
    printf("Seu texto em UTF-8: %s\n", str_utf);
    printf("Tamanho UTF-8: %zu\n", utf8_tam);
    return EXIT_SUCCESS;
}

size_t iso_to_utf(const unsigned char *str_i, unsigned char *str_u, size_t dest_size)
{
    size_t i = 0;
    size_t j = 0;
    unsigned char ch;

    while (str_i[i] != '\0') {
        ch = str_i[i];

        if (ch <= 0x7f) { // 127 em hexadecimal
            if (j + 1 >= dest_size) return 0;

            str_u[j++] = ch;
        }
        else {
            if (j + 2 >= dest_size) return 0;

            // 1 byte
            str_u[j++] = 0xC0 | (ch >> 6); // 192 emm hexadecimal
            // 2 byte
            str_u[j++] = 0x80 | (ch & 0x3F); // 128 em binario
        }

        i++;
    }

    str_u[j] = '\0';
    
    return j;
}