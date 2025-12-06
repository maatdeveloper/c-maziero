#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ex 14 - strings multibyte

int main(void)
{
    const char control_char[] = {
        '0', ' ', ' ', ' ', ' ', ' ', ' ', 'a', 'b', 't', 'n', 'v', 'f', 'r',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' '
    };

    if (!setlocale(LC_CTYPE, "pt_BR.iso88591"))
        fprintf(stderr, "Nao foi possivel definir o locale\n\n");

    printf("TABELA ASCII\n");
    printf("==================================\n");
    printf("char\tint\n");
    for (int i = 0; i < 128; ++i) {
        if (i <= 31)
            printf("\\%c\t%d\n", control_char[i], i);
        else if (i == 127)
            printf("DEL\t%d\n", i);
        else
            printf("%c\t%d\n", i, i);
    }

    printf("\n\n");
    printf("TABELA ISO-8859-1\n");
    printf("==================================\n");
    printf("char\tint\n");
    printf("ASCII\t1..127\n");
    for (int i = 128; i < 256; i++)
        printf("%c\t%d\n", (unsigned char)i, i);


    return EXIT_SUCCESS;
}