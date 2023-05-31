#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#include "arvore.h"

void escolher_estrutura(int escolha){
    switch(escolha){
        case 1:;
            node *PILHA = (node *)malloc(sizeof(node));
            PILHA->prox = NULL;
            int tam_pilha = 0;
            escolheu_pilha(PILHA, tam_pilha);
            break;
        case 2:;
            No *FILA = (No*)malloc(sizeof(No));
            FILA->prox = NULL;
            int tam_fila = 0;
            escolheu_fila(FILA, tam_fila);
            break;
        case 3:
            ArvB arv;
            arv.raiz = NULL;
            Nos *raiz = NULL;
            escolheu_arvore(raiz);
            break;
        default:
            printf("Digite uma opção válida");
    }
};

int main(){
    int escolha;
    printf("(1) Executar Pilha\n");
    printf("(2) Executar Fila\n");
    printf("(3) Executar Árvore\n->");
    scanf("%d", &escolha);
    escolher_estrutura(escolha);
    
}
