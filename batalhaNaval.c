#include <stdio.h>
#include <stdlib.h>

// Definição das constantes do sistema
#define TAM 10              // Tamanho do tabuleiro principal (10x10)
#define TAM_HABILIDADE 5    // Tamanho da matriz de cada habilidade (5x5)

/**
 * Inicializa o tabuleiro principal com zeros (representando água)
 * @param tabuleiro: matriz 10x10 que representa o campo de batalha
 */
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    // Percorre todas as posições do tabuleiro
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // 0 = água/vazio
        }
    }
}

/**
 * Gera o padrão de habilidade "Cone"
 * Cria um triângulo que se expande para baixo a partir do centro
 * Padrão resultante:
 *   0 0 1 0 0
 *   0 0 1 0 0  
 *   1 1 1 1 1
 *   0 1 1 1 0
 *   0 0 1 0 0
 * @param habilidade: matriz 5x5 onde será armazenado o padrão
 */
void gerarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica do cone: a partir da linha 2 (centro), expande lateralmente
            // i >= 2: só ativa a partir da linha central para baixo
            // j >= 2 - (i - 2): limite esquerdo do cone
            // j <= 2 + (i - 2): limite direito do cone
            habilidade[i][j] = (i >= 2 && j >= 2 - (i - 2) && j <= 2 + (i - 2)) ? 1 : 0;
        }
    }
}

/**
 * Gera o padrão de habilidade "Cruz"
 * Cria uma cruz centrada na matriz 5x5
 * Padrão resultante:
 *   0 0 1 0 0
 *   0 0 1 0 0
 *   1 1 1 1 1
 *   0 0 1 0 0
 *   0 0 1 0 0
 * @param habilidade: matriz 5x5 onde será armazenado o padrão
 */
void gerarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Ativa se estiver na linha central (i == 2) OU na coluna central (j == 2)
            habilidade[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

/**
 * Gera o padrão de habilidade "Octaedro" (formato de losango/diamante)
 * Usa distância Manhattan para criar um losango centrado
 * Padrão resultante:
 *   0 0 1 0 0
 *   0 1 1 1 0
 *   1 1 1 1 1
 *   0 1 1 1 0
 *   0 0 1 0 0
 * @param habilidade: matriz 5x5 onde será armazenado o padrão
 */
void gerarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Usa distância Manhattan do centro (2,2)
            // abs(i - 2) + abs(j - 2) <= 2 define um losango com raio 2
            habilidade[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }
}

/**
 * Aplica uma habilidade no tabuleiro principal
 * Centraliza a matriz 5x5 da habilidade na posição especificada
 * @param tabuleiro: tabuleiro principal onde aplicar a habilidade
 * @param habilidade: matriz 5x5 com o padrão da habilidade
 * @param origemLinha: linha central onde aplicar a habilidade
 * @param origemColuna: coluna central onde aplicar a habilidade  
 * @param valorEfeito: valor numérico que representa o tipo de habilidade
 */
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int origemLinha, int origemColuna, int valorEfeito) {
    
    // Percorre toda a matriz 5x5 da habilidade
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            
            // Calcula a posição correspondente no tabuleiro principal
            // Subtrai TAM_HABILIDADE/2 para centralizar a habilidade na origem
            int l = origemLinha - TAM_HABILIDADE/2 + i;    // linha no tabuleiro
            int c = origemColuna - TAM_HABILIDADE/2 + j;   // coluna no tabuleiro
            
            // Verifica se a posição está dentro dos limites do tabuleiro
            // E se a habilidade está ativa nesta posição (habilidade[i][j] == 1)
            // E se a célula do tabuleiro está vazia (tabuleiro[l][c] == 0)
            if (l >= 0 && l < TAM && c >= 0 && c < TAM && 
                habilidade[i][j] == 1 && tabuleiro[l][c] == 0) {
                
                tabuleiro[l][c] = valorEfeito; // Aplica o efeito
            }
        }
    }
}

/**
 * Exibe o tabuleiro de forma visual com coordenadas
 * Mostra colunas com letras (A-J) e linhas com números (1-10)
 * @param tabuleiro: matriz 10x10 a ser exibida
 */
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    // Array com as letras das colunas
    char colunas[] = "ABCDEFGHIJ";
    
    // Imprime o cabeçalho com as letras das colunas
    printf("\n    "); // Espaço para alinhar com os números das linhas
    for (int i = 0; i < TAM; i++) {
        printf(" %c", colunas[i]);
    }
    printf("\n");

    // Imprime cada linha do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i + 1); // Número da linha + separador
        
        // Imprime cada célula da linha
        for (int j = 0; j < TAM; j++) {
            // Traduz os valores numéricos para símbolos visuais
            if (tabuleiro[i][j] == 0) {
                printf(" ~");      // Água/vazio
            } else if (tabuleiro[i][j] == 5) {
                printf(" *");      // Cone
            } else if (tabuleiro[i][j] == 6) {
                printf(" +");      // Cruz  
            } else if (tabuleiro[i][j] == 7) {
                printf(" #");      // Octaedro
            } else {
                printf(" ?");      // Valor desconhecido
            }
        }
        printf("\n");
    }

    // Imprime a legenda explicativa
    printf("\nLegenda: ~ = água, * = cone, + = cruz, # = octaedro\n");
    printf("Posições centrais: Cruz (2,2), Cone (6,2), Octaedro (5,7)\n");
}

/**
 * Função principal - demonstra o sistema de habilidades
 */
int main() {
    // Declara o tabuleiro principal
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Declara as matrizes para armazenar os padrões das habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE]; 
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    // Gera os padrões de cada habilidade
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica as habilidades em posições específicas do tabuleiro
    aplicarHabilidade(tabuleiro, cruz, 2, 2, 6);        // Cruz na posição (2,2) com valor 6
    aplicarHabilidade(tabuleiro, cone, 6, 2, 5);        // Cone na posição (6,2) com valor 5  
    aplicarHabilidade(tabuleiro, octaedro, 5, 7, 7);    // Octaedro na posição (5,7) com valor 7

    // Exibe o resultado final
    exibirTabuleiro(tabuleiro);
    
    return 0; // Indica execução bem-sucedida
}