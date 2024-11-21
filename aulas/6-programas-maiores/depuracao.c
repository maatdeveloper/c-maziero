#include <stdio.h>

int fatorial(int num) {
    if (num <= 1) {
        return 1;
    }

    return num * fatorial(num - 1);
}

int main() {
    printf("fatorial de %d é: %d\n", 5, fatorial(5));

    return 0;
}

//compilar com o parametro -g