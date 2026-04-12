/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* programa principal */
int main ()
{
  struct racional r1, r2, r_sum, r_sub, r_mul, r_div;
  int i, n, max;
  srand (0); /* use assim, com zero */

  printf("Digite um valor para n (max: 100): ");
  if (scanf("%d", &n) == -1) {
    fprintf(stderr, "Erro de leitura!\n");
    return 1;
  }

  printf("Digite o maior numero sorteavel (max: 30): ");
  if (scanf("%d", &max) == -1) {
    fprintf(stdout, "Erro de leitura!\n");
    return 1;
  }

  if (n < 1 || n > 100)     return 1;
  if (max < 1 || max > 30)  return 1;

  /* a completar! */
  for (i = 0; i < n; i++) {
    fprintf(stdout, "%d: ", i);

    r1 = sorteia_r(-max, max);
    r2 = sorteia_r(-max, max);

    imprime_r(r1);
    fprintf(stdout, " ");
    imprime_r(r2);
    fprintf(stdout, "\n");

    if (!valido_r(r1) || !valido_r(r2)) {
      fprintf(stdout, "NUMERO INVALIDO\n");
      return 1;
    }

    r_sum = soma_r(r1, r2);
    r_sub = subtrai_r(r1, r2);
    r_mul = multiplica_r(r1, r2);
    r_div = divide_r(r1, r2);

    if (!valido_r(r_div)) {
      fprintf(stdout, "DIVISAO INVALIDA\n");
      return 1;
    }

    // soma
    imprime_r(r1);
    printf(" + ");
    imprime_r(r2);
    printf(": ");
    imprime_r(r_sum);
    printf("\n");

    // subtração
    imprime_r(r1);
    printf(" - ");
    imprime_r(r2);
    printf(": ");
    imprime_r(r_sub);
    printf("\n");

    // multiplicacao
    imprime_r(r1);
    printf(" * ");
    imprime_r(r2);
    printf(": ");
    imprime_r(r_mul);
    printf("\n");

    // divisao
    imprime_r(r1);
    printf(" / ");
    imprime_r(r2);
    printf(": ");
    imprime_r(r_div);
    printf("\n");

    printf("\n");
  }

  return (0) ;
}
