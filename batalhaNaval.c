#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUADRADO 10 //define tamanho da matriz quadrada

void montaTabuleiro(int tabuleiro[QUADRADO][QUADRADO]) {
    for (int i = 0; i < QUADRADO; i++){ //define todos os índices como 0
        for (int j = 0; j < QUADRADO; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void mostraTabuleiro(int tabuleiro[QUADRADO][QUADRADO]) { //automatiza a impressão do tabuleiro
    printf("   "); //espaçamento da primeira linha
    for (int i = 0; i < QUADRADO; i++){ //imprime linha referencia do eixo X
        printf(" %c", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < QUADRADO; i++){ //imprime matriz 10 x 10
        printf("%2d: ", i + 1); //imprime coluna referencia do eixo y
        for (int j = 0; j < QUADRADO; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("\n"); //quebra de página

    //monta tabuleiro
        int tabuleiro[QUADRADO][QUADRADO]; //define tamanho da matriz
        montaTabuleiro(tabuleiro);
    
    //define posicao do navio um, sempre horizontal
        int navioUmY = 3, navioUmX = 4;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioUmY][navioUmX + i] = 3;
        }
    
    //define posicao do navio dois, sempre horizontal
        int navioDoisY = 5, navioDoisX = 7;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioDoisY + i][navioDoisX] = 3;
        }

    //define posicao do navio três, sempre diagonal principal

    //define posicao do navio quatro, sempre diagonal secundaria


    //exibe estado atualizado do tabuleiro
        mostraTabuleiro(tabuleiro); //imprime o tabuleiro

    return 0;
}

// tabuleiro[y][x] tabuleiro [i][j]
// tabuleiro 10 por 10
// navio 1 3E, 3F, 3G
// navio 2 6H, 7H, 8H