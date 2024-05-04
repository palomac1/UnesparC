#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para a função sleep
#include <string.h>
#include <time.h>

// Interpretador de parâmetros
void interpretar_parametros(int argc, char *argv[], int *S, int *W, int *ts) {
    if (argc != 4) {
        printf("Uso: %s <tamanho_memoria> <leituras_por_ciclo> <tempo_reposo_segundos>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    *S = atoi(argv[1]);
    *W = atoi(argv[2]);
    *ts = atoi(argv[3]);

    if (*S <= 0 || *W <= 0 || *ts < 0) {
        printf("Parâmetros inválidos. S, W devem ser maiores que 0 e ts não pode ser negativo.\n");
        exit(EXIT_FAILURE);
    }
}

// Alocador de memória
char *alocar_memoria(int S) {
    char *memoria = malloc(S * sizeof(char));
    if (memoria == NULL) {
        printf("Falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    return memoria;
}

// Gerador de endereço
int gerar_endereco(int S) {
    return rand() % S; // Gera um endereço aleatório dentro do espaço de memória alocado
}

// Leitura/Escrita
void leitura_escrita(char *memoria, int S, int W) {
    for (int i = 0; i < W; i++) {
        int endereco = gerar_endereco(S);
        // Operação de leitura
        char valor = memoria[endereco];
        // Operação de escrita (modificamos levemente o valor para garantir escrita)
        memoria[endereco] = valor ^ 0xFF; // Operação XOR com um valor constante
    }
}

int main() {
    int S, W, ts;

    // Interpretar parâmetros
    interpretar_parametros(argc, argv, &S, &W, &ts);

    // Alocar memória
    char *memoria = alocar_memoria(S);

    // Iniciar gerador de números aleatórios
    srand((unsigned)time(NULL));

    // Laço principal do benchmark
    while (1) {
        // Executar operações de leitura/escrita
        leitura_escrita(memoria, S, W);

        // Tempo de repouso
        sleep(ts);
    }

    // Liberação da memória alocada (na prática, o loop é infinito, mas é bom liberar memória no final)
    free(memoria);

    return 0;
}
