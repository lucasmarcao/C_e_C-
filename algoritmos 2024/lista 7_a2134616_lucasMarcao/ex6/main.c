
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random(int rows, int cols, int m[rows][cols], int min, int max)
{
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche a matriz com valores aleatórios entre min e max
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = min + rand() % (max - min + 1);
        }
    }
}

int main()
{
    int v[4][6];
    init_random(4, 6, v, 5, 50);

    // Imprime a matriz preenchida com valores aleatórios
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    return 0;
}
