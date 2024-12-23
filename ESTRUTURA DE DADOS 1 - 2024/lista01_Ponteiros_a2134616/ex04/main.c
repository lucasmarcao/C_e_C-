#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copy_reverse(const char* str) {
    // Verifica se a string original é nula
    if (str == NULL) {
        return NULL;
    }

    // Calcula o comprimento da string
    size_t len = strlen(str);
    
    // Aloca memória para a cópia reversa da string (incluindo o caractere nulo)
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    if (reversed == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    // Preenche a nova string em ordem reversa
    for (size_t i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0'; // Adiciona o caractere nulo no final

    return reversed;
}

int main() {
    const char* original = "Hello, World!";
    char* reversed = copy_reverse(original); // copia a string reversa

    if (reversed != NULL) {
        printf("Original: %s\n", original);
        printf("Reversa: %s\n", reversed);
        free(reversed); // libera a memória alocada
    }

    return 0;
}
