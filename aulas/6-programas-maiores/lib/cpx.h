#ifndef __CPX__
#define __CPX__

typedef struct {
    float r, i;
} cpx_t;

cpx_t cpx(float r, float i);

cpx_t cpx_sum(cpx_t a, cpx_t b);
cpx_t cpx_sub(cpx_t a, cpx_t b);
cpx_t cpx_mul(cpx_t a, cpx_t b);
cpx_t cpx_div(cpx_t a, cpx_t b);

float cpx_real(cpx_t c);
float cpx_imag(cpx_t c);

char* cpx_str(cpx_t s);

#endif
