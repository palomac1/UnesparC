#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Teste com manipulação de arquivos
//Realiza teste para medir o tempo para abrir, escrever ou ler um arquivo, e depois excluí-lo.

#define ITERATIONS 1000  // Número de execuções para obter uma média
#define MAX_FILENAME_LEN 50  // Comprimento máximo do nome do arquivo

// Função para gerar um nome de arquivo exclusivo
void gerar_nome_arquivo(char *nome, int indice) {
    sprintf(nome, "tempfile_%d.txt", indice);  // Cria um nome único
}

// Função para medir o tempo de abertura e escrita em um arquivo
double medir_tempo_abrir_arquivo(const char *nome_arquivo) {
    clock_t inicio = clock();  // Marca o início
    FILE *arquivo = fopen(nome_arquivo, "w");  // Abre o arquivo para escrita
    clock_t fim = clock();  // Marca o final

    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo %s.\n", nome_arquivo);
        return 0.0;
    }

    // Grava dados no arquivo para simular uma operação real
    for (int i = 0; i < 100; i++) {
        fprintf(arquivo, "Linha %d: Exemplo de texto.\n", i);
    }

    fclose(arquivo);  // Fecha o arquivo
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;  // Tempo para abrir
}

// Função para medir o tempo de exclusão de um arquivo
double medir_tempo_excluir_arquivo(const char *nome_arquivo) {
    clock_t inicio = clock();  // Marca o início
    int resultado = remove(nome_arquivo);  // Apaga o arquivo
    clock_t fim = clock();  // Marca o final

    if (resultado != 0) {
        printf("Erro: Não foi possível apagar o arquivo %s.\n", nome_arquivo);
        return 0.0;
    }

    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;  // Tempo para excluir
}

// Função para calcular a média de tempos
double calcular_tempo_medio(double *tempos, int iteracoes) {
    double soma = 0.0;  // Soma para calcular a média
    for (int i = 0; i < iteracoes; i++) {
        soma += tempos[i];  // Soma todos os tempos
    }
    return soma / iteracoes;  // Retorna a média
}

int main() {
    double tempos_abrir[ITERATIONS];  // Armazena tempos de abertura
    double tempos_excluir[ITERATIONS];  // Armazena tempos de exclusão

    // Mede o tempo para abrir e excluir os arquivos várias vezes
    for (int i = 0; i < ITERATIONS; i++) {
        char nome_arquivo[MAX_FILENAME_LEN];  // Buffer para o nome do arquivo
        gerar_nome_arquivo(nome_arquivo, i);  // Gera um nome exclusivo

        tempos_abrir[i] = medir_tempo_abrir_arquivo(nome_arquivo);  // Tempo para abrir
        tempos_excluir[i] = medir_tempo_excluir_arquivo(nome_arquivo);  // Tempo para excluir
    }

    // Calcula os tempos médios
    double tempo_medio_abrir = calcular_tempo_medio(tempos_abrir, ITERATIONS);  // Média de abertura
    double tempo_medio_excluir = calcular_tempo_medio(tempos_excluir, ITERATIONS);  // Média de exclusão

    printf("Tempo médio para abrir arquivos: %f segundos\n", tempo_medio_abrir);
    printf("Tempo médio para excluir arquivos: %f segundos\n", tempo_medio_excluir);

    return 0;
}
