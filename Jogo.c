#include <stdio.h>

void printTabuleiro(char tabuleiro[3][3]) {
    printf("\nJogo da Velha\n\n");
    printf(" 0 | 1 | 2 \n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
}

int verificarLinhas(char tabuleiro[3][3]) {
    for (int linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] &&
            tabuleiro[linha][1] == tabuleiro[linha][2] &&
            tabuleiro[linha][0] != ' ') {
            printf("Vitória na linha %d para o jogador '%c'\n", linha, tabuleiro[linha][0]);
            return 1;
        }
    }
    return 0;
}

int verificarColunas(char tabuleiro[3][3]) {
    for (int coluna = 0; coluna < 3; coluna++) {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] &&
            tabuleiro[1][coluna] == tabuleiro[2][coluna] &&
            tabuleiro[0][coluna] != ' ') {
            printf("Vitória na coluna %d para o jogador '%c'\n", coluna, tabuleiro[0][coluna]);
            return 1;
        }
    }
    return 0;
}

int verificarDiagonal(char tabuleiro[3][3]) {
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        printf("Vitória na diagonal principal para o jogador '%c'\n", tabuleiro[0][0]);
        return 1;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        printf("Vitória na diagonal secundária para o jogador '%c'\n", tabuleiro[0][2]);
        return 1;
    }
    return 0;
}

int verificarVitoria(char tabuleiro[3][3]) {
    return verificarLinhas(tabuleiro) || verificarColunas(tabuleiro) || verificarDiagonal(tabuleiro);
}

void preencherTabuleiro(char tabuleiro[3][3]) {
    // Inicializa o tabuleiro
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';

    int l, c;
    char valor;

    for (int jogada = 0; jogada < 9; jogada++) {
        do {
            printf("Digite a posição da linha (0 a 2): ");
            scanf("%d", &l);

            printf("Digite a posição da coluna (0 a 2): ");
            scanf("%d", &c);

            if (l < 0 || l > 2 || c < 0 || c > 2) {
                printf("Posição fora do tabuleiro. Tente novamente.\n");
                continue;
            }

            if (tabuleiro[l][c] != ' ') {
                printf("Posição já ocupada. Escolha outra.\n");
                continue;
            }

            printf("Digite o valor (x ou o): ");
            scanf(" %c", &valor);

            if (valor != 'x' && valor != 'o') {
                printf("Valor inválido! Use apenas 'x' ou 'o'.\n");
            }

        } while (l < 0 || l > 2 || c < 0 || c > 2 || tabuleiro[l][c] != ' ' || (valor != 'x' && valor != 'o'));

        tabuleiro[l][c] = valor;
        printTabuleiro(tabuleiro);

        if (verificarVitoria(tabuleiro)) {
            printf("Fim de jogo!\n");
            return;
        }
    }

    printf("Empate! Ninguém venceu.\n");
}

int main(int argc, char *argv[]) {
    char tabuleiro[3][3];
    printTabuleiro(tabuleiro);      // Exibe
    preencherTabuleiro(tabuleiro);
    printTabuleiro(tabuleiro);      // Exibe
    verificarLinhas(tabuleiro);     // Verifica linhas
    verificarColunas(tabuleiro);    // Verifica colunas
    verificarDiagonal(tabuleiro);   // Verifica diagonal

    return 0;
}