#include <stdio.h>

void bubbleSort(int vetor[], int tamanho){
    int temp = 0;
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if (vetor[i] < vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    printf("-----Vetor Ordenado por Bubble Sort-----\n");
    for(int i = 0; i < tamanho; i++){
        printf(" - %d",vetor[i]);
    }
}
void insertionSort(int vetor[], int tamanho){
    int guarda, indice;
    
    for(int i = 1; i < tamanho; i++){
        guarda = vetor[i];
        indice = i;
        while(indice > 0 && vetor[indice - 1] > guarda){
            vetor[indice] = vetor[indice - 1];
            indice--;
        }
        vetor[indice] = guarda;
    }
    printf("-----Vetor Ordenado por Insertion Sort-----\n");
    for(int i = 0; i < tamanho; i++){
        printf(" - %d",vetor[i]);
    }
}
int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++){
        printf("Digite o %d número: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("----- Digite qual método de ordenação você quer -----\n");
    printf("-----     [1]Bubble Sort - [2]Insertion Sort    -----\n->");
    int escolha;
    scanf("%d", &escolha);
    if(escolha == 1){
        bubbleSort(vetor, tamanho);
    }
    else if(escolha == 2){
        insertionSort(vetor, tamanho);
    }
    else{
        printf("Digite uma opção válida!");
    }
}
