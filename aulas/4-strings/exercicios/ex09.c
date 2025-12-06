#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ex 9 - strings

#define STRING_SIZE 100

size_t my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);
void my_strcat(char *dest, const char *src);

int main(void)
{
    const char *str = "C Programming";
    char *str_cp;

    str_cp = (char*) malloc(STRING_SIZE * sizeof(char));
    if (!str_cp)
        return EXIT_FAILURE;
    
    for (int i=0; i<1000000; i++)
        my_strlen(str);
    // real     0m0, 019s
    // user     0m0, 018s
    // sys      0m0, 001s
    
    for (int j=0; j<1000000; j++)
        my_strcpy(str_cp, str);
    // real     0m0, 026s
    // user     0m0, 024s
    // sys      0m0, 002s

    for (int c=0; c<1000000; c++)
        my_strcat(str_cp, str);
    // real     0m0, 024s
    // user     0m0, 023s
    // sys      0m0, 001s

    free(str_cp);
    str_cp = NULL;

    return EXIT_SUCCESS;
}

size_t my_strlen(const char *str)
{
    size_t size = 0;
    while (str[size] != '\0') size++;

    return size;
}

void my_strcpy(char *dest, const char *src)
{   
    while ((*dest++ = *src++));
}

void my_strcat(char *dest, const char *src)
{   
    char *aux = dest;
    while (*aux != '\0') aux++;

    while ((*aux++ = *src++));
}