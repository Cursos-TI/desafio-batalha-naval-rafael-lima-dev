#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Cabeçalhos de colunas
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // 1. Criando o Tabuleiro (Matriz 10x10)
    int tabuleiro[10][10];

    // Inicializando com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Coordenadas iniciais dos navios
    int navio_horizontal[3] = {3, 3, 3};  // tamanho 3
    int navio_vertical[3] = {3, 3, 3};

    int linhaH = 2, colunaH = 4; // navio horizontal em (3, E)
    int linhaV = 5, colunaV = 7; // navio vertical em (6, H)

    // Validação de limites
    if (colunaH + 3 > 10 || linhaV + 3 > 10) {
        printf("Erro: navios fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificar sobreposição
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0 || tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: os navios se sobrepõem.\n");
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

    // 3. Exibir tabuleiro
    printf("\nTABULEIRO BATALHA NAVAL\n  ");

    // Cabeçalho das colunas
    for (int i = 0; i < 10; i++) {
        printf(" %c", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1);  // Números das linhas
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
