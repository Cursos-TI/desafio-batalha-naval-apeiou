#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostraTabuleiro(char tabuleiro[10][10]) { //automatiza a impressão do tabuleiro
    printf("   "); //espaçamento da primeira linha
    for (int i = 0; i < 10; i++){ //imprime linha referencia do eixo X
        printf(" %c", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < 10; i++){ //imprime matriz 10 x 10
        printf("%2d. ", i + 1); //imprime coluna referencia do eixo y
        for (int j = 0; j < 10; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[10][10]; //define tamanho da matriz
        for (int i = 0; i < 10; i++){ //define todos os índices como '0'
            for (int j = 0; j < 10; j++){
                tabuleiro[i][j] = '0';
            }
        }
    
    char navioUm[3] = {tabuleiro[3][4] = 'X', tabuleiro[3][5] = 'X', tabuleiro[3][6] = 'X'};
    char navioDois[3] = {tabuleiro[5][7] = 'X', tabuleiro[6][7] = 'X', tabuleiro[7][7] = 'X'};

    printf("\n"); //quebra de página
    mostraTabuleiro(tabuleiro); //imprime o tabuleiro

    return 0;
}

// tabuleiro[y][x] tabuleiro [i][j]
// tabuleiro 10 por 10
// navio 1 3E, 3F, 3G
// navio 2 6H, 7H, 8H