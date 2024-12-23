#include <stdio.h>

void put_totals(int rows, int cols, int m[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        int sum = 0; // Variável para armazenar a soma dos elementos da linha
        for (int j = 0; j < cols - 1; j++)
        {
            sum += m[i][j]; // Soma os elementos da linha
        }
        m[i][cols - 1] = sum; // Atribui a soma ao último elemento da linha
    }
}

int main()
{
    int mat[4][5] = {
        {1, 2, 3, 4, 0},
        {2, 4, 6, 8, 0},
        {3, 6, 9, 12, 0},
        {4, 8, 12, 16, 0}};

    put_totals(4, 5, mat);

    // Imprime a matriz após a chamada da função put_totals
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
