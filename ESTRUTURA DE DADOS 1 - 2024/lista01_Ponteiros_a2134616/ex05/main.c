#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat_string(const char* str1, const char* str2) {
    // Verifica se ambas as strings são nulas
    if (str1 == NULL && str2 == NULL) {
        return NULL;
    }

    // Se apenas uma das strings for nula, usa a outra
    if (str1 == NULL) {
        return strdup(str2); // Cria uma cópia da segunda string
    }
    if (str2 == NULL) {
        return strdup(str1); // Cria uma cópia da primeira string
    }

    // Calcula o comprimento total para a nova string
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    // Aloca memória para a string concatenada (incluindo o caractere nulo)
    char* concatenated = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (concatenated == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    // Copia a primeira string
    strcpy(concatenated, str1);
    // Concatena a segunda string
    strcat(concatenated, str2);

    return concatenated;
}

int main() {
    const char* string1 = "Hello, ";
    const char* string2 = "World!";
    
    char* result = concat_string(string1, string2); // concatena as strings

    if (result != NULL) {
        printf("Resultado: %s\n", result);
        free(result); // libera a memória alocada
    }

    return 0;
}
