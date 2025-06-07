#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostraTabuleiro(int tabuleiro[10][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10] = {0};

    mostraTabuleiro(tabuleiro);

    

    return 0;
}
