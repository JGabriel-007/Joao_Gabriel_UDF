#include <stdio.h>

int main() {
    int numeros[5];
    
    // Leitura dos elementos
    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i +1);
        scanf("%d", &numeros[i]);
    }
    
    // Exibindo os elementos
    printf("\nValores digitados:\n");
    for (int i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }
    return 0;
}