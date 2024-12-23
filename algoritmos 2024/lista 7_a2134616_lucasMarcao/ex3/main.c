#include <stdio.h>

void print_min_max(int rows, int cols, int m[rows][cols])
{
    int min = m[0][0]; // Assume que o primeiro elemento é o menor
    int max = m[0][0]; // Assume que o primeiro elemento é o maior

    // Percorre a matriz para encontrar o menor e o maior valores
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (m[i][j] < min)
            {
                min = m[i][j]; // Atualiza o menor valor
            }
            if (m[i][j] > max)
            {
                max = m[i][j]; // Atualiza o maior valor
            }
        }
    }

    // Imprime o menor e o maior valores
    printf("Menor valor: %d\n", min);
    printf("Maior valor: %d\n", max);
}

int main()
{
    int mat[3][3] = {
        {66, 2, 3},
        {4, 78, 6},
        {7, 1, 9}};

    print_min_max(3, 3, mat);

    return 0;
}
