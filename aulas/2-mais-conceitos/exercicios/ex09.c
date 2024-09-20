#include <stdio.h>

#define SIZE 5

void printarrey(int arr[]);
void selectionsort(int arr[], int menor);
int menor_indice(int arr[]);

int main()
{
    int arr[SIZE];
    for (int i=0; i<SIZE; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &arr[i]);
    }
    printarrey(arr);

    selectionsort(arr, menor_indice(arr));

    return 0;
}

int menor_indice(int arr[])
{
    int menor = 0;
    for (int i=0; i<SIZE; i++)
    {
        if (arr[i] < arr[menor])
        {
            menor = i;
        }
    }
    printf("%d\n", menor);
    return menor;
}

void selectionsort(int arr[], int menor)
{
    int aux = arr[0];
    arr[0] = arr[menor];
    arr[menor] = aux;

    for (int i=1; i<SIZE; i++)
    {
        int imenor = i;
        for (int j=i+1; j<SIZE; j++)
        {
            if (arr[j] < arr[imenor])
            {
                imenor = j;
            }
        }

        aux = arr[i];
        arr[i] = arr[imenor];
        arr[imenor] = aux;
    }

    printarrey(arr);
}

void printarrey(int arr[])
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}