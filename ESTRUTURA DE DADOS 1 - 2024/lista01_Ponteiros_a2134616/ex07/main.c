#include <stdio.h>
#include <stdlib.h>

int* array_intersection(int n1, const int* v1, int n2, const int* v2, int* result_size) {
    // Aloca memória para o vetor de interseção (o tamanho máximo pode ser o menor vetor)
    int* intersection_array = (int*)malloc((n1 < n2 ? n1 : n2) * sizeof(int));
    if (intersection_array == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    int index = 0;

    // Encontra a interseção
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (v1[i] == v2[j]) {
                intersection_array[index++] = v1[i];
                break; // Para evitar duplicatas na interseção
            }
        }
    }

    // Redimensiona o vetor para o tamanho real da interseção
    intersection_array = (int*)realloc(intersection_array, index * sizeof(int));
    
    // Define o tamanho do resultado
    *result_size = index;

    return intersection_array;
}

void print_array(int n, const int* array) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int v1[] = {1, 2, 3, 4};
    int v2[] = {3, 4, 5, 6};
    int result_size;

    int* result = array_intersection(4, v1, 4, v2, &result_size); // realiza a interseção

    if (result != NULL) {
        printf("Interseção: ");
        print_array(result_size, result); // imprime a interseção (espera-se 3, 4)
        free(result); // libera a memória alocada
    }

    return 0;
}
