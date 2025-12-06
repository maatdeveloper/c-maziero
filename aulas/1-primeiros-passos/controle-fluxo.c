#include <stdio.h>
#include <stdlib.h>

void ife();
void switche();
void whiler();
void forin();
void gotos();

int main() {
    ife();
    whiler();
    forin();
    gotos();
    
    return 0;
}

void ife() {
    int num = 5;

    if (num > 10) {
        printf("Maior que 10\n");
    } else if (num > 5) {
        printf("Maior que 5\n");
    } else {
        printf("buxa kkj\n");
    }

    num = num < 10 ? 10 : num;
    printf("%d\n", num);
}

void switche() {
    char letra = 'C';

    switch (letra)
    {
        case 'C':
            printf("%s programming\n", letra);
            break;
        default:
            printf("%s sla kk\n", letra);
            break;
    }
    printf("%s\n", letra);
}

void whiler() {
    int num = 0;

    printf("While\n");
    while (num < 10) {
        printf("%d ", num);
        num++;
    }

    printf("\nDo While\n");
    do {
        num--;
        printf("%d ", num);
    } while (num > 0);

    printf("\n");
}

void forin() {
    printf("For\n");

    for (int i=0; i < 10; i++) {
        printf("%d ", i);
    }
    
    printf("\n");
}

void gotos() {
    goto PT2;
    printf("lalala n sei oq");

    PT2:
    printf("pulei kkj\n");

    exit(0);
}