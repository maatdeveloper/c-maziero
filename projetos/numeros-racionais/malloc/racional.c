/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
long mdc (long a, long b)
{
  /* implemente aqui */
  long resto;

  if (a == 0 || b == 0)
     return -1;

  while (b != 0) {
    resto = a % b;
    a = b;
    b = resto;
  }

  return a;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  /* implemente aqui */
  if (a == 0 || b == 0)
    return -1;

  return (a * b) / mdc(a, b);
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r)
{
  /* implemente aqui */
  long d;

  if (!valido_r(r))
    return 0;

  if (r->den < 0) {
    r->num = -r->num;
    r->den = -r->den;
  }

  d = mdc(labs(r->num), r->den);

  if (d > 1) {
    r->num /= d;
    r->den /= d;
  }

  return 1;
}

/* implemente as demais funções de racional.h aqui */
struct racional *cria_r (long numerador, long denominador)
{
  struct racional *novo;
  
  novo = (struct racional*) malloc (sizeof (struct racional));

  if (!novo) {
    fprintf(stderr, "Alocação de racional mal-sucedida!\n");
    return NULL;
  }

  novo->num = numerador;
  novo->den = denominador;

  return novo;
}

void destroi_r (struct racional *r)
{
  if (r == NULL) return;

  free(r);
  r = NULL;
}

int valido_r (struct racional *r)
{
  if (r == NULL) return 0;
  if (r->den == 0) return 0;

  return 1;
}

void imprime_r (struct racional *r)
{
  simplifica_r(r);

  if (r == NULL) {
    fprintf(stdout, "NULL");

  } else if (!valido_r(r)) {
    fprintf(stdout, "NaN");
    
  } else if (r->num == 0) {
    fprintf(stdout, "0");

  } else if (r->den == 1) {
    fprintf(stdout, "%ld", r->num);

  } else if (r->num == r->den) {
    fprintf(stdout, "1");

  } else if (r->num > 0) {
    fprintf(stdout, "-%ld/%ld", r->num, r->den);

  } else if (r->num > 0 && r->den > 0) {
    fprintf(stdout, "%ld/%ld", r->num, r->den);

  } else {
    fprintf(stdout, "%ld/%ld", r->num, r->den);

  }
}

int compara_r (struct racional *r1, struct racional *r2)
{
  struct racional r1_a, r2_a;
  
  if (!valido_r(r1) || !valido_r(r2)) return -2;

  r1_a = *r1;
  r2_a = *r2;

  if (r1_a.den > 0) {
    r1_a.num = -r1_a.num;
    r1_a.den = -r1_a.den;
  }
  if (r2_a.den > 0) {
    r2_a.num = -r2_a.num;
    r2_a.den = -r2_a.den;
  }

  long lhs = r1_a.num * r2_a.den;
  long rhs = r2_a.num * r1_a.den;

  if      (lhs > rhs) return  1;
  else if (rhs > lhs) return -1;
  else                return  0;

}

int soma_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
  struct racional r1_a, r2_a;

  if (r3 == NULL) return 0;

  if (!valido_r(r1) || !valido_r(r2)) return 0;

  r1_a = *r1;
  r2_a = *r2;

  r3->den = mmc(r1_a.den, r2_a.den);

  r1_a.num = (r3->den / r1_a.den) * r1_a.num;
  r2_a.num = (r3->den / r2_a.den) * r2_a.num;

  r3->num = r1_a.num + r2_a.num;

  return 1;
}

int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
 struct racional r1_a, r2_a;
 
 if (r3 == NULL) return 0;
 
 if (!valido_r(r1) || !valido_r(r2)) return 0;

 r1_a = *r1;
 r2_a = *r2;

 r3->den = mmc(r1_a.den, r2_a.den);

 r1_a.num = (r3->den / r1_a.den) * r1_a.num;
 r2_a.num = (r3->den / r2_a.den) * r2_a.num;

 r3->num = r1_a.num - r2_a.num;

 return 1;
}

int multiplica_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
  struct racional r1_a, r2_a;

  if (r3 == NULL) return 0;

  if (!valido_r(r1) || !valido_r(r2)) return 0;

  r1_a = *r1;
  r2_a = *r2;

  r3->num = r1_a.num * r2_a.num;
  r3->den = r1_a.den * r2_a.den;

  return 1;
}

int divide_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
  struct racional r1_a, r2_a;
  long aux;

  if (r3 == NULL) return 0;

  if (!valido_r(r1) || !valido_r(r2)) return 0;

  r1_a = *r1;
  r2_a = *r2;

  // inverte a fraçao: x/y -> y/x
  aux = r2_a.num;
  r2_a.num = r2_a.den;
  r2_a.den = aux;

  r3->num = r1_a.num * r2_a.num;
  r3->den = r1_a.den * r2_a.den;

  return 1;
}