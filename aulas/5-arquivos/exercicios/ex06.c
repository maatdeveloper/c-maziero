#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// ex 6 - arquivos de texto
// compilar com -o mygrep

#define LINESIZE 1024
#define ARRAYSIZE 8

void show_results(const char *filename, const char *word, int occurrences, int *lines);
int process_file(FILE* arq, const char *word, int **line_oc, int *tot);

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Parametros incorretos! Forma correta de usar:\n");
        fprintf(stderr, "mygrep <arquivo> <palavra>\n");
        return EXIT_FAILURE;
    }
    
    const char *filename  = argv[1];
    const char *word      = argv[2];
    FILE *arq = fopen(filename, "r");

    if (!arq) {
        fprintf(stderr, "Falha ao tentar abrir arquivo\n");
        return EXIT_FAILURE;
    }

    int *lines_found = NULL;
    int tot = 0;
    int result;

    result = process_file(arq, word, &lines_found, &tot);
    show_results(argv[1], word, tot, lines_found);

    if (fclose(arq) == EOF)
        fprintf(stderr, "Erro ao fechar o arquivo\n");
    
    if (result == EXIT_FAILURE)
        return EXIT_FAILURE;

    free(lines_found);
    lines_found = NULL;

    return EXIT_SUCCESS;
}

int process_file(FILE* arq, const char *word, int **line_oc, int *tot)
{
    char line[LINESIZE+1];
    int current_line = 0;
    int array_size = ARRAYSIZE;
    int current_index = 0;
    int *tmp = NULL;

    *line_oc = (int*) malloc(array_size * sizeof(int));
    if (!line_oc) {
        fprintf(stderr, "Erro ao tentar alocar memoria\n");
        return EXIT_FAILURE;
    }

    while (fgets(line, LINESIZE, arq) != NULL) {
        current_line++;

        if (strstr(line, word) != NULL) {
            if (current_index >= array_size) {
                array_size *= 2;

                tmp = (int*) realloc(*line_oc, array_size * sizeof(int));

                if (!tmp) {
                    fprintf(stderr, "Erro ao tentar realocar memoria\n");
                    free(*line_oc);
                    *line_oc = NULL;
                    
                    return EXIT_FAILURE;
                }

                *line_oc = tmp;
            }

            (*line_oc)[current_index] = current_line;
            current_index++;
        }
    }

    *tot = current_index;

    if (ferror(arq)) {
        fprintf(stderr, "Erro durante a leitura do arquivo\n");
        free(*line_oc);
        *line_oc = NULL;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void show_results(const char *filename, const char *word, int occurrences, int *lines)
{
    printf("Arquivo: %s\n\n", filename);

    if (occurrences == 0) {
        printf("A palavra '%s' nao apareceu", word);
    }
    else {
        printf("A palavra '%s' apareceu %d vezes, nas linhas: ", word, occurrences);

        for (int i=0; i<occurrences; ++i) {
            printf("%d ", lines[0]);
        }
    }

    printf("\n");
}