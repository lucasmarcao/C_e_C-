#include <stdio.h>

int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2])
{
    // Verifica se as dimensões das matrizes são iguais
    if (r1 != r2 || c1 != c2)
    {
        return 0; // Retorna 0 (false) se as dimensões forem diferentes
    }

    // Compara cada elemento correspondente das duas matrizes
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (m1[i][j] != m2[i][j])
            {
                return 0; // Retorna 0 (false) se encontrar elementos diferentes
            }
        }
    }

    // Se todas as comparações forem iguais, retorna 1 (true)
    return 1;
}

int main()
{
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int mat2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int mat3[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    printf("mat1 == mat2: %d\n", matrix_equals(3, 3, mat1, 3, 3, mat2)); // Esperado: 1 (true)
    printf("mat1 == mat3: %d\n", matrix_equals(3, 3, mat1, 3, 3, mat3)); // Esperado: 0 (false)

    return 0;
}
