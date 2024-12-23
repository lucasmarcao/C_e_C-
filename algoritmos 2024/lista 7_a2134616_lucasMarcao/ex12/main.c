#include <stdio.h>
#include <string.h>

void cut_string(char str[], const char word[])
{
    // Encontra a posição da palavra na string
    char *pos = strstr(str, word);

    // Se a palavra foi encontrada
    if (pos != NULL)
    {
        // Preenche os caracteres após a palavra com o caractere nulo ('\0')
        pos[strlen(word)] = '\0';
    }
}

int main()
{
    char s[] = "first things first, second things latter";
    cut_string(s, "second");
    printf("%s\n", s); // Saída: "first things first, second"
    return 0;
}
