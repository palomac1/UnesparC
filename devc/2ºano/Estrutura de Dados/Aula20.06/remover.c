#include<stdio.h>
 #include<stdlib.h>


    typedef struct no {
    int conteudo;
    struct no *esquerda, *direita;
    }No;


typedef struct{
No *  raiz;
}ArvB;


void inserirEsquerda(No *no, int valor) {

    if(no->esquerda == NULL) {
        No novo = (No)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    } else {

        if(valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        else
        if(valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}

 void inserirDireita(No *no, int valor) {
    if(no->direita == NULL) {
        No novo = (No)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    } else {
        if(valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if(valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
}

void imprimir(No *raiz)
{
    if(raiz!=NULL)//
    {

        imprimir(raiz->esquerda);
        printf("%d  ",raiz->conteudo);//(*raiz).esquerda
        imprimir(raiz->direita);

    }
}

No* remover(No *raiz, int chave) {
    if (raiz == NULL) {
        printf("Valor não encontrado!\n"); // Quando não existir árvore
        return NULL;
    } else {
        // Elimina nó folha (nó sem filhos)
        if (raiz->conteudo == chave) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d!\n", chave);
                return NULL;
            // Elimina nó com um filho a direita
            } else if (raiz->esquerda == NULL) {
                No *temp = raiz->direita;
                free(raiz);
                printf("Elemento com um filho removido: %d!\n", chave);
                return temp;
            // Elimina nó com um filho a esquerda
            } else if (raiz->direita == NULL) {
                No *temp = raiz->esquerda;
                free(raiz);
                printf("Elemento com um filho removido: %d!\n", chave);
                return temp;
            // Elimina nó com dois filhos
            } else {
                No *temp = raiz->direita;
                while (temp->esquerda != NULL) {
                    temp = temp->esquerda;
                }
                raiz->conteudo = temp->conteudo;
                raiz->direita = remover(raiz->direita, temp->conteudo);
            }
        // Busca o valor a ser removido
        } else if (chave < raiz->conteudo) {
            raiz->esquerda = remover(raiz->esquerda, chave);
        } else {
            raiz->direita = remover(raiz->direita, chave);
        }
        return raiz;
    }
}

int main() {

    int op, valor;
    ArvB arv;
    arv.raiz=NULL;

  do{
    printf( "\n0 - sair\n1 - inserir\n2 - imprimir\n3 - Buscar\n4 - Remover\n" );
    scanf("%d",&op);
    switch(op){
        case 0: printf("\nSaindo...\n");
            break;
        case 1:
            printf("Digite um valor:");
            scanf("%d",&valor);
            inserir(&arv,valor);
            break;
        case 2:
            printf("\nImpresssao da arvore binaria:\n");
            imprimir(arv.raiz);
            printf("\n");
            printf("Tamanho: %d \n",tamanho(arv.raiz));
            break;
        case 3:
            printf("Digite um valor para buscar:");
            scanf("%d",&valor);
            if(buscar(arv.raiz,valor))
                printf("Valor encontrado!\n");
            else
                printf("Valor não encontrado!\n");
            break;
        case 4:
            printf("Digite um valor para remover:");
            scanf("%d",&valor);
            arv.raiz=remover(arv.raiz,valor);
            break;
         } while (op != 0);

    free(arv);
    return 0;
    }
}
