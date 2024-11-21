#include <stdio.h>
#include <stdlib.h>
#include "lib/cpx.h"

int main() {
    cpx_t compx = cpx(14.3, 25.3);

    printf("Complexo: %f - %f \n", compx.r, compx.i);
    return 0;
}

//compile com: gcc -Wall organizar_codigo.c cpx.c -o binario