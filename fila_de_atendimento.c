#include "lista.h"

int main() {

    t_lista l;

    inicia_lista(&l);

    int opcao = 0;

    int senha = 1;
    int senhaVIP = 100;

    while(opcao != 6) {

        printf("\n\n");
        printf("--------------------------------------\n");
        printf("         FILA DE ATENDIMENTO         \n");
        printf("--------------------------------------\n");
        printf("  1 - Emitir nova senha              \n");
        printf("  2 - Emitir senha VIP               \n");
        printf("  3 - Chamar proximo                 \n");
        printf("  4 - Ver fila atual                 \n");
        printf("  5 - Quantidade na fila             \n");
        printf("  6 - Sair                           \n");
        printf("--------------------------------------\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                printf("\nSenha comum gerada: %d\n", senha);
                insere_fim(senha, &l);
                senha++;
                break;

            case 2:

                printf("\nSenha VIP gerada: %d\n", senhaVIP);
                insere_inicio(senhaVIP, &l);
                senhaVIP++;
                break;

            case 3:

                if(!lista_vazia(&l)) {

                    printf("\nSenha %d foi atendida.\n",
                           remove_inicio(&l));

                } else {

                    printf("\nFila vazia! Nao ha ninguem aguardando.\n");
                }

                break;

            case 4:

                exibe_lista(&l);

                break;

            case 5:

                printf("\nExistem %d pessoas aguardando na fila.\n",tamanho_lista(&l));

                break;

            case 6:

                printf("\nSistema encerrado.\n");

                break;

            default:
                printf("\n Opcao invalida!\n");
                break;
        }
    }

    return 0;
}