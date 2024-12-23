#include <stdio.h>

void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int m3[rows][cols])
{
    // Percorre cada elemento correspondente das matrizes m1 e m2
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Soma os elementos correspondentes e atribui o resultado à matriz m3
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

int main()
{
    int m1[3][2] = {
        {1, 3},
        {1, 0},
        {1, 2}};

    int m2[3][2] = {
        {0, 4},
        {7, 5},
        {2, 1}};

    int m3[3][2];

    sum(3, 2, m1, m2, m3);

    // Imprime a matriz resultante m3
    printf("m3\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
