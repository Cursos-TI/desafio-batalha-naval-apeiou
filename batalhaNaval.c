#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10 //define tamanho da matriz quadrada

void montaTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) { //monta a matriz base
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void mostraTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) { //imprime o tabuleiro
    printf("   "); //espaçamento da primeira linha
    for (int i = 0; i < TAMANHO; i++){ //imprime linha referencia do eixo X
        printf(" %c", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO; i++){ //imprime matriz 10 x 10
        printf("%2d: ", i + 1); //imprime coluna referencia do eixo y
        for (int j = 0; j < TAMANHO; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void navioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int posY, int posX, int tamanho){ //define posição do navio na horizontal, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY, j = posX + moveIndice;
        if (i < TAMANHO && j < TAMANHO){
            tabuleiro[i][j] = 3;
        }
    }
}

void navioVertical(int tabuleiro[TAMANHO][TAMANHO], int posY, int posX, int tamanho){ //define posição do navio na vertical, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY + moveIndice, j = posX;
        if (i < TAMANHO && j < TAMANHO){
            tabuleiro[i][j] = 3;
        }
    }
}

void navioDiagonalPrincipal(int tabuleiro[TAMANHO][TAMANHO], int posY, int posX, int tamanho){ //define posição do navio na diagonal principal, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY + moveIndice, j = posX + moveIndice;
        if (i < TAMANHO && j < TAMANHO){
            tabuleiro[i][j] = 3;
        }
    } 
}

void navioDiagonalSecundaria(int tabuleiro[TAMANHO][TAMANHO], int posY, int posX, int tamanho) { //define posição do navio na diagonal secundária, de acordo com a posição do primeiro índice
    for (int moveIndice = 0; moveIndice < tamanho; moveIndice++){
        int i = posY + moveIndice, j = posX - moveIndice;
        if (i < TAMANHO && j < TAMANHO){
            tabuleiro[i][j] = 3;
        }  
    }
}

void habilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int posY, int posX){
    if (posY - 1 >= 0 && posX >= 0 && posX < TAMANHO){
        tabuleiro[posY - 1][posX] = 5;
    }
    for (int j = -1; j <= 1; j++){
        if (posY >= 0 && posY < TAMANHO && posX + j >= 0 && posX + j < TAMANHO){
            tabuleiro[posY][posX + j] = 5;
        }
    }
    for (int j = -2; j <= 2; j++){
        if (posY >= 0 && posY < TAMANHO && posX + j >= 0 && posX + j < TAMANHO){
            tabuleiro[posY + 1][posX + j] = 5;
        }
    }
}

void habilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int posY, int posX){
    if (posY - 1 >= 0 && posX >= 0 && posX < TAMANHO){
        tabuleiro[posY - 1][posX] = 5;
    }
    for (int j = -1; j <= 1; j++){
        if (posY >= 0 && posY < TAMANHO && posX + j >= 0 && posX + j < TAMANHO){
            tabuleiro[posY][posX + j] = 5;
        }
    }
    if (posY + 1 >= 0 && posX >= 0 && posX < TAMANHO){
        tabuleiro[posY + 1][posX] = 5;
    }
}


int main() {
    printf("\n"); //quebra de página

    //exibição dos navios
        int tabuleiro[TAMANHO][TAMANHO]; //define tamanho da matriz
        montaTabuleiro(tabuleiro);
        navioHorizontal(tabuleiro, 3, 4, 3); //define posicao do navio 1, sempre horizontal / [3,4][3,5][3,6]
        navioVertical(tabuleiro, 5, 7, 3); //define posicao do navio 2, sempre horizontal / [5,7][6,7][7,7]
        navioDiagonalPrincipal(tabuleiro, 1, 1, 3); //define posicao do navio 3, sempre diagonal principal / [1,1][2,2][3,3]
        navioDiagonalSecundaria(tabuleiro, 5, 4, 3); //define posicao do navio 4, sempre diagonal secundaria / [5,4][6,3][7,2]
        navioDiagonalPrincipal(tabuleiro, 0, 7, 3); //extra - define posicao do navio 5, em diagonal / [0,7][1,8][2,9]
        navioDiagonalSecundaria(tabuleiro, 7, 5, 3); //extra - define posicao do navio 6, em diagonal / [7,5][8,4][9,3]
        habilidadeCone(tabuleiro, 2, 3); //define posicao da habilidade em cone com o centro no indice [2,3]
        habilidadeOctaedro(tabuleiro, 8, 2); //define posicao da habilidade em formato octaedro com o centro no indice [8,2]
        mostraTabuleiro(tabuleiro); //exibe estado atualizado do tabuleiro 

    return 0;
}