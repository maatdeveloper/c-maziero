#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
// ex 11 - strings multibyte

static const unsigned char ISO_TO_ASCII_MAP[] = {
    // 160-191: Símbolos/Controles (geralmente mantidos ou substituídos por '?' ou espaço)
    ' ', '!', 'c', 'L', 'a', 'Y', '|', 'S', 'a', 'G', 'a', 'B', 'a', 'T', 'z', 'Z',
    ' ', '!', 'c', 'L', 'a', 'Y', '|', 'S', 'a', 'G', 'a', 'B', 'a', 'T', 'z', 'Z',

    // 192-255: Caracteres acentuados
    // A A A A A A AE C E E E E I I I I D N O O O O O x U U U U Y P B a a a a a ae c e e e e i i i i d n o o o o o / u u u u y p y
    'A', 'A', 'A', 'A', 'A', 'A', 'A', 'C', 'E', 'E', 'E', 'E', 'I', 'I', 'I', 'I', 
    'D', 'N', 'O', 'O', 'O', 'O', 'O', '*', 'U', 'U', 'U', 'U', 'Y', 'P', 'B', 'a',
    'a', 'a', 'a', 'a', 'a', 'a', 'c', 'e', 'e', 'e', 'e', 'i', 'i', 'i', 'i', 'd',
    'n', 'o', 'o', 'o', 'o', 'o', '/', 'u', 'u', 'u', 'u', 'y', 'p', 'y', '?'
};

#define SIZE 100

void iso_to_ascii(unsigned char *str_i, unsigned char *str_a);
unsigned char convert_char(unsigned char ch);

int main(void)
{   
    char *locale;
    unsigned char str_iso[SIZE];
    unsigned char str_ascii[SIZE];

    locale = setlocale(LC_CTYPE, "pt_BR.iso88591");

    if (!locale)
        fprintf(stderr, "Nao foi possivel definir o locale\n");

    printf("Conversor de texto ISO-8859-1 para ASCII\n\n");

    printf("Digite qualquer coisa: ");
    scanf("%99[^\n]", str_iso);
    getchar();

    iso_to_ascii(str_iso, str_ascii);
    printf("Seu texto no padrão ISO: %s\n", str_iso);
    printf("Seu texto no padrão ASCII: %s\n", str_ascii);

    return EXIT_SUCCESS;
}

void iso_to_ascii(unsigned char *str_i, unsigned char *str_a)
{
    while (*str_i != '\0') {
        *str_a = convert_char(*str_i);
        
        str_a++;
        str_i++;
    }

    *str_a++ = '\0';
}

unsigned char convert_char(unsigned char ch)
{
    if (ch <= 127)
        return ch;
    
    if (ch >= 160 && ch <= 255)
        return ISO_TO_ASCII_MAP[ch - 160];

    return '?';
}