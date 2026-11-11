#include <stdio.h>

int main() {

    int senhasP[100], categorias[100];
    int senhasN[100];

    char nomesP[100][100];
    char nomesN[100][100];

    int qtdP = 0, qtdN = 0;
    int contadorP = 0, contadorN = 0;
    int opcao, categoria, i, j;

    do {

        printf("\n===== GERENCIADOR DE SENHAS =====\n");
        printf("1 - Gerar senha preferencial\n");
        printf("2 - Gerar senha normal\n");
        printf("3 - Chamar proxima senha\n");
        printf("4 - Consultar filas\n");
        printf("5 - Mostrar quantidade de pessoas aguardando\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        fflush(stdout);
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                if (qtdP < 100) {

                    printf("\n--- SENHA PREFERENCIAL ---\n");
                    printf("1 - Idoso (60 a 79 anos)\n");
                    printf("2 - Idoso (80 anos ou mais)\n");
                    printf("3 - Gestante\n");
                    printf("4 - PCD\n");

                    printf("Escolha a categoria: ");
                    fflush(stdout);
                    scanf("%d", &categoria);

                    if (categoria >= 1 && categoria <= 4) {

                        printf("Digite o nome do paciente: ");
                        fflush(stdout);
                        scanf(" %99[^\n]", nomesP[qtdP]);

                        contadorP++;

                        senhasP[qtdP] = contadorP;
                        categorias[qtdP] = categoria;

                        qtdP++;

                        printf("\nSenha gerada: P%03d\n",
                               contadorP);

                        printf("Paciente: %s\n",
                               nomesP[qtdP - 1]);

                    } else {
                        printf("Categoria invalida!\n");
                    }

                } else {
                    printf("Fila preferencial cheia!\n");
                }

                break;

            case 2:

                if (qtdN < 100) {

                    printf("\nDigite o nome do paciente: ");
                    fflush(stdout);
                    scanf(" %99[^\n]", nomesN[qtdN]);

                    contadorN++;

                    senhasN[qtdN] = contadorN;

                    qtdN++;

                    printf("\nSenha gerada: N%03d\n",
                           contadorN);

                    printf("Paciente: %s\n",
                           nomesN[qtdN - 1]);

                } else {
                    printf("Fila normal cheia!\n");
                }

                break;

            case 3:

                if (qtdP > 0) {

                    printf("\nSenha chamada: P%03d\n", senhasP[0]);
                    printf("Paciente: %s\n", nomesP[0]);

                    if (categorias[0] == 1)
                        printf("Idoso (60 a 79 anos)\n");

                    else if (categorias[0] == 2)
                        printf("Idoso (80 anos ou mais)\n");

                    else if (categorias[0] == 3)
                        printf("Gestante\n");

                    else
                        printf("PCD\n");

                    for (i = 0; i < qtdP - 1; i++) {

                        senhasP[i] = senhasP[i + 1];
                        categorias[i] = categorias[i + 1];

                        for (j = 0; j < 100; j++) {
                            nomesP[i][j] = nomesP[i + 1][j];
                        }
                    }

                    qtdP--;

                } else if (qtdN > 0) {

                    printf("\nSenha chamada: N%03d\n", senhasN[0]);
                    printf("Paciente: %s\n", nomesN[0]);

                    for (i = 0; i < qtdN - 1; i++) {

                        senhasN[i] = senhasN[i + 1];

                        for (j = 0; j < 100; j++) {
                            nomesN[i][j] = nomesN[i + 1][j];
                        }
                    }

                    qtdN--;

                } else {

                    printf("\nNao existem pacientes aguardando!\n");
                }

                break;

            case 4:

                printf("\n===== FILA PREFERENCIAL =====\n");

                if (qtdP == 0) {
                    printf("Nenhum paciente aguardando.\n");
                }

                for (i = 0; i < qtdP; i++) {

                    printf("P%03d - %s - ",
                           senhasP[i], nomesP[i]);

                    if (categorias[i] == 1)
                        printf("Idoso 60-79 anos\n");

                    else if (categorias[i] == 2)
                        printf("Idoso 80+ anos\n");

                    else if (categorias[i] == 3)
                        printf("Gestante\n");

                    else
                        printf("PCD\n");
                }

                printf("\n===== FILA NORMAL =====\n");

                if (qtdN == 0) {
                    printf("Nenhum paciente aguardando.\n");
                }

                for (i = 0; i < qtdN; i++) {

                    printf("N%03d - %s\n",
                           senhasN[i], nomesN[i]);
                }

                break;

            case 5: {

                int idosos60 = 0;
                int idosos80 = 0;
                int gestantes = 0;
                int pcd = 0;

                for (i = 0; i < qtdP; i++) {

                    if (categorias[i] == 1)
                        idosos60++;

                    else if (categorias[i] == 2)
                        idosos80++;

                    else if (categorias[i] == 3)
                        gestantes++;

                    else
                        pcd++;
                }

                printf("\n===== QUANTIDADE DE PESSOAS =====\n");

                printf("Idosos (60-79 anos): %d\n", idosos60);
                printf("Idosos (80+ anos): %d\n", idosos80);
                printf("Gestantes: %d\n", gestantes);
                printf("PCD: %d\n", pcd);

                printf("---------------------------------\n");

                printf("Fila preferencial: %d\n", qtdP);
                printf("Fila normal: %d\n", qtdN);

                printf("---------------------------------\n");

                printf("TOTAL AGUARDANDO: %d pessoa(s)\n",
                       qtdP + qtdN);

                break;
            }

            case 0:

                printf("\nSistema encerrado!\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}