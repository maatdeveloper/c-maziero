#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// biblioteca padrao da linguagem C
// oferece funcoes para:
// . interface com o SO
// . manipulacao de strings
// . operacoes matematicas
// . operacoes de busca
// . etc

#define VECSIZE 1024

int main(void)
{   
    unsigned short *vec;

    vec = (unsigned short*) malloc(VECSIZE * sizeof (unsigned short)); // aloca memoria (stdlib)

    if (!vec) { return EXIT_FAILURE; } // macro para retornar códigos de erro (stdlib)

    memset(vec, 0, sizeof (vec)); // preenche com dados (0) no vetor (string)

    for (int i = 0; i < VECSIZE; i++) {
        printf("%d: %d\n", i, vec[i]); // imprime texto na saida padrao (stdout) (stdio)
    }

    free(vec);  // libera a memoria alocada (stdlib)
    vec = NULL; // macro para representar valores nulos (stdilb)
    
    return EXIT_SUCCESS; // macro para retornar uma execucao bem sucessida (stdlib)
}