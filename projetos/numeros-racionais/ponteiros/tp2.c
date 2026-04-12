/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "racional.h"

#define VECSIZE 100
#define ARQUIVO "entrada1.txt"
#define LINESIZE 8
/* coloque aqui as funções auxiliares que precisar neste arquivo */

void ler_racional(const char *buff, struct racional *rac);
void limpar_racionais(struct racional vec[], int size);
void ordenar_racionais(struct racional vec[], int size);
struct racional somar_racionais(struct racional vec[], int size);

/* programa principal */
int main ()
{
  /* a completar! */
  FILE* file;
  struct racional vec[VECSIZE];
  struct racional aux;
  struct racional soma;
  char buff[LINESIZE];
  int n;

  memset(vec, 0, sizeof (struct racional) * VECSIZE);

  file = fopen(ARQUIVO, "r");
  if (!file) {
    fprintf(stdout, "Erro ao tentar abrir arquivo!\n");
    return 1;
  }

  // le a primeira linha e converte para um inteiro
  n = atoi(fgets(buff, LINESIZE, file));

  // le os dados de 'entrada1.txt' e armazena nas estruturas do vetor
  for (int i = 0; i < n; ++i) {
    aux = vec[i];
    fgets(buff, LINESIZE, file);
    ler_racional(buff, &aux);
    vec[i] = aux;
  }

  fprintf(stdout, "VETOR= ");
  for (int i=0; i < n; ++i) {
    imprime_r(vec[i]);
    putc(' ', stdout);
  }

  limpar_racionais(vec, n);
  putc('\n', stdout);
  fprintf(stdout, "VETOR= ");
  for (int i=0; i < n; ++i) {
    if (valido_r(vec[i])) {
      imprime_r(vec[i]);
      putc(' ', stdout);
    }
  }
 
  ordenar_racionais(vec, n);
  putc('\n', stdout);
  fprintf(stdout, "VETOR= ");
  for (int i=0; i < n; ++i) {
    if (valido_r(vec[i])) {
      imprime_r(vec[i]);
      putc(' ', stdout);
    }
  }

  soma = somar_racionais(vec, n);
  putc('\n', stdout);
  fprintf(stdout, "SOMA= ");
  imprime_r(soma);

  putc('\n', stdout);
  return (0) ;
}

void ler_racional(const char *buff, struct racional *rac)
{
  #define SIZE 4
  char snum[SIZE];
  char sden[SIZE];
  char *aux = NULL;
  char *aux_num = NULL;
  char *aux_den = NULL;

  memset(snum, '\0', sizeof(char) * SIZE);
  memset(sden, '\0', sizeof(char) * SIZE);

  aux = buff;
  aux_num = snum;
  aux_den = sden;

  while (aux) {
    while (aux_num) {
      if (*aux == ' ' || *aux == '\n' || *aux == '\0')
        break;

      *aux_num = *aux;
      aux_num++;
      aux++;
    }

    if (*aux == ' ') aux++;

    while (aux_den) {
      if (*aux == ' ' || *aux == '\n' || *aux == '\0')
        break;
      
      *aux_den = *aux;
      aux_den++;
      aux++;
    }

    break;
  }

  rac->num = atoi(snum);
  rac->den = atoi(sden);
}

void limpar_racionais(struct racional vec[], int size)
{
  for (int i = 0; i < size; ++i) {
    if (!valido_r(vec[i])) {
      for (int j=i; j < size; j++) {
        vec[j] = vec[j+1];
      }
    }
  }
}

void ordenar_racionais(struct racional vec[], int size)
{
  struct racional aux;
  int cmp, i, j;

  for (i = 0; i < size; i++) {
    for (j = 0; j < size-1; j++) {
      cmp = compara_r(vec[j], vec[j+1]);
      
      if (cmp == 1) {
        aux = vec[j];
        vec[j] = vec[j+1];
        vec[j+1] = aux;
      }        
    }
  }
}

struct racional somar_racionais(struct racional vec[], int size)
{
  struct racional ret = {1 , 1};
  struct racional aux;

  for (int i = 0; i < size; ++i) {
    aux = ret;
    soma_r(aux, vec[i], &ret);
  }

  return ret;
}