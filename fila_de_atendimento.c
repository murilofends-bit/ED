#include "lista.h"

int main() {

    /* Duas filas separadas: uma para VIP, outra para comum.
       Assim o VIP sempre passa na frente do comum, mas a ordem
       de chegada ENTRE os VIPs (e entre os comuns) e' respeitada. */
    t_lista vip;
    t_lista comum;

    inicia_lista(&vip);
    inicia_lista(&comum);

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
                insere_fim(senha, &comum);   /* comum entra no fim da fila comum */
                senha++;
                break;

            case 2:

                printf("\nSenha VIP gerada: %d\n", senhaVIP);
                insere_fim(senhaVIP, &vip);  /* VIP entra no fim da fila VIP (mantem ordem de chegada) */
                senhaVIP++;
                break;

            case 3:

                /* Atende primeiro os VIPs; so' depois os comuns. */
                if(!lista_vazia(&vip)) {

                    printf("\nSenha VIP %d foi atendida.\n",
                           remove_inicio(&vip));

                } else if(!lista_vazia(&comum)) {

                    printf("\nSenha %d foi atendida.\n",
                           remove_inicio(&comum));

                } else {

                    printf("\nFila vazia! Nao ha ninguem aguardando.\n");
                }

                break;

            case 4:

                printf("\n=== Fila VIP ===");
                exibe_lista(&vip);
                printf("\n=== Fila Comum ===");
                exibe_lista(&comum);

                break;

            case 5:

                printf("\nExistem %d pessoas aguardando na fila (VIP: %d | Comum: %d).\n",
                       tamanho_lista(&vip) + tamanho_lista(&comum),
                       tamanho_lista(&vip),
                       tamanho_lista(&comum));

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
