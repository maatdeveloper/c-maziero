#include <stdio.h>

int main() {
    char palavra[100];
    char* plv;
    int contador;

    scanf("%s", &palavra);
    plv = palavra;

    for (int i=0; i<100; i++) {
        if (*(plv+1)) {
            contador++;
            plv++;        
        }
    }
    contador++;

    printf("Numero de palavras: %d\n", contador);
    return 0;
}