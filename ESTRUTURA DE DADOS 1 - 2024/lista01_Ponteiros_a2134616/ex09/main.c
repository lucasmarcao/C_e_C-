#include <stdio.h>
#include <stdlib.h>

int** create_vector2D(int m, int n) {
    // Aloca memória para as linhas da matriz
    int** matrix = (int**)malloc(m * sizeof(int*));
    if (matrix == NULL) {
        fprintf(stderr, "Erro ao alocar memória para as linhas da matriz.\n");
        return NULL;
    }

    // Aloca memória para cada coluna da matriz
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para as colunas da matriz.\n");
            // Libera a memória já alocada antes de retornar
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    // Preenche a matriz com uma sequência crescente de inteiros
    int value = 1; // Começando de 1
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = value++;
        }
    }

    return matrix;
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

    // Cria a matriz 2D
    int** matrix = create_vector2D(m, n);
    if (matrix != NULL) {
        // Imprime a matriz
        printf("Conteúdo da matriz:\n");
        print_vector2D(m, n, (const int**)matrix);
        // Libera a memória alocada
        free_vector2D(m, matrix);
    }

    return 0;
}
