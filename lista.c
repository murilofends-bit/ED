#include "lista.h"

void inicia_lista(t_lista *pl) {
    pl->primeiro = NULL;
}

int lista_vazia(t_lista *pl) {
    return pl->primeiro == NULL;
}

void insere_inicio(int e, t_lista *pl) {
    t_no *novo = constroi_no(e);
    if(!lista_vazia(pl)) {
        novo->proximo = pl->primeiro;
    }
    pl->primeiro = novo;
}

void insere_fim(int e, t_lista *pl) {
    t_no *novo = constroi_no(e);
    if(lista_vazia(pl)) {
        pl->primeiro = novo;
    } else {
        t_no *runner = pl->primeiro;
        while(runner->proximo != NULL) {
            runner = runner->proximo;
        }
        runner->proximo = novo;
    }
}

void exibe_lista(t_lista *pl) {
    if(lista_vazia(pl)) {
        printf("\nFila vazia! Nao ha ninguem aguardando.\n");
    } else {
        t_no *runner = pl->primeiro;
        printf("\nFila atual:\n");
        while(runner != NULL) {
            printf("[%d] -> ", runner->info);
            runner = runner->proximo;
        }
        printf("NULL\n");
    }
}

int remove_inicio(t_lista *pl) {
    int copia_valor = pl->primeiro->info;
    t_no *copia_endereco = pl->primeiro;
    pl->primeiro = pl->primeiro->proximo;
    free(copia_endereco);
    return copia_valor;
}

int tamanho_lista(t_lista *pl) {
    int contador = 0;
    t_no *runner = pl->primeiro;
    while(runner != NULL) {
        contador++;
        runner = runner->proximo;
    }
    return contador;
}