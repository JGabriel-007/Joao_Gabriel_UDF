#include <stdio.h>

int main() {
    int i, j;
    int matriz[2][2] = {
        {10, 20},
        {30, 40}
    };
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
    
    return 0;
}