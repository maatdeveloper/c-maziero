#include "minha_lib/hello.h"

int main(void)
{
    hello_pt();
    hello_en();
    hello_fr();

    return 0;
}

/* para compilar (ligaçao estatica) voce deve:
 * 
 * 1 - compilar todos os arquivos da biblioteca (hello_pt, hello_en, hello_fr)
 * ex: gcc -Wall -c hello_pt.c
 * 
 * 2 - utlizar 'ar' (archiver) para juntar as bibliotecas
 * ex: ar rvs libhello.a hello_pt.o hello_en.o hello_fr.o
 * 
 * 3 - compilar a main e liga-la a biblioteca
 * ex: gcc -Wall main.c -o hello libhello.a
 */

/* para compilar (ligacao dinamica) voce deve:
 *
 * 1 - compilar todos os arquivos da biblioteca (hello_pt, hello_en, hello_fr)
 * ex: gcc -Wall -fPIC -c hello_pt.c
 * 
 * 2 - crie uma biblioteca dinamica:
 * $ gcc -Wall -g -shared -Wl,-soname,libhello.so.0 -o libhello.so.0.0 hello_pt.o hello_en.o hello_fr.o
 * 
 * 3 - voce deve mover o arquivo gerado para os diretorios adequados e gerar atalhos
 * # mv libhello.so.0.0 /usr/local/lib
 * # cd /usr/local/lib
 * # ln -s libhello.so.0.0 libhello.so.0
 * # ln -s libhello.so.0 libhello.so
 * 
 * 4 - compilar a main com a biblioteca
 * ex: gcc -Wall main.c -o main -L. -lhello
 */