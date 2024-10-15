#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

// estrututa nó
typedef struct no {
int conteudo;
struct no *esquerda, *direita;
}No;

// estrutura árvore com um ponteiro para um nó
typedef struct{
No * raiz;
}ArvB;

//void inserirDireita(No *no, int valor);
// procedimento para inserir um elemento na subárvore esquerda
void inserirEsquerda(No *no, int valor) { // na primeira vez, recebe a raiz
    if(no-&gt;esquerda == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo-&gt;conteudo = valor;
        novo-&gt;esquerda = NULL;
        novo-&gt;direita = NULL;
        no-&gt;esquerda = novo; //aponta para o novo nó
    } else {// poder ser que tenha alguem a esquerda
        if(valor &lt; no-&gt;esquerda-&gt;conteudo)
         inserirEsquerda(no-&gt;esquerda, valor);
        else
         if(valor &gt; no-&gt;esquerda-&gt;conteudo)
         inserirDireita(no-&gt;esquerda, valor);
    }
}

void inserirDireita(No *no, int valor) {// primeira parte
    if(no-&gt;direita == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo-&gt;conteudo = valor;
        novo-&gt;esquerda = NULL;
        novo-&gt;direita = NULL;
        no-&gt;direita = novo;
    } else {
        if(valor &gt; no-&gt;direita-&gt;conteudo)
         inserirDireita(no-&gt;direita, valor);
        if(valor &lt; no-&gt;direita-&gt;conteudo)
         inserirEsquerda(no-&gt;direita, valor);
    }
}

void inserir(ArvB *arv, int valor){// descobre se esta vazia ou se vai para
    esquerda ou direita.
    if(arv-&gt;raiz==NULL)// arvore esta vazia?
    {
        No *novo =(No*)malloc(sizeof(No));// retorna o endereço desse nó.
        novo-&gt;conteudo=valor;
        novo-&gt; esquerda=NULL;
        novo-&gt; direita=NULL;
        arv-&gt;raiz = novo; //a raiz aponta para o primeiro nó.
        //se já existe um nó criado
    } else{// separa ir para esquerda ou direita
        if(valor &lt; arv-&gt; raiz-&gt;conteudo)
        inserirEsquerda(arv-&gt;raiz,valor);//passa para o metodo inserir
        esq
        else
        inserirDireita(arv-&gt;raiz,valor);
    }
}

void imprimir(No *raiz) {
    if(raiz!=NULL) {
    //imprimir primeiro a esquerda depois a direita
    //(*raiz).esquerda
    // imprimir na pré-ordem
    // printf(&quot;%d &quot;,raiz-&gt;conteudo);
    //imprimir(raiz-&gt;esquerda);
    // imprimir(raiz-&gt;direita);
    // em ordem
    // imprimir(raiz-&gt;esquerda);
    // printf(&quot;%d &quot;,raiz-&gt;conteudo);//(*raiz).esquerda
    // imprimir(raiz-&gt;direita);
    // pós ordem
    imprimir(raiz-&gt;esquerda);
    imprimir(raiz-&gt;direita);
    printf(&quot;%d &quot;,raiz-&gt;conteudo);
    }
}

int tamanho(No *raiz){
    if(raiz == NULL)
     return 0;
    else
        return 1 + tamanho(raiz-&gt;esquerda) + tamanho(raiz-&gt;direita);
}

int buscar(No *raiz, int chave) {
    if(raiz==NULL){
        return -1;
    }else {
        if(raiz-&gt;conteudo == chave)
        return raiz-&gt;conteudo;
    else{
        if(chave &lt; raiz-&gt;conteudo)
        return buscar(raiz-&gt;esquerda,chave);
        else
        return buscar(raiz-&gt;direita,chave);
    }
    }
}

No* remover(No *raiz, int chave) {
    if(raiz == NULL){
        printf(&quot;Valor nao encontrado!\n&quot;);
        return NULL;
    } else { // procura o nó a remover
    if(raiz-&gt;conteudo == chave) {
        // remove nós folhas (nós sem filhos)
        if(raiz-&gt;esquerda == NULL &amp;&amp; raiz-&gt;direita == NULL) {
        free(raiz);
        printf(&quot;Elemento folha removido: %d !\n&quot;, chave);
        return NULL;
    } else{
    // remover nós que possuem 2 filhos
    // if(raiz-&gt;esquerda != NULL &amp;&amp; raiz-&gt;direita != NULL){
    // }
    // else{
    // remover nós que possuem apenas 1 filho
    // No *aux;
    // if(raiz-&gt;esquerda != NULL)
    // aux = raiz-&gt;esquerda;
    // else
    // aux = raiz-&gt;direita;
    // free(raiz);
    // printf(&quot;Elemento com 1 filho removido: %d !\n&quot;, chave);

    // return aux;
    // }
    }} else {
    if(chave &lt; raiz-&gt;conteudo)
     raiz-&gt;esquerda = remover(raiz-&gt;esquerda, chave);
    else
        raiz-&gt;direita = remover(raiz-&gt;direita, chave);
    return raiz;
    }
  }
}

int main() {
    int op, valor;
    ArvB arv;
    arv.raiz=NULL;

    do{
        printf( &quot;\n0 - sair\n1 - inserir\n2 - imprimir\n3 - Buscar\n4 -
        Remover\n&quot; );
        scanf(&quot;%d&quot;,&amp;op);
    switch(op){
    case 0:
        printf(&quot;\nSaindo...\n&quot;);
    break;
    case 1:
        printf(&quot;Digite um valor:&quot;);
        scanf(&quot;%d&quot;,&amp;valor);
        inserir(&amp;arv,valor);//passa endereço da raiz
    break;
    case 2:
        printf(&quot;\nImpresssao da arvore binaria:\n&quot;);
        imprimir(arv.raiz);
        printf(&quot;\n&quot;);
        printf(&quot;Tamanho: %d \n&quot;,tamanho(arv.raiz));
    break;
    case 3:
        printf(&quot;\nQual valor deseja buscar:\n&quot;);
        scanf(&quot;%d&quot;,&amp;valor);
        printf(&quot;\nResultado da busca...achado!:
        %d\n&quot;,buscar(arv.raiz,valor));
    break;
    case 4:
        printf(&quot;\nDigite um valor a ser removido:\n&quot;);
        scanf(&quot;%d&quot;,&amp;valor);
        arv.raiz =remover(arv.raiz,valor);
    break;
    default:
        printf(&quot;\nOpção invalida..\n&quot;);
    }

   } while(op != 0);
    return 0;
}