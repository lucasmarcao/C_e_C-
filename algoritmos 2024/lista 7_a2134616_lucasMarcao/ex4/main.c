#include <stdio.h>

float average(int rows, int cols, int m[rows][cols])
{
    int total_elements = rows * cols;
    float sum = 0;

    // Soma todos os elementos da matriz
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += m[i][j];
        }
    }

    // Calcula a média aritmética
    float avg = sum / total_elements;

    return avg;
}

int main()
{
    int mat[3][3] = {
        {4, 6, 8},
        {4, 6, 8},
        {4, 6, 8}};

    printf("Média: %.2f\n", average(3, 3, mat));

    return 0;
}
