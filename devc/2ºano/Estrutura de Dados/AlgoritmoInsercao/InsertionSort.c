#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação Insertion Sort 
void insertionSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 1; i < tam; i++) {
        int chave = vet[i]; // Armazena o valor do elemento atual do vetor
        int j = i - 1; // Armazena o índice do elemento anterior ao elemento atual
        (*comparacoes)++; // Incrementa o número de comparações
        while (j >= 0 && vet[j] > chave) { // Enquanto o índice do elemento anterior for maior ou igual a 0 e o valor do elemento anterior for maior que o valor do elemento atual
            vet[j + 1] = vet[j]; // O valor do elemento anterior é movido para a direita
            j = j - 1;  // Decrementa o índice do elemento anterior
            (*movimentacoes)++; // Incrementa o número de movimentações para a direita
            (*comparacoes)++; // Incrementa o número de comparações para verificar se o laço deve continuar
        }
        // O laço termina quando o índice do elemento anterior for menor que 0 ou o valor do elemento anterior for menor ou igual ao valor do elemento atual
        vet[j + 1] = chave;
        (*movimentacoes)++;
    }
}

// Inicializa um vetor com valores aleatórios para teste  para testar o caso médio
void inicializarVetorAleatorio(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % 10000;
    }
}

// Inicializa um vetor ordenado para teste para testar o melhor caso
void inicializarVetorOrdenado(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = i;
    }
}

// Inicializa um vetor ordenado de forma inversa para teste para testar o pior caso
void inicializarVetorInverso(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = tam - i - 1;
    }
}

// Testa o algoritmo de ordenação Insertion Sort 
void testarInsertionSort(int tam, void (*inicializarVetor)(int[], int), const char *tipo) { // Função de inicialização do vetor que contém os valores a serem ordenados
    int *vet = (int *)malloc(tam * sizeof(int)); // Aloca um vetor de tamanho tam para armazenar os valores a serem ordenados
    inicializarVetor(vet, tam); // Inicializa o vetor com valores de acordo com o tipo de vetor

    int comparacoes = 0;
    int movimentacoes = 0;

    // Mede o tempo de execução do algoritmo
    clock_t inicio = clock();
    insertionSort(vet, tam, &comparacoes, &movimentacoes);
    clock_t fim = clock();

    // Calcula o tempo de execução do algoritmo em segundos
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tipo de vetor: %s\n", tipo);
    printf("Tamanho do vetor: %d\n", tam);
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Numero de movimentacoes: %d\n", movimentacoes);
    printf("\n");

    free(vet);
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {100, 1000, 10000, 100000}; // Tamanhos dos vetores a serem testados
    // Recebe o número de tamanhos a serem testados e armazena em numTamanhos, dividindo o tamanho do vetor tamanhos pelo tamanho de um inteiro
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    printf("Insertion Sort\n\n"); 

    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        testarInsertionSort(tam, inicializarVetorAleatorio, "Aleatorio");
        testarInsertionSort(tam, inicializarVetorOrdenado, "Ordenado");
        testarInsertionSort(tam, inicializarVetorInverso, "Inverso");
    }

    return 0;
}