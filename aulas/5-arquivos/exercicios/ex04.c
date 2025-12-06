#include <stdio.h>
#include <stdlib.h>
// ex 04 - arquivos de texto

void print_mat(int lin, int col, const char m[lin][col]);

int main(void)
{
    FILE* arq;
    int col, lin;
    int read;

    arq = fopen("mapa.txt", "r");
    if (!arq) {
        perror("Erro ao tentar abrir arquivo");
        return EXIT_FAILURE;
    }

    if (fscanf(arq, "%d %d", &lin, &col) != 2) {
        perror("Erro ao ler dimensoes do mapa\n");
        fclose(arq);
        return EXIT_FAILURE;
    }
    read = fgetc(arq); // consome o '\n'
    char mat[lin][col];

    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            do {
                read = fgetc(arq);
            } while (read == '\n' || read == '\r');

            if (read == EOF) {
                perror("Erro, arquivo acabou antes do esperado\n");
                fclose(arq);
                return EXIT_FAILURE;
            }
            
            mat[i][j] = (char) read;
        }
    }

    printf("Nivel Boulder Dash\t(fonte: mapa.txt)\n\n");
    print_mat(lin, col, mat);

    fclose(arq);
    return EXIT_SUCCESS;
}

void print_mat(int lin, int col, const char m[lin][col])
{
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
}