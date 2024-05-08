#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//TESTE USANDO SRAND PARA NUMEROS ALEATORIOS E MEM BAIXO NIVEL
//Garante resultados diferentes em todos os testes por usar o tempo atual
//Preenche com numeros aletorios todas as vezes
//Acessa a memoria com blocos separados de maneira imprevisivel, garantindo o uso durante testes mais complexos
//Exibe mais lentamente
//Arrumar os acentos

#define ITERATIONS 1000  // Número de execuções para obter uma média

// Função para medir o tempo de alocação de memória
void medir_tempos(size_t tamanho, double *tempo_alocacao, double *tempo_manipulacao) {
    // Medir o tempo de alocação
    clock_t inicio_alocacao = clock(); // Tempo de início da alocação
    void *bloco = malloc(tamanho); // Aloca memória
    clock_t fim_alocacao = clock(); // Tempo de fim da alocação

    if (bloco != NULL) {
        // Inicializa a semente para o gerador de números aleatórios
        srand((unsigned int)time(NULL)); 

        // Mede o tempo de manipulação de forma aleatória
        clock_t inicio_manipulacao = clock(); // Tempo de início da manipulação aleatória
        char *ponteiro = (char *)bloco;
        for (size_t i = 0; i < tamanho; i++) {
            ponteiro[i] = (char)(rand() % 256); // Preenche com valores aleatórios
        }
        clock_t fim_manipulacao = clock(); // Tempo de fim da manipulação aleatória

        // Mede o tempo de manipulação de forma sequencial
        clock_t inicio_sequencial = clock(); // Tempo de início da manipulação sequencial
        for (size_t i = 0; i < tamanho; i++) {
            ponteiro[i] = (char)(ponteiro[i] + 1); // Manipulação sequencial
        }
        clock_t fim_sequencial = clock(); // Tempo de fim da manipulação sequencial

        free(bloco); // Libera a memória alocada

        // Calcular os tempos de alocacao para ambos os testes
        *tempo_alocacao = ((double)(fim_alocacao - inicio_alocacao)) / CLOCKS_PER_SEC;
        *tempo_manipulacao = ((double)(fim_sequencial - inicio_sequencial)) / CLOCKS_PER_SEC;
    } else {
        printf("Erro: Não foi possível alocar memória.\n");
    }
}

// Função para calcular a média dos tempos
double calcular_tempo_medio(double *tempos, int iteracoes) {
    double soma = 0.0;
    for (int i = 0; i < iteracoes; i++) {
        soma += tempos[i]; // Soma todos os tempos
    }
    return soma / iteracoes; // Retorna a média
}

int main() {
    char c; 

    // Tamanhos de alocação para os testes
    size_t tamanhos[] = {1024, 8192, 65536, 524288, 4194304}; // 1 KB, 8 KB, 64 KB, 512 KB, 4 MB
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]); // Número de tamanhos

    printf("Benchmark para Alocacao de Memoria\n");

    // Para cada tamanho, medir os tempos de alocação e manipulação, e obter a média
    for (int i = 0; i < num_tamanhos; i++) {
        double tempos_alocacao[ITERATIONS]; // Array para armazenar tempos de alocação
        double tempos_manipulacao[ITERATIONS]; // Armazenar tempos de manipulação
        size_t tamanho = tamanhos[i]; // Tamanho atual
        
        // Mede o tempo para múltiplas execuções
        for (int j = 0; j < ITERATIONS; j++) {
            double tempo_alocacao;
            double tempo_manipulacao;
            medir_tempos(tamanho, &tempo_alocacao, &tempo_manipulacao); 
            tempos_alocacao[j] = tempo_alocacao;
            tempos_manipulacao[j] = tempo_manipulacao;
        }

        // Calcular a média dos tempos de alocação e manipulação
        double tempo_medio_alocacao = calcular_tempo_medio(tempos_alocacao, ITERATIONS);
        double tempo_medio_manipulacao = calcular_tempo_medio(tempos_manipulacao, ITERATIONS);

        // Exibir resultados
        printf("\nPara %zu bytes:\n", tamanho);
        printf(" - Tempo medio para manipulacao aleatoria: %f segundos\n", tempo_medio_alocacao);
        printf(" - Tempo medio para manipulacao sequencial: %f segundos\n", tempo_medio_manipulacao);
    }

    printf("\nDigite uma tecla para finalizar.");

    if (scanf("%c", &c) == 1) {
        return 0;
    }
}
