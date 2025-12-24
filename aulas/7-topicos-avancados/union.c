#include <stdio.h>
#include <stdlib.h>
typedef struct{
    union {
        short  short_val;
        int    int_val;
        long   long_val;
        float  float_val;
        double double_val;
    };
    enum { SHORT, INT, LONG, FLOAT, DOUBLE } type ;
} numeric_t;
  
// imprime tipo numérico
void print_num (numeric_t n)
{
    switch (n.type) {
        case SHORT  : printf ("%d", n.short_val)   ; break;
        case INT    : printf ("%d", n.int_val)     ; break;
        case LONG   : printf ("%ld", n.long_val)   ; break;
        case FLOAT  : printf ("%f", n.float_val)   ; break;
        case DOUBLE : printf ("%lf", n.double_val) ; break;
        default     : printf ("NaN");
    }
}
  
int main(void)
{
    numeric_t a;
  
    a.short_val = 119;
    a.type = SHORT;
    print_num (a);
    printf ("\n");
  
    a.long_val = 3451212796756;
    a.type = LONG;
    print_num (a);
    printf ("\n");
  
    a.double_val = 3.141592653589793;
    a.type = DOUBLE;
    print_num (a);
    printf ("\n");

    return EXIT_SUCCESS;
}

