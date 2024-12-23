#include <stdio.h>
#include <stdbool.h>

int find_substring(const char str[], const char sub[])
{
    int i, j;

    // Percorre a string principal
    for (i = 0; str[i] != '\0'; i++)
    {
        // Verifica se a subsequência a partir da posição atual coincide com a string procurada
        for (j = 0; sub[j] != '\0' && str[i + j] == sub[j]; j++)
        {
        }

        // Se a string procurada foi encontrada
        if (sub[j] == '\0')
        {
            return 1; // Retorna verdadeiro (1)
        }
    }

    return 0; // Retorna falso (0) se a string procurada não foi encontrada
}

int main()
{
    char s[] = "first things first, second things latter";
    int check = find_substring(s, "second");
    printf("%d\n", check); // Saída: 1 (true), pois a string contém a palavra "second"
    return 0;
}
