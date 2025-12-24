#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// ex 1 - funcao main

int main(int argc, char **argv, char **envp)
{
    int params = 0;
    int index = 0;

    while (index < argc) {
        if (argv[index][0] == '-') params++;

        index++;
    }

    return params;
}