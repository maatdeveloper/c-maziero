#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// ex 2 - funcao main

int main(int argc, char **argv, char **envp)
{
    FILE* file;

    if (argc != 2) {
        perror("Use: .\\exists <path>\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    
    if (!file) return 1;
    
    fclose(file);
    return 0;
}