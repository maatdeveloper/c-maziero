#include <stdio.h>

#define SIZE 10

int main()
{
    int vec[SIZE];
    int *p = vec;

    for (int i=0; i<SIZE; i++)
    {
        scanf("%d", p);
        p++;
    }

    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", *p);
        p--;
    }
    
    printf("\n");
    return 0;
}