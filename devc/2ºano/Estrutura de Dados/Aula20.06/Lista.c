// Lista - dados ligados de maneira linear, ter ponteiros apontando para a cabeça da lista
/*1 - criar menu da lista (impressão, ordenar, começo, fim, contagem)
2 - contagem de nós
3 - criar um método para fazer a média dos números inseridos nos nós*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int num;
    struct No *prox; // Ponteiro que aponta para o próximo nó.
} no;

// Funções para exibir o que se pede no menu 
no *inserir_ordenado(no *lista, int dado);
void imprimir_lista(no *lista); 
int contar_nos(no *lista);
float calcular_media(no *lista);
void liberar_lista(no *lista);

no *inserir_ordenado(no *lista, int dado) {
    no *novoNo = (no*)malloc(sizeof(no)); // Reserva memoria para struct
    novoNo->num = dado;
    novoNo->prox = NULL;

    // Se lista for igual a null ou numero for menor que o total de dados
    if (lista == NULL || lista->num >= dado) {
        novoNo->prox = lista; 
        lista = novoNo;
        return lista;
    }

    no *anterior = NULL; // Ponteiro para o nó anterior, que recebe NULL pois não tem nó anterior
    no *atual = lista; // Ponteiro para o nó atual, que recebe a lista pois é o primeiro nó

    while (atual != NULL && atual->num < dado) {
        anterior = atual;
        atual = atual->prox;
    }

    novoNo->prox = atual;
    anterior->prox = novoNo;
    return lista;
}

no *criar_no() { 
    no *novo = (no*)malloc(sizeof(no)); // Aloca memória dinâmica para o ponteiro nó
    return novo;
}

void imprimir_lista(no *lista) {
    no *aux = lista; // O auxiliar percorre a lista para que nenhum dado da lista seja perdido
    while (aux != NULL) {
        printf("%d ", aux->num); // Número armazenado no nó
        aux = aux->prox; // Avança para o próximo nó
    }
    printf("\n");
}

int contar_nos(no *lista) { // Conta o número de nós na lista fazendo um loop até que o nó seja NULL e incrementando o contador
    int contador = 0;
    no *aux = lista;

    while (aux != NULL) { 
        contador++;
        aux = aux->prox;
    }

    return contador;
}

float calcular_media(no *lista) {
    int soma = 0;
    int contador = 0;
    no *aux = lista;

    while (aux != NULL) { // Enquanto o nó não for NULL, a soma recebe o número do nó e o contador é incrementado para calcular a média
        soma += aux->num; 
        contador++; 
        aux = aux->prox;
    }

    if (contador == 0) {
        return 0;
    }

    return (float)soma/contador;
}

void liberar_lista(no *lista) { // Libera a memória alocada para a lista afim de não causar erros futuros
    no *aux;

    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main() {
    int opcao, valor, i;
    no *lista = NULL; // Crian um ponteiro de lista que aponta para NULL

    do {
        printf("\nMenu:\n");
        printf("1. Digite até 5 valores para o inserir_ordenado\n");
        printf("2. Imprimir lista\n");
        printf("3. Contar nós\n");
        printf("4. Calcular média\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite até 5 valores (separados por espaço): ");
                for (i = 0; i < 5; i++) {
                    if (scanf("%d", &valor) != 1) {
                        break; 
                    }
                    lista = inserir_ordenado(lista, valor);
                }
                break;
            case 2:
                imprimir_lista(lista);
                break;
            case 3:
                printf("Total de nós: %d\n", contar_nos(lista));
                break;
            case 4:
                printf("Média: %.2f\n", calcular_media(lista));
                break;
            case 5:
                printf("Sair\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    liberar_lista(lista);

    /*lista = inserir_ordenado(lista, 3);
    lista = inserir_ordenado(lista, 2);
    lista = inserir_ordenado(lista, 1);
    imprimir_lista(lista);

   lista = inserirElementoFim(lista, 10);
    lista = inserirElementoFim(lista, 20);
    lista = inserirElementoFim(lista, 30);
    imprimir_lista(lista); 

    printf("Qual numero deseja remover? \n");
    scanf("%d", &valor);
    lista = remover(lista, valor);
    imprimir_lista(lista);*/

    return 0;
}
