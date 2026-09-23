#include <stdio.h>

int main() {
    int mat[3][3];
    int i, j;
    
    // Leitura da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite mat[%d][%d]:", i, j);
            scanf("%d", &mat[i][j]);
        }
        
    }
    
    return 0;
}