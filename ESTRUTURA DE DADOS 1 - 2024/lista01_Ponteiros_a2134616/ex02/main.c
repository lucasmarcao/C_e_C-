#include <stdio.h>
#include <stdlib.h>

int* get_largest(int n, int* v, int max) {
    // Aloca memória para o vetor de resultados
    int* largest = (int*)malloc(max * sizeof(int));
    if (largest == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    // Ordena o vetor original em ordem decrescente
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] < v[j + 1]) {
                // Troca v[j] e v[j + 1]
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    // Copia os max maiores elementos para o vetor de resultados
    for (int i = 0; i < max && i < n; i++) {
        largest[i] = v[i];
    }

    return largest;
}

void print_vector(int n, int* vector) {
    for (int i = 0; i < n; i++) {
        printf("%d", vector[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    int v0[] = {6, 10, 2, 1, 2, 3, 9};
    int* v1 = get_largest(7, v0, 2); // retorna vetor com os 2 maiores valores de v0
    if (v1 != NULL) {
        print_vector(2, v1); // imprime 10,9
        free(v1); // libera array alocado na heap
    }
    return 0;
}
