#include <stdio.h>
#include <stdlib.h>
#include <glib-2.0/glib.h>
/* biblioteca open source
 * feita para oferecer diversos tipos de
 * estrutura de dados e algoritmos como:
 * . hash-tables
 * . trees
 * . graphs
 * . linked-lists
 * . etc
 */

// exemplo tirado do tutorial da IBM (https://developer.ibm.com/tutorials/l-glib/)
int main(void)
{
    GList* list = NULL;
    list = g_list_append(list, "Hello world!");

    printf("The first item is '%s'\n", g_list_first(list)->data);
    return EXIT_SUCCESS;
}

/*
 * compilar com o comando:
 * gcc glib.c `pkg-config --cflags --libs glib-2.0` -o glib
 */