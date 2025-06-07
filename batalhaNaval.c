#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUADRADO 10 //define tamanho da matriz quadrada

void montaTabuleiro(int tabuleiro[QUADRADO][QUADRADO]) { //monta a matriz base
    for (int i = 0; i < QUADRADO; i++){
        for (int j = 0; j < QUADRADO; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void mostraTabuleiro(int tabuleiro[QUADRADO][QUADRADO]) { //imprime o tabuleiro
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

void navioHorizontal(int tabuleiro[QUADRADO][QUADRADO], int posY, int posX, int tamanho){ //define posição do navio na horizontal, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY, j = posX + moveIndice;
        if (i < QUADRADO && j < QUADRADO){
            tabuleiro[i][j] = 3;
        }
    }
}

void navioVertical(int tabuleiro[QUADRADO][QUADRADO], int posY, int posX, int tamanho){ //define posição do navio na vertical, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY + moveIndice, j = posX;
        if (i < QUADRADO && j < QUADRADO){
            tabuleiro[i][j] = 3;
        }
    }
}

void navioDiagonalPrincipal(int tabuleiro[QUADRADO][QUADRADO], int posY, int posX, int tamanho){ //define posição do navio na diagonal principal, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY + moveIndice, j = posX + moveIndice;
        if (i < QUADRADO && j < QUADRADO){
            tabuleiro[i][j] = 3;
        }
    } 
}

void navioDiagonalSecundaria(int tabuleiro[QUADRADO][QUADRADO], int posY, int posX, int tamanho) { //define posição do navio na diagonal secundária, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY + moveIndice, j = posX - moveIndice;
        if (i < QUADRADO && j < QUADRADO){
            tabuleiro[i][j] = 3;
        }  
    }
}


int main() {
    printf("\n"); //quebra de página

//monta tabuleiro
    int tabuleiro[QUADRADO][QUADRADO]; //define tamanho da matriz
    montaTabuleiro(tabuleiro);

//define posicao do navio 1, sempre horizontal / [3,4][3,5][3,6]
    navioHorizontal(tabuleiro, 3, 4, 3);

//define posicao do navio 2, sempre horizontal / [5,7][6,7][7,7]
    navioVertical(tabuleiro, 5, 7, 3);

//define posicao do navio 3, sempre diagonal principal / [1,1][2,2][3,3]
    navioDiagonalPrincipal(tabuleiro, 1, 1, 3);
    
//define posicao do navio 4, sempre diagonal secundaria / [5,4][6,3][7,2]
    navioDiagonalSecundaria(tabuleiro, 5, 4, 3);
    
//extra - define posicao do navio 5, em diagonal / [0,7][1,8][2,9
    navioDiagonalPrincipal(tabuleiro, 0, 7, 3);
    
//extra - define posicao do navio 6, em diagonal / [7,5][8,4][9,3]
    navioDiagonalSecundaria(tabuleiro, 7, 5, 3);

//exibe estado atualizado do tabuleiro 
    mostraTabuleiro(tabuleiro); //imprime o tabuleiro

    return 0;
}