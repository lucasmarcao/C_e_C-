#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** split(const char* str, int* n) {
    // Contar o número de palavras
    int count = 0;
    const char* p = str;

    while (*p) {
        // Ignora espaços em branco
        while (*p && isspace((unsigned char)*p)) {
            p++;
        }
        if (*p) {
            count++;
            // Move para o próximo espaço ou fim da string
            while (*p && !isspace((unsigned char)*p)) {
                p++;
            }
        }
    }

    // Aloca memória para o vetor de strings
    char** tokens = (char**)malloc(count * sizeof(char*));
    if (tokens == NULL) {
        fprintf(stderr, "Erro ao alocar memória para tokens.\n");
        return NULL;
    }

    // Preencher o vetor de strings
    int index = 0;
    p = str;
    while (*p) {
        // Ignora espaços em branco
        while (*p && isspace((unsigned char)*p)) {
            p++;
        }
        if (*p) {
            const char* start = p;
            // Move até o próximo espaço ou fim da string
            while (*p && !isspace((unsigned char)*p)) {
                p++;
            }
            // Aloca e copia a palavra
            size_t length = p - start;
            tokens[index] = (char*)malloc((length + 1) * sizeof(char));
            if (tokens[index] == NULL) {
                fprintf(stderr, "Erro ao alocar memória para uma palavra.\n");
                // Libera a memória já alocada antes de retornar
                for (int j = 0; j < index; j++) {
                    free(tokens[j]);
                }
                free(tokens);
                return NULL;
            }
            strncpy(tokens[index], start, length);
            tokens[index][length] = '\0'; // Termina a string
            index++;
        }
    }

    *n = count; // Define o número de palavras encontradas
    return tokens;
}

int main() {
    char str[] = " Texto de teste com várias palavras ";
    int size = 0;

    char** tokens = split(str, &size); // devolve vetor de strings com as palavras
    if (tokens != NULL) {
        for (int i = 0; i < size; i++) {
            printf("%s\n", tokens[i]); // imprime as palavras encontradas
            free(tokens[i]); // libera cada string
        }
        free(tokens); // libera vetor de strings alocado na heap
    }

    return 0;
}
