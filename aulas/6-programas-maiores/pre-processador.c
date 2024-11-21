#include <stdio.h> //busca pelos diretorios na lib padrao
#include "lib/cpx.h" //busca pelo diretorio atual

#if defined (__x86_64__) //verifica se o processador é x86_64
    #warning "Generating code for x86_64 processors"
    //macro para sistemas x86_64
#elif defined (__arm__) //verifica se o processador é ARM
    #warning "Generating code for ARM processors"
    //macro para sistemas ARM
#elif defined (__i386__) // agora para x86
    #warning "Generating code for i386 processors"
    //macro para sistemas intel 32-bits
#else
    //aborta a compilação
    #error "Unknown architecture, aborting."
#endif

#define VECSIZE 32
#define SQUARE(x) (x)*(x)

int main() {
    int* tar[VECSIZE];

    // constantes predefinidas
    printf("Dia: %s\nHora: %s\n", __DATE__, __TIME__);
    printf("Arquivo: %s\nLinha: %d\nFuncao: %s\n", __FILE__, __LINE__, __func__);

    #ifdef DEBUG
    printf("Só no debug\n");
    #endif
    printf("Quadrado de 5: %d\n", SQUARE(5));

    return 0;
}