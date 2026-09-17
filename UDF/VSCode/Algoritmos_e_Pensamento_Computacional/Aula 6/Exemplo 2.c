#include <stdio.h>

int main() {
    int numeros[20];   // vetor para 10 inteiros
    int i;
    int soma = 0;      // acumulador da soma
    float media;       // variavel para a media
    int maior, menor;  // maiores e menores valores

    // Leitura dos 10 numeros
    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &numeros[i]);
    }

    // Inicializa maior e menor com o primeiro elemento
    maior = numeros[0];
    menor = numeros[0];

    // Processa os dados do vetor
    for (i = 0; i < 10; i++) {
        soma = soma + numeros[i];       // acumula a soma
        if (numeros[i] > maior) {       // verifica o maior
            maior = numeros[i];
        }
        if (numeros[i] < menor) {       // verifica o menor
            menor = numeros[i];
        }
    }

    media = (float)soma / 20;           // calcula a media

    // Exibe os resultados
    printf("\nResultados:\n");
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    // Mostra todos os elementos do vetor
    printf("\nElementos do vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    return 0;
}