#include <stdio.h>
#include <stdlib.h>

int** transpose(int m, int n, int v[m][n]) {
    // Aloca memória para a matriz transposta
    int** transposed = (int**)malloc(n * sizeof(int*));
    if (transposed == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a matriz transposta.\n");
        return NULL;
    }

    // Aloca memória para cada linha da matriz transposta
    for (int i = 0; i < n; i++) {
        transposed[i] = (int*)malloc(m * sizeof(int));
        if (transposed[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para uma linha da matriz transposta.\n");
            // Libera a memória já alocada antes de retornar
            for (int j = 0; j < i; j++) {
                free(transposed[j]);
            }
            free(transposed);
            return NULL;
        }
    }

    // Preenche a matriz transposta
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = v[i][j];
        }
    }

    return transposed;
}

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

void free_vector2D(int m, int** matrix) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int m = 3; // número de linhas
    int n = 4; // número de colunas
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Transpondo a matriz
    int** transposed = transpose(m, n, matrix);
    if (transposed != NULL) {
        // Imprime a matriz transposta
        printf("Matriz transposta:\n");
        print_vector2D(n, m, (const int**)transposed);
        // Libera a memória alocada
        free_vector2D(n, transposed);
    }

    return 0;
}
