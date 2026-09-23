#include <stdio.h>

int main() {
    int mat[3][3] = {
        {5, 8, 12},
        {15, 20, 25},
        {30, 35, 40}
    };
    int i, j;
    
    // Leitura da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
        
    }
    
    // Exibe a matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        
        printf("\n");
    }
    return 0;
}