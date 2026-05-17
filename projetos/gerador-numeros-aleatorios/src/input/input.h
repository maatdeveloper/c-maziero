/* Nome: Matheus Carvalho Garcia
 * Data: 14/05/2026
 *
 * input.h: validação de input
 */

#ifndef __INPUT__
#define __INPUT__

#define NO_PARAMS 0
#define INPUT_SEED 2
#define INPUT_A 3
#define INPUT_C 4
#define INPUT_M 5

enum input {
    S,
    SA,
    SAC,
    SACM,
    ERR,
};

// Retorna o valor adequado de acordo com a entrada para lcrandom trabalhar corretamente
enum input validar_input(int argc, char **argv);

// Define os parametros de lcrandom
void lc_params(enum input in, long a, long c, long m);

// Mensagem de erro
void input_correto();

#endif