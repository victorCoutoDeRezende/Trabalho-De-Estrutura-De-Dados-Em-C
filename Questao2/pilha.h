struct Node{
    int item;
    struct Node *prox;
};

typedef struct Node node;

int vazia(node *PILHA){
    if(PILHA->prox == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void PUSH(node *PILHA, int tam){
    node *novo = (node *)malloc(sizeof(node));
    novo->prox = NULL;
    
    printf("Novo Item: ");
    scanf("%d", &novo->item);
    
    if(vazia(PILHA)){
        PILHA->prox = novo;
    }
    else{
        node *temp = PILHA->prox;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novo;
    }
    tam++;
}

void IMPRIME(node *PILHA, int tam){
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
        return;
    }
    else{
        node *temp;
        temp = PILHA->prox;
        printf("\nPILHA: ");
        while(temp != NULL){
            printf("%3d", temp->item);
            temp = temp->prox;
            tam++;
        }
    }
    printf("\nQtde de itens na PILHA: %d", tam);
    printf("\n");
}

void POP(node *PILHA, int tam){
    if(PILHA->prox == NULL){
        printf("A Pilha já está vazia!\n\n");
        return;
    }
    else{
        node *ultimo = PILHA->prox;
        node *penultimo = PILHA;
        
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
        tam--;
    }
    
}

void LIMPAR(node *PILHA, int tam){
    node *atual = PILHA->prox;
    node *proximo;
    while(atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    PILHA->prox = NULL;
    tam = 0;
}

void TOPO(node *PILHA){
    if(PILHA->prox == NULL){
        printf("A Pilha está vazia!\n");
    } 
    else{
        node *atual = PILHA->prox;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        printf("Topo da Pilha: %d\n", atual->item);
    }
}

void escolheu_pilha(node *PILHA, int tam){
    printf("----- Escolha a operação de Pilha -----\n");
    printf("[1]Empilha\n[2]Desempilha\n[3]Imprimir Pilha\n[4]Limpar Pilha\n[5]Imprimir Topo da Pilha\n[6]Sair\n->");
    int escolha_pilha;
    scanf("%d", &escolha_pilha);
    switch(escolha_pilha){
        case 1:
            PUSH(PILHA, tam);
            escolheu_pilha(PILHA, tam);
            break;
        case 2:
            POP(PILHA, tam);
            escolheu_pilha(PILHA, tam);
            break;
        case 3:
            IMPRIME(PILHA, tam);
            escolheu_pilha(PILHA, tam);
            break;
        case 4:
            LIMPAR(PILHA, tam);
            escolheu_pilha(PILHA, tam);
            break;
        case 5:
            TOPO(PILHA);
            escolheu_pilha(PILHA, tam);
            break;
        case 6:
            break;
        default:
            printf("Digite uma opção válida");
    }
}