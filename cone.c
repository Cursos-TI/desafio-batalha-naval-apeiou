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


int main() {
    printf("\n"); //quebra de página

    //exibição dos navios
        int tabuleiro[TAMANHO][TAMANHO]; //define tamanho da matriz
        montaTabuleiro(tabuleiro);
        habilidadeCone(tabuleiro, 6, 5);
        mostraTabuleiro(tabuleiro); //exibe estado atualizado do tabuleiro 

    return 0;
}