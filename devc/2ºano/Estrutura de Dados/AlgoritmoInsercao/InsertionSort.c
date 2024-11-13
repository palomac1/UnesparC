#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 1; i < tam; i++) {
        int chave = vet[i];
        int j = i - 1;
        (*comparacoes)++;
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j = j - 1;
            (*movimentacoes)++;
            (*comparacoes)++;
        }
        vet[j + 1] = chave;
        (*movimentacoes)++;
    }
}

void inicializarVetorAleatorio(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % 10000;
    }
}

void inicializarVetorOrdenado(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = i;
    }
}

void inicializarVetorInverso(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = tam - i - 1;
    }
}

void testarInsertionSort(int tam, void (*inicializarVetor)(int[], int), const char *tipo) {
    int *vet = (int *)malloc(tam * sizeof(int));
    inicializarVetor(vet, tam);

    int comparacoes = 0;
    int movimentacoes = 0;

    clock_t inicio = clock();
    insertionSort(vet, tam, &comparacoes, &movimentacoes);
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
    printf("Insertion Sort\n\n");

    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        testarInsertionSort(tam, inicializarVetorAleatorio, "Aleatorio");
        testarInsertionSort(tam, inicializarVetorOrdenado, "Ordenado");
        testarInsertionSort(tam, inicializarVetorInverso, "Inverso");
    }

    return 0;
}