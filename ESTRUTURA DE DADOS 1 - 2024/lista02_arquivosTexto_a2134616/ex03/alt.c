#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copy_string(const char* str) {
    // Verifica se a string original é nula
    if (str == NULL) {
        return NULL;
    }

    // Aloca memória para a cópia da string (incluindo o caractere nulo)
    char* copy = (char*)malloc((strlen(str) + 1) * sizeof(char));
    if (copy == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    // Copia a string para a nova alocação
    strcpy(copy, str);
    return copy;
}

int main() {
    const char* original = "Hello, World!";
    char* copied = copy_string(original); // copia a string

    if (copied != NULL) {
        printf("Original: %s\n", original);
        printf("Cópia: %s\n", copied);
        free(copied); // libera a memória alocada
    }

    return 0;
}
