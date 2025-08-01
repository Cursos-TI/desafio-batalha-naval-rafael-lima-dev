#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro
#define NAVIO 3 // Valor que representa uma parte do navio

int main() {
    // Cabeçalhos de colunas como letras
    const char COLUNAS[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // 1. Criando o Tabuleiro (Matriz 10x10)
    int tabuleiro[TAM][TAM];

    // Inicializando com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Coordenadas iniciais dos navios
    int navio_horizontal[3] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[3] = {NAVIO, NAVIO, NAVIO};
    int navio_diag1[3] = {NAVIO, NAVIO, NAVIO}; // ↘
    int navio_diag2[3] = {NAVIO, NAVIO, NAVIO}; // ↙

    // Coordenadas iniciais
    int linhaH = 2, colunaH = 4;    // (3, E)
    int linhaV = 5, colunaV = 7;    // (6, H)
    int linhaD1 = 0, colunaD1 = 0;  // (1, A)
    int linhaD2 = 0, colunaD2 = 9;  // (1, J)

    // Validação de limites
    if (colunaH + 3 > TAM || linhaV + 3 > TAM ||
        linhaD1 + 3 > TAM || colunaD1 + 3 > TAM ||
        linhaD2 + 3 > TAM || colunaD2 - 2 < 0) {
        printf("Erro: um ou mais navios estão fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificar sobreposição
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0 ||
            tabuleiro[linhaV + i][colunaV] != 0 ||
            tabuleiro[linhaD1 + i][colunaD1 + i] != 0 ||
            tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            printf("Erro: sobreposição de navios detectada.\n");
            return 1;
        }
    }

    // Posicionar navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
    }

    // Posicionar navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
    }

    // Posicionar navio diagonal ↘
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio_diag1[i];
    }

    // Posicionar navio diagonal ↙
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio_diag2[i];
    }

    // 3. Exibir tabuleiro
    printf("\nTABULEIRO BATALHA NAVAL\n  ");
    for (int i = 0; i < TAM; i++) {
        printf(" %c", COLUNAS[i]);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d", i + 1);  // Números das linhas
        for (int j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
