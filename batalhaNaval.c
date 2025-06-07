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
    
    //define posicao do navio um, sempre horizontal / [3,4][3,5][3,6]
        int navioUmY = 3, navioUmX = 4;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioUmY][navioUmX + i] = 3;
        }
    
    //define posicao do navio dois, sempre horizontal / [5,7][6,7][7,7]
        int navioDoisY = 5, navioDoisX = 7;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioDoisY + i][navioDoisX] = 3;
        }

    //define posicao do navio três, sempre diagonal principal / [1,1][2,2][3,3]
        int navioTres = 1;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioTres + i][navioTres + i] = 3;
        }
        
    //define posicao do navio quatro, sempre diagonal secundaria / [5,4][6,3][7,2]
        int navioQuatroY = 5, navioQuatroX = 4;
        for (int i = 0; i < 3; i++){
            tabuleiro[navioQuatroY + i][navioQuatroX - i] = 3;
        }
        
    //exibe estado atualizado do tabuleiro
        mostraTabuleiro(tabuleiro); //imprime o tabuleiro

    return 0;
}

// tabuleiro[y][x] tabuleiro [i][j]
// tabuleiro 10 por 10
// navio 1 3E, 3F, 3G
// navio 2 6H, 7H, 8H
// navio 3 2B, 3C, 4D
// navio 4 6E, 7D, 8C