#include <stdio.h>

int main() {
    int n = 0;
    for (int i=1; i<=10000; i++) {
        printf("%5d\n", i);
        printf("%05d\n", i);
    }
    
    return 0;
}