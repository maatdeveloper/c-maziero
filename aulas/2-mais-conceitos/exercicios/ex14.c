#include <stdio.h>
// ex 3 - funcoes

#define SIZE 7

struct Data
{
    int dia, mes, ano;
};


int separa(float num, int *pi, float *pf); //pi = parte inteira | pf = parte fracionaria
int data_set(int d, int m, int a, struct Data *dt);
void data_print(struct Data d);
int max(int v[], int tam, int *maxval, int *maxpos);
void print_array(int arr[]);

int main() {
    // ex 1
    float pf, num = 42.2422;
    int pi;

    if (separa(num, &pi, &pf)) {
        printf("Numero: %f\nParte Inteira: %d\nParte Fracionaria: %f\n", num, pi, pf);
    } else {
        printf("Ocorreu um erro\n");
    }
    printf("\n");

    // ex 2
    struct Data data;

    if (data_set(11, 6, 2004, &data)) {
        data_print(data);
    } else {
        printf("A data esta incorreta\n");
    }
    printf("\n");

    // ex 3
    int vec[SIZE] = {6, 4, 8, 1, 3, 2, 5};
    int max_val, max_pos;

    max(vec, SIZE, &max_val, &max_pos);
    print_array(vec);
    printf("Maior numero: %d\tSua posicao: %d", max_val, max_pos);
    printf("\n");
    
    return 0;
}

int separa(float num, int *pi, float *pf) {
    *pi = (int) num;
    *pf = num - *pi;
    if (num == (*pi + *pf)) {
        return 1;
    }

    return 0;
}

int data_set(int d, int m, int a, struct Data *dt) {
    if (d > 31 || d < 1)
        return 0;

    if (m > 12 || m < 1)
        return 0;

    if (a > 9999 || a < 1)
        return 0;
    
    dt->ano = a;
    dt->mes = m;
    dt->dia = d;

    return 1;
}

void data_print(struct Data d) {
    printf("%02d/%02d/%04d\n", d.dia, d.mes, d.ano);
}

int max(int v[], int tam, int *maxval, int *maxpos) {
    if (tam <= 0) {
        return 0;
    }

    int max = v[0], pos = 0;

    for (int i=0; i<tam; i++) {
        if (max < v[i]) {
            max = v[i];
            pos = i;
        }
    }

    *maxval = max;
    *maxpos = pos;
    return 1;
}

void print_array(int arr[]) {
    for (int i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}