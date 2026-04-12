/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
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

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
{
  /* implemente aqui */
  return rand() % (max - min + 1) + min;
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
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

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  /* implemente aqui */
  if (a == 0 || b == 0)
    return -1;

  return (a * b) / mdc(a, b);
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
  /* implemente aqui */
  long d;

  if (!valido_r(r))
    return r;
  
  if (r.den < 0) {
    r.num = -r.num;
    r.den = -r.den;
  }

  d = mdc(labs(r.num), r.den);

  if (d > 1) {
    r.num /= d;
    r.den /= d;
  }

  return r;
}

/* implemente as demais funções de racional.h aqui */

struct racional cria_r(long numerador, long denominador)
{
  struct racional r = {numerador, denominador};
  return r;
}

int valido_r(struct racional r)
{
  return r.den == 0 ? 0 : 1;
}

struct racional sorteia_r (long min, long max)
{
  return cria_r(aleat(min, max), aleat(min, max));
}

void imprime_r (struct racional r)
{
  if (!valido_r(r)) {
    fprintf(stdout, "INVALIDO");
    return;
  }
  if (r.num == 0) {
    fprintf(stdout, "0");
    return;
  }
  if (r.den == 1) {
    fprintf(stdout, "%ld", r.num);
    return;
  }
  if (r.num == r.den) {
    fprintf(stdout, "1");
    return;
  }
  
  r = simplifica_r(r);
  fprintf(stdout, "%ld/%ld", r.num, r.den);
}

struct racional soma_r (struct racional r1, struct racional r2)
{
  struct racional rac;
  long den_ig; 

  den_ig = mmc(r1.den, r2.den);

  rac.den = den_ig;
  
  r1.num = (rac.den / r1.den) * r1.num;
  r2.num = (rac.den / r2.den) * r2.num;

  rac.num = r1.num + r2.num;

  return rac;
}

struct racional subtrai_r (struct racional r1, struct racional r2)
{
  struct racional rac;
  long den_ig; 

  den_ig = mmc(r1.den, r2.den);

  rac.den = den_ig;
  
  r1.num = (rac.den / r1.den) * r1.num;
  r2.num = (rac.den / r2.den) * r2.num;

  rac.num = r1.num - r2.num;

  return rac;
}


struct racional multiplica_r (struct racional r1, struct racional r2)
{
  struct racional rac;

  rac.num = r1.num * r2.num;
  rac.den = r1.den * r2.den;

  return rac;
}

struct racional divide_r (struct racional r1, struct racional r2)
{
  struct racional rac;
  long aux;

  aux = r2.num;
  r2.num = r2.den;
  r2.den = aux;

  rac.num = r1.num * r2.num;
  rac.den = r1.den * r2.den;

  return rac;
}