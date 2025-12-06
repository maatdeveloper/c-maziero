#include <stdio.h>
// ex 2 - ponteiros

#define SIZE 5

void preencher(int* ptr);
void bubblesort(int* ptr);
void printarrey(int* ptr);

int main()
{
    int vec[SIZE];
    
    printf("preencher\n");
    preencher(vec);
    printf("bubblesort\n");
    bubblesort(vec);
    printf("printarrey\n");
    printarrey(vec);
    
    return 0;
}

void preencher(int* ptr) {
    for (int i=0; i<SIZE; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }
}

void printarrey(int* ptr) {
    for (int i=0; i<SIZE; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

void bubblesort(int* ptr) {
    int aux;

    for (int i=0; i<SIZE-1; i++) {
        printarrey(ptr);
        for (int j=i; j<SIZE; j++) {
            // printf("%p - ", ptr);
            // printf("%d\n", *ptr);
        
            if (*ptr > *(ptr + 1)) {
                aux = *(ptr + 1);
                *(ptr + 1) = *ptr;
                *ptr = aux;
            }
            
                ptr++; //esse aq é o periculoso
        }
        ptr-= SIZE-i;
        printarrey(ptr);
    }
}