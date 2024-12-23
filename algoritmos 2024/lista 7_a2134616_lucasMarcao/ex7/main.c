#include <stdio.h>

int max_line(int rows, int cols, int m[rows][cols])
{
    int max_sum = 0;    // Inicializa a maior soma encontrada
    int max_index = -1; // Inicializa o índice da linha com a maior soma

    // Percorre cada linha da matriz
    for (int i = 0; i < rows; i++)
    {
        int row_sum = 0; // Soma os elementos da linha atual
        for (int j = 0; j < cols; j++)
        {
            row_sum += m[i][j];
        }
        // Verifica se a soma da linha atual é maior que a maior soma encontrada até agora
        if (row_sum > max_sum)
        {
            max_sum = row_sum; // Atualiza a maior soma
            max_index = i;     // Atualiza o índice da linha com a maior soma
        }
    }

    return max_index; // Retorna o índice da linha com a maior soma
}

int main()
{
    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {2, 4, 6, 8, 10},
        {1, 2, 3, 4, 7},
        {2, 0, 99, 1, 10},
        {7, 3, 4, 0, 0}};

    int res = max_line(5, 5, mat);
    printf("Índice da linha com a maior soma: %d\n", res);

    return 0;
}
