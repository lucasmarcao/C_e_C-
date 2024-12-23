#include <stdio.h>
#include <ctype.h>

void string_count(const char str[])
{
    int occurrences[26] = {0}; // Array para contar as ocorrências de cada letra
    int total_letters = 0;     // Total de letras na string

    // Contagem das ocorrências de cada letra
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {                                      // Verifica se o caractere é uma letra
            total_letters++;                   // Incrementa o total de letras
            int index = tolower(str[i]) - 'a'; // Obtém o índice da letra no array (0-25)
            occurrences[index]++;              // Incrementa a contagem de ocorrências da letra
        }
    }

    // Imprimindo as ocorrências de cada letra e seu percentual
    for (int i = 0; i < 26; i++)
    {
        if (occurrences[i] > 0)
        {
            char letter = 'a' + i;                                          // Obtém a letra correspondente ao índice
            float percentage = (float)occurrences[i] / total_letters * 100; // Calcula o percentual
            printf("%c x%d (%.0f%%)\n", letter, occurrences[i], percentage);
        }
    }
}

int main()
{
    char s[] = "Hello World of Software Development";
    string_count(s);
    return 0;
}
