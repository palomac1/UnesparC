#include <stdio.h>
#include <stdlib.h>

// Implementação de uma fila com prioridade

typedef struct no {
    int valor;
    struct no *proximo;
    int valorPrioridade;
} No;

typedef struct {
    No *inicio;
    No *final;
    int tamanho;
} Fila;

void criarFila(Fila *fila){ // Função para inicializar a fila
    fila->inicio = NULL;
    fila->final = NULL;
    fila->tamanho = 0;
}

void inserirFilaPrioridade(Fila *fila, int num, int prioridade){
    No *novo = (No*)malloc(sizeof(No));
    if(novo != NULL){
        novo->valor = num;
        novo->valorPrioridade = prioridade;
        novo->proximo = NULL;

        // Se a fila está vazia, insere no início
        if (fila->inicio == NULL){
            fila->inicio = novo;
            fila->final = novo;
        } else {
            // Inserir o nó de acordo com sua prioridade (ordenação crescente)
            No *atual = fila->inicio;
            No *anterior = NULL;

            while (atual != NULL && atual->valorPrioridade <= prioridade) {
                anterior = atual;
                atual = atual->proximo;
            }

            if (anterior == NULL) { // Inserir no início
                novo->proximo = fila->inicio;
                fila->inicio = novo;
            } else if (atual == NULL) { // Inserir no final
                fila->final->proximo = novo;
                fila->final = novo;
            } else { // Inserir no meio
                anterior->proximo = novo;
                novo->proximo = atual;
            }
        }

        fila->tamanho++;
    } else {
        printf("\nErro ao alocar memória.\n");
    }
}

No* removerFila(Fila *fila){
    No *remover = NULL;
    if(fila->inicio != NULL){
        remover = fila->inicio;
        fila->inicio = remover->proximo;
        fila->tamanho--;
        if (fila->inicio == NULL) {
            fila->final = NULL;
        }
    } else {
        printf("\tFila Vazia!\n");
    }
    return remover;
}

void imprimirFila(Fila *fila){
    No *aux = fila->inicio;
    printf("\t----FILA----\n");
    while(aux != NULL){
        printf("Valor: %d Prioridade: %d\n", aux->valor, aux->valorPrioridade);
        aux = aux->proximo;
    }
    printf("\n\t----FIM DA FILA----\n");
}

int main(){
    No *r1;
    Fila filaPrioridade;
    criarFila(&filaPrioridade); // Inicializa uma fila
    int valor, entradaUsuario, prioridade, removerValor;

    do {
        printf("\nEscolha uma opção: \n");
        printf(" 0 - Sair \n 1 - Inserir \n 2 - Remover \n 3 - Imprimir \n\n");
        scanf("%d", &entradaUsuario);
        switch(entradaUsuario)
        {
        case 1:
            printf("Digite um valor a ser inserido na fila: ");
            scanf("%d", &valor);
            printf("\nDigite a prioridade do valor inserido (1 ou 2): ");
            scanf("%d", &prioridade);
            if(prioridade == 1 || prioridade == 2){
                inserirFilaPrioridade(&filaPrioridade, valor, prioridade);
            } else {
                printf("Prioridade inválida.\n");
            }
            break;
        case 2:
            r1 = removerFila(&filaPrioridade);
            if (r1 != NULL) {
                printf("Removido: %d\n", r1->valor);
                free(r1);
            }
            break;
        case 3:
            imprimirFila(&filaPrioridade);
            break;
        default:
            if(entradaUsuario != 0){
                printf("Opção inválida.\n");
            }
            break;
        }
    } while (entradaUsuario != 0);

    return 0;
}
