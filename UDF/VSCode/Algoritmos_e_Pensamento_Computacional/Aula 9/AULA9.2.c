#include <stdio.h>

int main() {
    FILE *arquivo;
    
    arquivo = fopen("mensagem.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    fprintf(arquivo, "Olá, mundo!\n");
    printf("Mensagem gravada com sucesso!\n");
    
    return 0;
}