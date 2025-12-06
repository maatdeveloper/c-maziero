#include <stdio.h>
// ex 4 - ponteiros

#define SIZE 50

int main() {
    char string_1[SIZE], string_2[SIZE], string_concat[SIZE];
    char *ptr, *ptr_concat;

    scanf("%s %s", string_1, string_2);

    ptr_concat = string_concat;
    ptr = string_1;

    while (*ptr != '\0') {
        *ptr_concat = *ptr;
        ptr_concat++;
        ptr++;
    }

    ptr = string_2;
    while (*ptr != '\0') {
        *ptr_concat = *ptr;
        ptr_concat++;
        ptr++;
    }

    ptr_concat++;
    *ptr_concat = '\0';
    ptr = NULL;
    ptr_concat = NULL;

    printf("Dados de entrada concatenados: %s\n", string_concat);

    return 0;
}