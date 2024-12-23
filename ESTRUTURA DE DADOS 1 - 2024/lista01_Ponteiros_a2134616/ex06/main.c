#include <stdio.h>
#include <stdlib.h>

int* array_union(int n1, const int* v1, int n2, const int* v2) {
    // Aloca memória para o vetor de união
    int* union_array = (int*)malloc((n1 + n2) * sizeof(int));
    if (union_array == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    int index = 0;

    // Adiciona elementos do primeiro vetor
    for (int i = 0; i < n1; i++) {
        union_array[index++] = v1[i];
    }

    // Adiciona elementos do segundo vetor, evitando duplicatas
    for (int j = 0; j < n2; j++) {
        int found = 0;
        for (int i = 0; i < n1; i++) {
            if (v2[j] == v1[i]) {
                found = 1; // Elemento já existe em v1
                break;
            }
        }
        if (!found) {
            union_array[index++] = v2[j];
        }
    }

    // Redimensiona a memória para o tamanho real da união
    union_array = (int*)realloc(union_array, index * sizeof(int));

    return union_array;
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

    int* result = array_union(4, v1, 4, v2); // realiza a união

    if (result != NULL) {
        print_array(6, result); // imprime a união (espera-se 1, 2, 3, 4, 5, 6)
        free(result); // libera a memória alocada
    }

    return 0;
}
