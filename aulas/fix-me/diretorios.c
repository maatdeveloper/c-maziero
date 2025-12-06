#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main(void)
{
    DIR* dirstream;
    struct dirent* direntry;
    
    dirstream = opendir("./");

    if (! dirstream) {
        perror("Não foi possivel abrir o diretorio");
        exit(1);
    }

    for (;;) {
        direntry = readdir(dirstream);

        if (! direntry) {
            break;
        }

        printf ("%s\t", direntry->d_name);
        switch (direntry->d_type)
        {
            case DT_UNKWONW:
                printf ("(desconhecido)\n");
                break;
            case DT_REG:
                printf (" (arquivo)\n");
                break;
            case DT_DIR:
                printf (" (diretorio)\n");
                break;
            default:
                printf (" (outros)\n");
        }
    }

    (void) closedir (dirstream);

    return 0;
}
