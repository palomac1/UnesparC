#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação Selection Sort
void selectionSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tam - 1; i++) { // Percorre o vetor do início ao penúltimo elemento para garantir que o último elemento já está ordenado
        int min_idx = i; // Armazena o índice do menor elemento do vetor não ordenado inicialmente como o primeiro elemento
        for (int j = i + 1; j < tam; j++) { // Percorre o vetor do segundo elemento ao último elemento não ordenado
            (*comparacoes)++; // Incrementa o número de comparações realizadas para verificar se o elemento atual é menor que o menor elemento
            if (vet[j] < vet[min_idx]) { // Se o elemento atual for menor que o menor elemento
                min_idx = j; // O índice do menor elemento é atualizado
            }
        }
        if (min_idx != i) { // Se o índice do menor elemento for diferente do índice do primeiro elemento não ordenado
            int temp = vet[min_idx]; // Troca os elementos de posição
            vet[min_idx] = vet[i];  // O menor elemento é movido para a posição do primeiro elemento não ordenado
            vet[i] = temp; // O primeiro elemento não ordenado é movido para a posição do menor elemento
            (*movimentacoes) += 3; // Incrementa o número de movimentações realizadas
            (*movimentacoes)++; // Incrementa o número de movimentações realizadas
        }
    }
}

// Inicializa um vetor com valores aleatórios para teste para testar o caso médio
void inicializarVetorAleatorio(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % 1000;  
    }
}

// Inicializa um vetor ordenado para teste para testar o melhor caso
void inicializarVetorOrdenado(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = i + 1;  // 
    }
}

// Inicializa um vetor ordenado de forma inversa para teste para testar o pior caso
void inicializarVetorInverso(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = tam - i; 
    }
}

// Testa o algoritmo de ordenação Selection Sort
void testarSelectionSort(int tam, void (*inicializarVetor)(int[], int), const char *tipo) {
    int *vet = (int *)malloc(tam * sizeof(int)); // Aloca um vetor de tamanho tam para armazenar os valores a serem ordenados
    inicializarVetor(vet, tam); // Inicializa o vetor com valores de acordo com o tipo de vetor

    int comparacoes = 0;
    int movimentacoes = 0;

    // Mede o tempo de execução do algoritmo
    clock_t inicio = clock();
    selectionSort(vet, tam, &comparacoes, &movimentacoes);
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
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]); 
    printf("Selection Sort\n\n");

    for (int i = 0; i < numTamanhos; i++) { // Percorre os tamanhos dos vetores a serem testados
        int tam = tamanhos[i];
        testarSelectionSort(tam, inicializarVetorAleatorio, "Aleatorio");
        testarSelectionSort(tam, inicializarVetorOrdenado, "Ordenado");
        testarSelectionSort(tam, inicializarVetorInverso, "Inverso");
    }

    return 0;
}