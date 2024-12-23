#include <stdio.h>

void print_reversed(int rows, int cols, int m[rows][cols])
{
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 0; j--)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    print_reversed(3, 3, mat);

    return 0;
}
