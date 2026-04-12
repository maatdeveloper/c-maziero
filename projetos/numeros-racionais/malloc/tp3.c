/*
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
 */

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "racional.h"

#define LINESIZE 8
/* coloque aqui as funções auxiliares que precisar neste arquivo */
void le_racional(char* buff, struct racional **vec);
void limpar_racionais(struct racional ***vec, int *n);
void ordena_racionais(struct racional **vec, int n);
void liberar_racionais(struct racional **vec, int n);
struct racional soma_racionais(struct racional **vec, int n);

/* programa principal */
int main(int argc, char **argv)
{
  /* a completar! */
  FILE *fp = NULL;
  struct racional **vec = NULL;
  struct racional soma;
  char buff[LINESIZE];
  int n;

  if (argc != 2) return (1);

  fp = fopen(argv[1], "r");
  if (!fp) {
    fprintf(stderr, "Erro ao tentar abrir arquivo %s\n", argv[1]);
    return (1);
  }

  // pega a primeira linha de 'fp' e converte para um inteiro
  n = atoi(fgets(buff, LINESIZE, fp));
  if (n <= 0) {
    fprintf(stderr, "O valor de entrada deve ser maior que 0!\n");
    return (1);
  }

  vec = malloc (n * sizeof (struct racional*));

  if (!vec) {
    fprintf(stderr, "Erro ao tentar alocar memoria\n");
    return (1);
  }

  memset(vec, 0, sizeof (*vec) * n);

  for (int i=0; i < n; i++) {
    if(!fgets(buff, LINESIZE, fp)) break;
    le_racional(buff, &vec[i]);
  }

  fprintf(stdout, "VETOR= ");
  for (int i=0; i < n; i++) {
    imprime_r(vec[i]);
    putc(' ', stdout);
  }

  putc('\n', stdout);

  limpar_racionais(vec, &n);
  fprintf(stdout, "VETOR= ");
  for (int i=0; i < n; i++) {
    imprime_r(vec[i]);
    putc(' ', stdout);
  }

  putc('\n', stdout);

  ordena_racionais(vec, n);
  fprintf(stdout, "VETOR= ");
  for (int i=0; i < n; i++) {
    imprime_r(vec[i]);
    putc(' ', stdout);
  }

  putc('\n', stdout);

  soma = soma_racionais(vec, n);
  fprintf(stdout, "SOMA= ");
  imprime_r(&soma);

  putc('\n', stdout);

  liberar_racionais(vec, n);
  fprintf(stdout, "VETOR= ");

  putc('\n', stdout);
  
  fclose(fp);
  
  return (0);
}

void le_racional(char* buff, struct racional **vec)
{
  long num, den;

  if (sscanf(buff, "%ld/%ld", &num, &den) == 2) {
    *vec = cria_r(num, den);
  } else {
    *vec = cria_r(atol(buff), 1);
  }
}

void liberar_racionais(struct racional **vec, int n)
{
  for (int i=0; i < n; i++) {
    destroi_r(vec[i]);
  }

  destroi_r(vec);
}

void limpar_racionais(struct racional ***vec, int *n)
{
    struct racional **old = *vec;
    struct racional **new_vec;
    int count = 0;

    // contar válidos
    for (int i = 0; i < *n; i++) {
        if (valido_r(old[i]))
            count++;
    }

    new_vec = malloc(sizeof(struct racional*) * count);
    if (!new_vec) {
        fprintf(stderr, "Erro ao alocar novo vetor\n");
        return;
    }

    // copiar válidos
    int j = 0;
    for (int i = 0; i < *n; i++) {
        if (valido_r(old[i])) {
            new_vec[j++] = old[i];
        } else {
            destroi_r(old[i]); // libera inválidos
        }
    }

    free(old);

    *vec = new_vec;
    *n = count;
}

void ordena_racionais(struct racional **vec, int n)
{
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (compara_r(vec[j], vec[j+1]) == 1) {
        struct racional *aux = vec[j];
        vec[j] = vec[j+1];
        vec[j+1] = aux;
      }
    }
  }
}

struct racional soma_racionais(struct racional **vec, int n)
{
  struct racional ret = {1, 1};
  struct racional aux;

  for (int i=0; i < n; i++) {
    aux = ret;
    soma_r(&aux, vec[i], &ret);
  }

  return ret;
}