#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação Bubble Sort
void bubbleSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tam - 1; i++) { // Percorre o vetor do início ao penúltimo elemento para garantir que o último elemento já está ordenado
        for (int j = 0; j < tam - i - 1; j++) { // Percorre o vetor do início ao penúltimo elemento não ordenado
            (*comparacoes)++; // Incrementa o número de comparações realizadas para verificar se o elemento atual é maior que o próximo
            if (vet[j] > vet[j + 1]) { // Se o elemento atual for maior que o próximo
                int temp = vet[j]; // Troca os elementos de posição
                vet[j] = vet[j + 1]; // O elemento atual recebe o valor do próximo
                vet[j + 1] = temp; // O próximo elemento recebe o valor do elemento atual
                (*movimentacoes)++; // Incrementa o número de movimentações realizadas
            }
        }
    }
}

// Inicializa um vetor com valores aleatórios para teste para testar o caso médio
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

// Testa o algoritmo de ordenação Bubble Sort
void testarBubbleSort(int tam, void (*inicializarVetor)(int[], int), const char *tipo) {
    int *vet = (int *)malloc(tam * sizeof(int)); // Aloca um vetor de tamanho tam para armazenar os valores a serem ordenados
    inicializarVetor(vet, tam); // Inicializa o vetor com valores de acordo com o tipo de vetor

    int comparacoes = 0;
    int movimentacoes = 0;

    // Mede o tempo de execução do algoritmo
    clock_t inicio = clock();
    bubbleSort(vet, tam, &comparacoes, &movimentacoes);
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

    int tamanhos[] = {100, 1000, 10000, 100000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    printf("Bubble Sort\n\n");

    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        testarBubbleSort(tam, inicializarVetorAleatorio, "Aleatorio");
        testarBubbleSort(tam, inicializarVetorOrdenado, "Ordenado");
        testarBubbleSort(tam, inicializarVetorInverso, "Inverso");
    }

    return 0;
}
