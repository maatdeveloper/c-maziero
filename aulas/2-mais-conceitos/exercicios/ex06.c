#include <stdio.h>

int main() {
    int arrey[] = {45, 68, 42, 75, 24};
    int tam = sizeof(arrey) / sizeof(arrey[0]);
    int soma = 0;
    float media;

    for (int i=0; i<tam; i++) {
        soma += arrey[i];
    }
    
    media = (float) soma / tam;
    
    printf("média: %f\nmaior que a media: ", media);
    for (int c=0; c<tam; c++) {
        if (arrey[c] > media) {
            printf("%d ", arrey[c]);
        }
    }
    
    printf("\n");
    return 0;
}