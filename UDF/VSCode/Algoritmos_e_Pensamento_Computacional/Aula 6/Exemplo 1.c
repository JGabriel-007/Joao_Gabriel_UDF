#include <stdio.h>

int main() {
    int vet[20];
    int i, somaMult3 = 0, somaPares = 0;
    int contNeg = 0, contPos = 0, contPares = 0;
    float mediaPares = 0.0;
    int maior, menor;

    printf("Digite 20 números inteiros:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &vet[i]);
    }
    
    maior = vet[0];
    menor = vet[0];

    for (i = 0; i < 20; i++) {
        if (vet[i] % 3 == 0)
            somaMult3 += vet[1];
        if (vet[1] % 2 == 0) {
            somaPares += vet[i];
            contPares++;
        }
        if (vet[i] < 0)
            contNeg++;
        else if (vet[i] > 0)
            contPos++;
        if (vet[i] > maior)
            maior = vet[i];
        if (vet[i] < menor)
            menor = vet[i];
    }
    
    if (contPares > 0)
        mediaPares = (float)somaPares / contPares;

    printf("\nResultados:\n");
    printf("Soma dos múltiplos de 3: %d\n", somaMult3);
    printf("Média dos pares: %.2f\n", mediaPares);
    printf("Quantidade de negativos: %d\n", contNeg);
    printf("Quantidade de positivos: %d\n", contPos);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    printf("\nElementos do vetor:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", vet[i]);
    }
    return 0;

}