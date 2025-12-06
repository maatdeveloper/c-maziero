#include <stdio.h>
#include <string.h>
// ex 1 - structs

struct Aluno
{
    char nome[100];
    char curso[100];
    int idade;
};

int main() {
    struct Aluno alunos[5];
    
    struct Aluno aluno;
    char nome[50];
    char curso[100];
    int idade;

    for (int i=0; i<5; i++) {
        printf("Nome: ");
        scanf("%s", &nome);
        
        printf("Idade: ");
        scanf("%d", &idade);
        
        printf("Curso: ");
        scanf("%s", &curso);
        printf("\n");

        strcpy(aluno.nome, nome);
        strcpy(aluno.curso, curso);
        aluno.idade = idade;

        alunos[i] = aluno;
    }

    for (int i=0; i<5; i++) {
        if (alunos[i].idade > 22) {
            printf("%s\n", alunos[i].nome);
        }   
    }

    struct Aluno aux;
    for (int i=0; i<5; i++) {
        for (int c=0; c<4; c++) {
            if (alunos[c].idade < alunos[c+1].idade) {
                aux = alunos[c+1];
                alunos[c+1] = alunos[c];
                alunos[c] = aux;
            }
        }
    }

    for (int i=0; i<5; i++) {
        printf("%s %d\n", alunos[i].nome, alunos[i].idade);
    }
    return 0;
}