#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct {
    No *raiz;
} ArvB;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->conteudo = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void inserir(No **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
    } else {
        if (valor < (*raiz)->conteudo)
            inserir(&(*raiz)->esquerda, valor);
        else if (valor > (*raiz)->conteudo)
            inserir(&(*raiz)->direita, valor);
    }
}

void imprimir(No *raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d  ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

No* remover(No *raiz, int chave) {
    if (raiz == NULL) {
        printf("Valor não encontrado!\n");
        return NULL;
    } else {
        // Encontra o nó a ser removido
        if (raiz->conteudo == chave) {
            // Nó folha
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                printf("Elemento folha removido: %d\n", chave);
                free(raiz);
                return NULL;
            }
            // Elimna nó com um filho à direita
            else if (raiz->esquerda == NULL) {
                No *temp = raiz->direita;
                printf("Elemento com um filho a direita removido: %d\n", chave);
                free(raiz);
                return temp;
            }
            // Elimina nó com um filho à esquerda
            else if (raiz->direita == NULL) {
                No *temp = raiz->esquerda;
                printf("Elemento com um filho a esquerda removido: %d\n", chave);
                free(raiz);
                return temp;
            }
            // Nó com dois filhos
            else {
                No *temp = raiz->direita;
                while (temp->esquerda != NULL) {
                    temp = temp->esquerda;
                }
                printf("Elemento com dois filhos removido: %d, substituido por %d\n", chave, temp->conteudo);
                raiz->conteudo = temp->conteudo;
                raiz->direita = remover(raiz->direita, temp->conteudo);  // Remove o nó substituto
            }
        // Busca o nó a ser removido na subárvore esquerda
        } else if (chave < raiz->conteudo) {
            raiz->esquerda = remover(raiz->esquerda, chave);
        // Busca o nó a ser removido na subárvore direita
        } else {
            raiz->direita = remover(raiz->direita, chave);
        }
        return raiz;
    }
}

int buscar(No *raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    } else if (raiz->conteudo == valor) {
        return 1;
    } else if (valor < raiz->conteudo) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

int tamanho(No *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

int main() {
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    printf("---------------------------------\n");
    printf("Arvore binaria de busca\n");
    printf("---------------------------------\n");

    do {
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n4 - Remover\n");
        scanf("%d", &op);
        switch (op) {
            case 0: 
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir(&arv.raiz, valor);
                break;
            case 2:
                printf("\nImpressao da arvore binaria:\n"); 
                imprimir(arv.raiz);
                printf("\nTamanho: %d \n", tamanho(arv.raiz));
                break;
            case 3:
                printf("Digite um valor para buscar: ");
                scanf("%d", &valor);
                if (buscar(arv.raiz, valor))
                    printf("Valor encontrado!\n");
                else
                    printf("Valor nao encontrado!\n");
                break;
            case 4:
                printf("Digite um valor para remover: ");
                scanf("%d", &valor);
                arv.raiz = remover(arv.raiz, valor);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (op != 0);

    return 0;
}
