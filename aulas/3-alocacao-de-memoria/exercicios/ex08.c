#include <stdio.h>
#include <stdlib.h>
// ex 4 - alocar memoria

typedef struct LinkedList {
    int val;
    struct LinkedList *prox;
} LinkedList;

LinkedList *new_linkedlist();
void print_linkedlist(LinkedList *linklist);
int add_linkedlist(int val, LinkedList *ll);

int main(void) {
    LinkedList *linked_list = new_linkedlist();

    for (int i=0; i<1000; i++) {
        add_linkedlist(i+1, linked_list);
    }

    print_linkedlist(linked_list);

    return 0;
}

LinkedList *new_linkedlist() {
    LinkedList *nll; // new linked list

    nll = (LinkedList*) malloc(sizeof (LinkedList));
    
    if (!nll) {
        fprintf(stderr, "Falha ao tentar criar lista ligada\n");
        return NULL;
    }

    nll->prox = NULL;

    return nll;
}

int add_linkedlist(int val, LinkedList *ll) {
    LinkedList *nova;

    nova = (LinkedList*) malloc(sizeof(LinkedList));
    if (!nova) {
        fprintf(stderr, "Falha ao adicionar novo valor\n");
        return 0;
    }

    nova->val = val;
    nova->prox = ll->prox;

    ll->prox = nova;
    return 1;
}

void print_linkedlist(LinkedList *linkedlist) {
    LinkedList *ll;

    for (ll=linkedlist->prox; ll != NULL; ll = ll->prox) {
        fprintf(stdout, "%d ", ll->val);
    }
    fprintf(stdout, "\n");
}