#include <stdio.h>

int count_words_plus(const char str[])
{
    int num_words = 0;
    int i = 0;

    // Ignorando espaços em branco no início da string
    while (str[i] == ' ')
    {
        i++;
    }

    // Percorrendo a string
    while (str[i] != '\0')
    {
        // Ignorando espaços em branco entre palavras
        while (str[i] == ' ')
        {
            i++;
        }

        // Verificando se encontramos uma palavra
        if (str[i] != '\0' && str[i] != ' ')
        {
            num_words++;
            // Indo para o próximo espaço em branco ou final da string
            while (str[i] != '\0' && str[i] != ' ')
            {
                i++;
            }
        }
    }

    return num_words;
}

int main()
{
    char s[] = " first things first, second things latter ";
    printf("%d", count_words_plus(s)); // Saída: 6
    return 0;
}
