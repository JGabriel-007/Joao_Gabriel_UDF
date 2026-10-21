#include <stdio.h>

int main() {
    int v[5] = {9, 4, 7, 2, 1};
    int i, j, temp;
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    printf("Vetor ordenado:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}