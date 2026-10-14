#include <stdio.h>
#include "operacoes.h"

int main(void) {
    int num1;
    int num2;
    int escolha;
    
    printf("Escolha a operacao:\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("Digite o numero da opcao: ");
    scanf("%d", &escolha);
    
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    
    if (escolha == 1) {
        int resultado = somar(num1, num2);
        printf("Resultado da Soma: %d\n", resultado);
    }
    
    else if (escolha == 2) {
        int resultado = subtrair(num1, num2);
        printf("Resultado da Subtração: %d\n", resultado);
    }
    
    else if (escolha == 3) {
        int resultado = multi(num1, num2);
        printf("Resultado da Multiplicação: %d\n", resultado);
    }
    
    else {
        int resultado = dividir(num1, num2);
        printf("Resultado da Divisão: %d\n", resultado);
    }
    return 0;
}