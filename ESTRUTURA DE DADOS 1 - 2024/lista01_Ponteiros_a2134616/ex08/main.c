#include <stdio.h>
#include <stdlib.h>

void print_vector2D(int m, int n, const int** v) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", v[i][j]);
            if (j < n - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main() {
    int m = 3; // número de linhas
    int n = 4; // número de colunas

    // Alocação da matriz 2D
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Preenchendo a matriz com alguns valores
    int value = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = value++;
        }
    }

    // Imprimindo a matriz
    printf("Conteúdo da matriz:\n");
    print_vector2D(m, n, (const int**)matrix);

    // Liberando a memória alocada
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
