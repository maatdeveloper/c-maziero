#include <stdio.h>
#include <stdlib.h>
// ex 01 - ponteiros para funcoes

#define VECSIZE 100

int maior_int (const void* a, const void* b);
int maior_double (const void* a, const void* b);
int maior_struct (const void* a, const void* b);

struct pessoa {
    char inicial;
    int idade;
};

int main(void)
{
    int vec_i[VECSIZE];
    int (*m_i) ();

    double vec_d[VECSIZE];
    int (*m_d) ();
    
    struct pessoa vec_s[VECSIZE];
    int (*m_s) ();

    m_i = maior_int;
    m_d = maior_double;
    m_s = maior_struct;

    int i;
    char ch = 97;
    // ex 'a'
    for (i = 0; i < VECSIZE; ++i) {
        vec_i[i] = rand() % 10000;
    }

    qsort(vec_i, VECSIZE, sizeof (int), m_i);
    for (i = 0; i < VECSIZE; ++i) {
        printf(" %d", vec_i[i]);
    }

    puts("\n");
    // ex 'b'
    for (i = 0; i < VECSIZE; ++i) {
        vec_d[i] = (double) rand() / 10000;
    }

    qsort(vec_d, VECSIZE, sizeof (double), m_d);
    for (i = 0; i < VECSIZE; ++i) {
        printf(" %.4lf", vec_d[i]);
    }

    puts("\n");
    // ex 'c'
    for (i = 0; i < VECSIZE; ++i) {
        if (ch >= 122) ch = 97;
        
        struct pessoa aux;
        aux.inicial = ch;
        aux.idade = rand() % 80;

        ch++;
        vec_s[i] = aux;
    }

    qsort(vec_s, VECSIZE, sizeof (struct pessoa), m_s);
    for (i = 0; i < VECSIZE; ++i) {
        printf(" %c", vec_s[i].inicial);
    }

    puts("\n");
    return EXIT_SUCCESS;
}

int maior_int (const void* a, const void* b)
{
    int *x, *y;

    x = (int*) a;
    y = (int*) b;

    if (*x > *y) return  1;
    if (*x < *y) return -1;

    return 0;
}

int maior_double(const void* a, const void* b)
{
    double *x, *y;

    x = (double*) a;
    y = (double*) b;

    if (*x > *y) return  1;
    if (*x < *y) return -1;

    return 0;
}

int maior_struct(const void* a, const void* b)
{
    struct pessoa *x, *y;

    x = (struct pessoa*) a;
    y = (struct pessoa*) b;

    if (x->idade > y->idade) return  1;
    if (x->idade < y->idade) return -1;

    return 0;
}