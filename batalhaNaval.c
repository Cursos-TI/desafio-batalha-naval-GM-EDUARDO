/*#include <stdio.h>

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
}*/
#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {

    // ===== TABULEIRO =====
    int tabuleiro[TAM][TAM];

    // Inicializa com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===== NAVIOS =====
    int navio[NAVIO] = {3, 3, 3};

    // ===== COORDENADAS =====
    // Horizontal
    int linhaH = 1, colunaH = 2;

    // Vertical
    int linhaV = 5, colunaV = 0;

    // Diagonal principal (↘)
    int linhaD1 = 0, colunaD1 = 0;

    // Diagonal secundária (↙)
    int linhaD2 = 0, colunaD2 = 9;

    // ===== VALIDAÇÕES =====

    // Horizontal
    if (colunaH + NAVIO > TAM) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // Vertical
    if (linhaV + NAVIO > TAM) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // Diagonal principal
    if (linhaD1 + NAVIO > TAM || colunaD1 + NAVIO > TAM) {
        printf("Erro: Navio diagonal (↘) fora do tabuleiro!\n");
        return 1;
    }

    // Diagonal secundária
    if (linhaD2 + NAVIO > TAM || colunaD2 - (NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal (↙) fora do tabuleiro!\n");
        return 1;
    }

    // ===== POSICIONAMENTO =====

    // Horizontal
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Sobreposição detectada (horizontal)\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = navio[i];
    }

    // Vertical
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Sobreposição detectada (vertical)\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = navio[i];
    }

    // Diagonal principal (↘)
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
            printf("Erro: Sobreposição detectada (diagonal ↘)\n");
            return 1;
        }
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
    }

    // Diagonal secundária (↙)
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            printf("Erro: Sobreposição detectada (diagonal ↙)\n");
            return 1;
        }
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
    }

    // ===== EXIBIÇÃO =====
    printf("\n=== TABULEIRO 10x10 ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // ===== COORDENADAS =====
    printf("\n=== COORDENADAS DOS NAVIOS ===\n");

    printf("\nNavio Horizontal:\n");
    for (int i = 0; i < NAVIO; i++) {
        printf("(%d, %d)\n", linhaH, colunaH + i);
    }

    printf("\nNavio Vertical:\n");
    for (int i = 0; i < NAVIO; i++) {
        printf("(%d, %d)\n", linhaV + i, colunaV);
    }

    printf("\nNavio Diagonal (↘):\n");
    for (int i = 0; i < NAVIO; i++) {
        printf("(%d, %d)\n", linhaD1 + i, colunaD1 + i);
    }

    printf("\nNavio Diagonal (↙):\n");
    for (int i = 0; i < NAVIO; i++) {
        printf("(%d, %d)\n", linhaD2 + i, colunaD2 - i);
    }

    return 0;
}