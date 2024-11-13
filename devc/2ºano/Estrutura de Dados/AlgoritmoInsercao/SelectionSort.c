#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tam - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tam; j++) {
            (*comparacoes)++;
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = vet[min_idx];
            vet[min_idx] = vet[i];
            vet[i] = temp;
            (*movimentacoes)++;
        }
    }
}

void inicializarVetorAleatorio(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % 1000;  // Valores aleatórios de 0 a 999
    }
}

void inicializarVetorOrdenado(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = i + 1;  // Vetor ordenado de 1 a tam
    }
}

void inicializarVetorInverso(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = tam - i;  // Vetor decrescente de tam a 1
    }
}

void testarSelectionSort(int tam, void (*inicializarVetor)(int[], int), const char *tipo) {
    int *vet = (int *)malloc(tam * sizeof(int));
    inicializarVetor(vet, tam);

    int comparacoes = 0;
    int movimentacoes = 0;

    clock_t inicio = clock();
    selectionSort(vet, tam, &comparacoes, &movimentacoes);
    clock_t fim = clock();

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
    printf("Selection Sort\n\n");

    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        testarSelectionSort(tam, inicializarVetorAleatorio, "Aleatorio");
        testarSelectionSort(tam, inicializarVetorOrdenado, "Ordenado");
        testarSelectionSort(tam, inicializarVetorInverso, "Inverso");
    }

    return 0;
}