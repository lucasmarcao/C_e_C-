#include <stdio.h>

void init_values(int rows, int cols, int m[rows][cols], int start, int step)
{
    int value = start;

    // Percorre a matriz e atribui os valores
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = value;
            value += step;
        }
    }
}

int main()
{
    int v[4][6];
    init_values(4, 6, v, 10, 2);

    // Imprime a matriz após a inicialização
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
