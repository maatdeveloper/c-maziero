#include <stdio.h>
// ex 1 -  vetores

int main() {
    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    int tam = sizeof(nums) / sizeof(nums[0]);

    for (int i=0; i<tam; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    for (int i=tam-1; i>=0; i--) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}