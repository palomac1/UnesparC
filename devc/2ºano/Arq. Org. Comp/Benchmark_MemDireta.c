#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//TESTE COM MEMORIA DE BAIXO NIVEL
//Exibe os resultados mais lentamente
//Manipulação direta de memória: Depois de alocar a memória, usamos um ponteiro char para acessar e preencher
//Preenchimento da memória: Simulamos o uso da memória preenchendo-a com valores sequenciais. Isso pode ser útil para testar como o sistema operacional e o hardware lidam com a alocação e o acesso à memória

#define ITERATIONS 1000  // Número de execuções para obter uma média

// Função para medir o tempo de alocação de memória
double medir_tempo_de_alocacao(size_t tamanho) {
    clock_t inicio = clock(); // Marca o tempo de início
    void *bloco = malloc(tamanho); // Aloca memória
    clock_t fim = clock(); // Marca o tempo de fim

    if (bloco != NULL) {
        
        // Manipula a memória diretamente para simular uso
        char *ponteiro = (char *)bloco;
        for (size_t i = 0; i < tamanho; i++) {
            ponteiro[i] = (char)(i % 256); // Preenche a memória com valores
        }

        free(bloco); // Libera a memória
    } else {
        printf("Erro: Não foi possível alocar memória.\n");
    }
    
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Converte para segundos
}

// Função para calcular a média de tempos
double calcular_tempo_medio(double *tempos, int iteracoes) {
    double soma = 0.0;
    for (int i = 0; i < iteracoes; i++) {
        soma += tempos[i];
    }
    return soma / iteracoes;
}

int main() {
    // Tamanhos de alocação para teste
    size_t tamanhos[] = {1024, 8192, 65536, 524288, 4194304}; // 1 KB, 8 KB, 64 KB, 512 KB, 4 MB
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]); // Número de tamanhos

    // Para cada tamanho, medir o tempo de alocação e obter a média
    for (int i = 0; i < num_tamanhos; i++) {
        double tempos[ITERATIONS]; // Array para armazenar tempos de alocação
        size_t tamanho = tamanhos[i]; // Tamanho atual
        
        // Medir o tempo para múltiplas execuções
        for (int j = 0; j < ITERATIONS; j++) {
            tempos[j] = medir_tempo_de_alocacao(tamanho); // Mede o tempo de alocação
        }

        // Calcular o tempo médio de alocação
        double tempo_medio = calcular_tempo_medio(tempos, ITERATIONS); // Calcula a média
        printf("Tempo médio para alocação de %zu bytes: %f segundos\n", tamanho, tempo_medio);
    }

    return 0;
}
