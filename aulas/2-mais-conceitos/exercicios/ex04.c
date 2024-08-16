#include <stdio.h>
#include <math.h>

int main() {
    float raiz;
    float log;

    for (int i=1; i<=1000; i++) {
        raiz = sqrt(i);
        log = log10f(i / 1.0);

        printf("%d\t%.4f\t%.4f\n", i, raiz);
    }

    return 0;
}