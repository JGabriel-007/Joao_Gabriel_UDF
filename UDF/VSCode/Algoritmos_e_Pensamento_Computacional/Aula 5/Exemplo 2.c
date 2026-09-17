#include <stdio.h>

int main() {
    int limite;
    int contador = 1;
    
    printf("Digite um número limite: ");
    scanf("%d", &limite);
    
    printf("\nOrdem crescente:\n");
    
    while (contador <= limite) {
        printf("%d\n", contador);
        contador++;
    }
    
    printf("\nOrdem decrescente:\n");
    contador = limite;
    
    while (contador >= 1) {
        printf("%d\n", contador);
        contador--;
    }
    
    return 0;
}