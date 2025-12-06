#include <stdio.h>
// ex 4 -  vetores

#define SIZE 5

void print_arrey(int arr[]);
void bubblesort(int arr[]);

int main()
{
    int arr[SIZE];

    for (int i=0; i<SIZE; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &arr[i]);
    }

    print_arrey(arr);

    bubblesort(arr);

    return 0;
}

void bubblesort(int arr[])
{
    int aux;

    for (int i=0; i<SIZE-1; i++)
    {
        for (int c=0; c<SIZE-1; c++)
        {
            if (arr[c] > arr[c+1])
            {
                aux = arr[c+1];
                arr[c+1] = arr[c];
                arr[c] = aux;
            }
        }
    }

    print_arrey(arr);
}

void print_arrey(int arr[])
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}