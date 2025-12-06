#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}
int subtracao(int a, int b) {
    return a - b;
}
//protótipo
long fatorial(int n);

int main() {
    printf("fatorial: %d\n", fatorial(5));
    return 0;
}

long fatorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * fatorial(n-1);
}