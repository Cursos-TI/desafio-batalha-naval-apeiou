#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUADRADO 10 //define tamanho da matriz quadrada

void montaTabuleiro(char tabuleiro[QUADRADO][QUADRADO]) {
    for (int i = 0; i < QUADRADO; i++){ //define todos os índices como '0'
        for (int j = 0; j < QUADRADO; j++){
            tabuleiro[i][j] = '0';
        }
    }
}

void mostraTabuleiro(char tabuleiro[QUADRADO][QUADRADO]) { //automatiza a impressão do tabuleiro
    printf("   "); //espaçamento da primeira linha
    for (int i = 0; i < QUADRADO; i++){ //imprime linha referencia do eixo X
        printf(" %c", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < QUADRADO; i++){ //imprime matriz 10 x 10
        printf("%2d: ", i + 1); //imprime coluna referencia do eixo y
        for (int j = 0; j < QUADRADO; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("\n"); //quebra de página

    //monta tabuleiro
        char tabuleiro[QUADRADO][QUADRADO]; //define tamanho da matriz
        montaTabuleiro(tabuleiro);
    
    //define posicao do navio um, sempre horizontal
        int navioUmY = 3, navioUmX = 4;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioUmY][navioUmX + i] = 'X';
        }
    
    //define posicao do navio um, sempre horizontal
        int navioDoisY = 5, navioDoisX = 7;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioDoisY + i][navioDoisX] = 'X';
        }

    //exibe estado atualizado do tabuleiro
        mostraTabuleiro(tabuleiro); //imprime o tabuleiro

    return 0;
}

// tabuleiro[y][x] tabuleiro [i][j]
// tabuleiro 10 por 10
// navio 1 3E, 3F, 3G
// navio 2 6H, 7H, 8H