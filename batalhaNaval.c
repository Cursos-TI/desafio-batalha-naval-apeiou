#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int index;
    int tabuleiro[10][10] = {0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
