#include <stdio.h>
#include <errno.h>

int main(int argc, char argv[]) {
    FILE* file ;

    file = fopen ("results.dat", "r+") ;
    
    if (! file) {
        switch (errno) {
            case EPERM   : printf ("Operação não permitida\n") ; break ;
            case ENOENT  : printf ("Arquivo não encontrado\n") ; break ;
            case EACCES  : printf ("Permissão negada\n") ;       break ;
            default      : printf ("Outro erro\n") ;     
        }
        exit (1) ;
    }
}