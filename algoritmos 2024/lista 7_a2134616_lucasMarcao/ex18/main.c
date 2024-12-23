#include <stdio.h>
#include <string.h>

void print_strings_minmax(int n, int len, char list[n][len])
{
    if (n <= 0)
    {
        printf("A lista está vazia.\n");
        return;
    }

    // Inicializa as variáveis para armazenar a palavra de menor e maior tamanho
    char smallest[len];
    char largest[len];

    // Inicializa os tamanhos com um valor grande e pequeno, respectivamente
    int smallest_length = len;
    int largest_length = 0;

    // Percorre o array de strings para encontrar a palavra de menor e maior tamanho
    for (int i = 0; i < n; i++)
    {
        int length = strlen(list[i]);

        if (length < smallest_length)
        {
            smallest_length = length;
            strcpy(smallest, list[i]);
        }

        if (length > largest_length)
        {
            largest_length = length;
            strcpy(largest, list[i]);
        }
    }

    // Imprime as palavras de menor e maior tamanho
    printf("Menor: ");
    for (int i = 0; i < n; i++)
    {
        if (strlen(list[i]) == smallest_length)
        {
            printf("%s, ", list[i]);
        }
    }
    printf("\n");

    printf("Maior: ");
    for (int i = 0; i < n; i++)
    {
        if ((strlen(list[i])) == largest_length)
        {
            printf("%s, ", list[i]);
        }
    }
    printf("\n");
}

int main()
{
    char v[6][20] = {"Joh", "Mariane", "Jak", "Samuel", "Ada", "Michelangelo"};
    print_strings_minmax(6, 20, v);

    return 0;
}