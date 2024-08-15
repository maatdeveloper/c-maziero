#include <stdio.h>
#include <stdbool.h>

int main() {
    //Tipos inteiros (desconsiderando signed e unsigned) char para caracteres da tabela ASCII
    char coritiba = 1;
    short pequeno = 10;
    int medio = 100;
    long athletico = 1000;
    printf("char %d bytes\nshort %d bytes\nint %d bytes\nlong %d bytes\n", sizeof(coritiba),
                                                                           sizeof(pequeno),
                                                                           sizeof(medio),
                                                                           sizeof(athletico));

    //Tipos decimais (desconsiderando signed e unsigned)
    float baixo = 100.0f;
    double alto = 10000.0f;
    printf("float %d bytes\ndouble %d bytes\n", sizeof(baixo), sizeof(alto));

    //Tipo booleano (implementado apartir de C99 pela stdbool), 1 para verdadeiro 0 para false
    bool verdade = false;
    printf("bool %d bytes\n", sizeof(verdade));
    return 0;
}