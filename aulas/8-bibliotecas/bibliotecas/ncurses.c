#include <ncurses.h>
/* biblioteca para interface de texto com o usuario
 * oferece recursos como:
 * . posicionamento de cursor
 * . leitura de teclas
 * . manipulacao de cores
 * . criacao de eventos com o mouse
 * . criacao de janelas
 * . etc
 */

// exemplo tirado do NCurses (https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/helloworld.html)
int main(void)
{
    initscr();
    printw("Hello word!");
    refresh();
    getch();
    endwin();

    return 0;
}

/*
 * compilar com:
 * gcc ncurses.c -o ncurses -lncurses
 */