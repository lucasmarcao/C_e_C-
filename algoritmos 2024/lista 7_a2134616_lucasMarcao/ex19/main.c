#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_words(int n, int len, char lines[n][len])
{
    int count = 0;

    // Percorre cada linha do array de strings
    for (int i = 0; i < n; i++)
    {
        int in_word = 0;    // Flag para indicar se estamos dentro de uma palavra
        int word_count = 0; // Contador de palavras para a linha atual

        // Percorre cada caractere da linha
        for (int j = 0; j < len && lines[i][j] != '\0'; j++)
        {
            // Verifica se o caractere é um espaço em branco
            if (isspace(lines[i][j]))
            {
                in_word = 0; // Se for espaço em branco, indica que não estamos mais dentro de uma palavra
            }
            else
            {
                // Se não for espaço em branco e não estivermos dentro de uma palavra,
                // incrementa o contador de palavras
                if (!in_word)
                {
                    in_word = 1;
                    word_count++;
                }
            }
        }

        count += word_count; // Incrementa o contador total de palavras com o número de palavras na linha atual
    }

    return count;
}

int main()
{
    char v[2][200] = {
        " Computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
        " Programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language."};

    int count = count_words(2, 200, v);
    printf("Número de palavras: %d\n", count);

    return 0;
}