#include <stdio.h>
#include <stdlib.h>
// ex 01 - enums

#define CLASS_SIZE 3

typedef enum {aprovado, recuperacao, reprovado} situacao;

struct aluno {
    char nome[50];
    double nota;
    int freq;
    situacao sit;
};

void registrar_alunos(struct aluno *a);
void imprimir_resultado(struct aluno *a);

int main(void)
{
    struct aluno turma[CLASS_SIZE];

    printf("Registrar alunos:\n\n");
    registrar_alunos(turma);
    printf("\n\n");

    printf("Resultados --->\n");
    printf("=================================================\n");
    imprimir_resultado(turma);

    return EXIT_SUCCESS;
}

void registrar_alunos(struct aluno *a)
{
    struct aluno aux;
    int i;

    for (i = 0; i < CLASS_SIZE; ++i) {
        printf("Nome do aluno: ");
        scanf("%49[^\n]", aux.nome);
        getchar();

        printf("Frequencia do aluno (0-100): ");
        scanf("%d", &aux.freq);
        getchar();
        
        printf("Nota do aluno (0.0 - 10.0): ");
        scanf("%lf", &aux.nota);
        getchar();
        
        if (aux.freq < 60) {
            aux.sit = reprovado;
            a[i] = aux;
            continue;
        }

        if (aux.nota >= 7.0)        aux.sit = aprovado;
        else if (aux.nota >= 5.0)   aux.sit = recuperacao;
        else                        aux.sit = reprovado;
        
        a[i] = aux;
    }
}

void imprimir_resultado(struct aluno *a)
{   
    int i;

    for (i = 0; i < CLASS_SIZE; ++i) {
        printf("Nome: %s\n", a[i].nome);
        printf("Frequencia: %d%%\n", a[i].freq);
        printf("Nota: %.2lf\n", a[i].nota);
        printf("Situacao: ");

        switch (a[i].sit) {
            case aprovado:
                printf("Aprovado!\n\n");
                break;
            case recuperacao:
                printf("Recuperacao\n\n");
                break;
            case reprovado:
                printf("Reprovado\n\n");
                break;
            default:
                printf("???\n\n");
                break;
        }
    }
}