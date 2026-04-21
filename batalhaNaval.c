#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Tamanho dos navios

int main() {

    // ===== TABULEIRO =====
    int tabuleiro[TAM][TAM];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===== NAVIOS =====
    int navio_horizontal[NAVIO] = {3, 3, 3};
    int navio_vertical[NAVIO] = {3, 3, 3};

    // Coordenadas iniciais (definidas manualmente)
    int linhaH = 2, colunaH = 4; // navio horizontal
    int linhaV = 5, colunaV = 1; // navio vertical

    // ===== VALIDAÇÃO DE LIMITES =====
    if (colunaH + NAVIO > TAM) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    if (linhaV + NAVIO > TAM) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // ===== POSICIONAR NAVIO HORIZONTAL =====
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Sobreposição de navios!\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
    }

    // ===== POSICIONAR NAVIO VERTICAL =====
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Sobreposição de navios!\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
    }

    // ===== EXIBIR TABULEIRO =====
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // ===== EXIBIR COORDENADAS =====
    printf("\n=== COORDENADAS DOS NAVIOS ===\n");

    printf("\nNavio Horizontal:\n");
    for (int i = 0; i < NAVIO; i++) {
        printf("(%d, %d)\n", linhaH, colunaH + i);
    }

    printf("\nNavio Vertical:\n");
    for (int i = 0; i < NAVIO; i++) {
        printf("(%d, %d)\n", linhaV + i, colunaV);
    }

    return 0;
}