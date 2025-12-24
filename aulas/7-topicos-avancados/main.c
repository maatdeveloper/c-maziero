#include <stdio.h>

//padrao C ANSI | int main(int argc, char **argv);
//padrao Apple (MacOS, iOS) | int main(int argc, char **argv, char **envp, char **apple);

//padrao UNIX-like (Linux, FreeBSD, Solaris etc) e Windows
int main(int argc, char **argv, char **envp) {
    //argc = numero de argumentos
    //argv = argumentos passados num array de char*
    //envp = variaveis de ambiente, no formato chave=valor

    int i;

    printf("Numero de argumentos: %d\n", argc);

    for (i=0; i<argc; i++) {
        printf("argv[%d] %s\n", i, argv[i]);
    }

    return 0;
}