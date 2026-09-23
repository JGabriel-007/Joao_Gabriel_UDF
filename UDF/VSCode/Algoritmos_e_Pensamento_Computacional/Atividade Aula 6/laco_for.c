#include <stdio.h>

int main() {
    int linhas, colunas;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &colunas);

    printf("\n--- Resultado (%dx%d) ---\n", linhas, colunas);

    for (int i = 1; i <= linhas; i++) {
        
        for (int j = 1; j <= colunas; j++) {
            printf("[%d,%d] ", i, j);
        }

    }

    return 0;
}