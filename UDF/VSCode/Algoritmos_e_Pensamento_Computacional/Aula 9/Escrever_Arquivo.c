#include <stdio.h>

int main() {
    FILE *arquivo;
    
    arquivo = fopen("mensagem.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    fprintf(arquivo, "Olá Mundo!.\n");
    fclose(arquivo);
    
    printf("Arquivo criado com sucesso!\n");
    
    return 0;
}