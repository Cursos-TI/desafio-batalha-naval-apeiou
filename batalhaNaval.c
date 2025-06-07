#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostraTabuleiro(int tabuleiro[10][10]) { //automatiza a impressão do tabuleiro
    for (int i = 0; i < 10; i++){ //imprime linha refencia do eixo X
        printf(" %c", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < 10; i++){ //imprime matriz 10 x 10
        for (int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main() {
    
    int tabuleiro[10][10] = {0}; //define estado inicial do tabuleiro, todas as casas vazias

    printf("\n"); //quebra de página
    mostraTabuleiro(tabuleiro); //imprime o tabuleiro

    return 0;
}

// tabuleiro[y][x] tabuleiro [i][j]