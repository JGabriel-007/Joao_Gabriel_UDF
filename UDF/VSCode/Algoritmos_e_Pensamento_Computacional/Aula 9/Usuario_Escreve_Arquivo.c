#include <stdio.h>

int main() {
    FILE *arquivo;
    char equipamento[100];
    char linha[100];
    
    printf("Digite o nome do equipamento: ");
    fgets(equipamento, sizeof(equipamento), stdin);
    
    arquivo = fopen("equipamentos.txt", "a");
    fprintf(arquivo, "%s", equipamento);
    fclose(arquivo);
    
    arquivo = fopen("equipamentos.txt", "r");
    while (fgets(linha, sizeof(linha), arquivo) !=NULL) {
        printf("s%", linha);
    }
    fclose(arquivo);
    return 0;
}