#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            (*comparacoes)++;
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                (*movimentacoes)++;
            }
        }
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

void testarBubbleSort(int tam, void (*inicializarVetor)(int[], int), const char *tipo) {
    int *vet = (int *)malloc(tam * sizeof(int));
    inicializarVetor(vet, tam);

    int comparacoes = 0;
    int movimentacoes = 0;

    clock_t inicio = clock();
    bubbleSort(vet, tam, &comparacoes, &movimentacoes);
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
    printf("Bubble Sort\n\n");

    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        testarBubbleSort(tam, inicializarVetorAleatorio, "Aleatorio");
        testarBubbleSort(tam, inicializarVetorOrdenado, "Ordenado");
        testarBubbleSort(tam, inicializarVetorInverso, "Inverso");
    }

    return 0;
}
