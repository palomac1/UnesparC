#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct ArvB{
    No *raiz;
} ArvB;

//Insere o n� na esquerda
void inserirEsquerda(No *no, int valor){
    if(no->esquerda == NULL){ //Se o n� esquerdo for NULL
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    } else {
        if(valor < no->esquerda->conteudo){ //Se o valor for menor que o conteudo do n� esquerdo
            inserirEsquerda(no->esquerda, valor);
        } else {
            inserirDireita(no->esquerda, valor);
        }
    }
}

//Insere o n� na direita
void inserirDireita(No *no, int valor){
    if(no->direita == NULL){ //Se o n� direito for NULL
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    } else {
        if(valor < no->direita->conteudo){ //Se o valor for menor que o conteudo do n� direito
            inserirEsquerda(no->direita, valor);
        } else {
            inserirDireita(no->direita, valor);
        }
    }
}

//Insere o n� na arvore, considerando direita ou esquerda
void inserir(ArvB *arv, int valor){
    if(arv->raiz == NULL){ //Se a arvore estiver vazia
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo; //A raiz da arvore recebe o novo n� inv�s de ser NULL
    } else { //Se a arvore n�o estiver vazia
        if(valor < arv->raiz->conteudo){
            inserirEsquerda(arv->raiz, valor); //insere um valor no ponto esquerdo do n� da arvore
        } else {
            inserirDireita(arv->raiz, valor); //insere um valor no ponto direito do n� da arvore
        }
    }
}

//Fun��o para imprimir a arvore em ordem
void imprimirOrdem(No *raiz){
    if(raiz != NULL){
        imprimirOrdem(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimirOrdem(raiz->direita);
    }
}

//Fun��o para imprimir a arvore em pr�-ordem
void imprimirPre(No *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->conteudo);
        imprimirPre(raiz->esquerda);
        imprimirPre(raiz->direita);
    }
}

void imprimirPos(No *raiz){
    if(raiz != NULL){
        imprimirPos(raiz->esquerda);
        imprimirPos(raiz->direita);
        printf("%d ", raiz->conteudo);
    }
}

void qtdPares(No *raiz){
    if(raiz != NULL){
        qtdPares(raiz->esquerda);
        if(raiz->conteudo % 2 == 0){
            printf("%d ", raiz->conteudo);
        }
        qtdPares(raiz->direita);
    }
}

int main(){
    int op, valor;
    ArvB *arv = (ArvB*)malloc(sizeof(ArvB));
    arv->raiz = NULL;

    printf("------------------------------- ARVORE BINARIA --------------------------\n");
    do{
        printf("\n1 - Inserir\n2 - Imprimir em ordem\n3 - Imprimir em pr�-ordem\n4- Imprimir em pos-ordem\n0 - Sair\n\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d", &valor);
                printf("\n");
                inserir(arv, valor);
                break;
            case 2:
                printf("Imprimindo em ordem: ");
                imprimirOrdem(arv->raiz);
                printf("\n");
                printf("Quantidade de pares: ");
                qtdPares(arv->raiz);
                break;
            case 3:
                printf("Imprimindo em pre ordem: ");
                imprimirPre(arv->raiz);
                printf("\n");
                printf("Quantidade de pares: ");
                qtdPares(arv->raiz);
                break;
            case 4:
                printf("Imprimindo em pos ordem: ");
                imprimirPos(arv->raiz);
                printf("\n");
                printf("Quantidade de pares: ");
                qtdPares(arv->raiz);
                break;
        }
    } while(op != 0);

    //Libera a mem�ria alocada
    free(arv);
    return 0;
}
