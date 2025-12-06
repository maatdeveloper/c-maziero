#include <stdio.h>
#include <stdlib.h>
// ex 5 - arquivos de texto

int main(int argc, char **argv)
{
    FILE *arq1 = NULL;
    FILE *arq2 = NULL;
    int read;

    if (argc != 3) {        // verifica se os parametros estao corretos
        fprintf(stderr, "Use: %s <arquivo_origem> <arquivo_destino>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    arq2 = fopen(argv[2], "r");
    if (arq1 != NULL) {     // verifica se o arquivo destino ja existe
        fprintf(stderr, "O arquivo de destino ja existe\n");
        fclose(arq2);
        return EXIT_FAILURE;
    }

    arq1 = fopen(argv[1], "r");
    if (!arq1) {            // abre o arquivo original
        fprintf(stderr, "Erro ao tentar abrir arquivo original\n");
        return EXIT_FAILURE;
    }

    arq2 = fopen(argv[2], "w");
    if (!arq2) {            // cria o arquivo de destino
        fprintf(stderr, "Erro ao tentar gerar arquivo de copia\n");
        fclose(arq1);
        return EXIT_FAILURE;
    }

    read = fgetc(arq1);
    while (read != EOF) {
        fputc(read, arq2);
        read = fgetc(arq1);
    }

    fclose(arq1);
    fclose(arq2);

    printf("Copia concluida\n");
    return EXIT_SUCCESS;
}

// compilar com -o mycp