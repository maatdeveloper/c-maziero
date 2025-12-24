#include <stdio.h>
#include <stdlib.h>

// bitfields
struct DISK_REGISTER {
    unsigned ready          : 1;
    unsigned error_occured  : 1;
    unsigned disk_spinning  : 1;
    unsigned write_project  : 1;
    unsigned read_loaded    : 1;
    unsigned error_code     : 8;
    unsigned track          : 9;
    unsigned sector         : 5;
    unsigned command        : 5;
};

int main(void)
{   
    short n, b;

    // operaçoes bit a bit
    for (n = 0; n < 256; n++) {
        printf("%3d: ", n);

        for (b = 7; b >= 0; b--) {
            n & (1 << b) ? putchar('1') : putchar('0');
        }

        putchar('\n');
    }

    return EXIT_SUCCESS;
}