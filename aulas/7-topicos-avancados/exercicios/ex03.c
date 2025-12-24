#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// ex 3 - funcao main

int main(int argc, char **argv, char **envp)
{
    char **env;
    int count = 0;

    if (argc == 1) return EXIT_FAILURE;

    env = envp;
    while (*env != NULL) {
        printf("%03d: %s\n", count, (*env));

        env++;
        count++;
    }
    
    return EXIT_SUCCESS;
}