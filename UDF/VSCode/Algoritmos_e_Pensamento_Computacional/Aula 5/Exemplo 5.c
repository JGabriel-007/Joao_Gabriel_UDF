#include <stdio.h>
#include <string.h>

int main() {
    char senha[50];
    const char senha_correta[] = "1234";
    int tentativas = 0;
    int max_tentativas = 3;

    while (tentativas < max_tentativas) {
        printf("Digite a senha: ");
        scanf("%s", senha);

        if (strcmp(senha, senha_correta) == 0) {
            printf("\nAcesso liberado!\n");
            return 0;
        } else {
            tentativas++;
            if (tentativas < max_tentativas) {
                printf("Senha incorreta! Voce tem mais %d tentativa(s).\n\n", max_tentativas - tentativas);
            }
        }
    }

    printf("\nNumero maximo de tentativas atingido. Acesso bloqueado!\n");
    return 0;
}