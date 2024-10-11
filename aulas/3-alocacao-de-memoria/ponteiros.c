#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef unsigned short int u8;

int main() {
    u8 *p, *ptr;
    u8 a = 6266;
    u8 b = 3111;
    u8 arrey[SIZE];

    printf("endereco de p: %p\n", &p); //endereço de p
    printf("endereco de a: %p\n", &a); //endereco de b
    printf("endereco de b: %p\n", &b); //endereco de c

    printf("p vale: %p\n", p); // valor de p

    p = &a; //atribui valor a p
    printf("p vale %p\n", p); //le p
    printf("*p vale %d\n", *p); //desrefencencia p

    p = &b;
    printf("p vale %p\n", p);
    printf("*p vale %d\n", *p);

    *p = 500;
    printf("b vale %d\n", b);

    //preenchimento padrao
    for (int i=0; i<SIZE; i++) {
        arrey[i] = 0;
    }

    //preenchimento usando aritmetica de ponteiros
    for (ptr=arrey; p<arrey; p++) {
        *p = 1;
    }

    pointer_to_pointer();
    return 0;
}

void pointer_to_pointer() {
    int a = 231;
    int *pd;  // ponteiro direto
    int **pi; // ponteiro indireto, equivale a int *(*p)
    
    pd = &a;  // pd recebe o endereço de um int
    pi = &pd; // pi recebe o endereço de um ponteiro para int
    
    printf ("a  está em %p e vale %d\n", &a, a);
    printf ("pd está em %p e vale %p\n", &pd, pd);
    printf ("pi está em %p e vale %p\n", &pi, pi);
    
    printf ("*pd  vale %d\n", *pd);
    printf ("*pi  vale %p\n", *pi);
    printf ("**pi vale %d\n", **pi);
}

void strcpy(char *s, char *t)
{
    while ((*s = *t) != "\0") {
        s++;
        t++;
    }
}