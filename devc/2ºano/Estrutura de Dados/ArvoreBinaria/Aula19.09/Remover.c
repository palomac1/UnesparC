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

No* Remover(No *raiz, int chave){

    if(raiz == NULL){
        printf("valor não encontrado!\n"); \\Quando não exister árvore
        return NULL;
    } else {
        if(raiz-> conteudo == chave){
            if(raiz-> esquerda == NULL && raiz -> direita == NULL){
                free(raiz);
                printf("Elemento folha removido: %d !", chave);
                return NULL;
            } else{

             }
        }
     }
} else {
    if(chave < raiz -> conteudo){
        raiz -> esquerda = remover(raiz -> esquerda, chave);
    } else {
        raiz -> direita = remover(raiz -> direita, chave);
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
            inserir(&arv,valor);//passa endereço da raiz
            break;
        case 2:
            printf("\nImpresssao da arvore binaria:\n");
            imprimir(arv.raiz);
            printf("\n");
            printf("Tamanho: %d \n",tamanho(arv.raiz));
            break;
         } while (op != 0);

    free(arv);
    return 0;
    }
}