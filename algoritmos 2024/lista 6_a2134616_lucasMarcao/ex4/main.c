#include <stdio.h>

void string_to_upper(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        // Verifica se o caractere é uma letra minúscula
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // Converte para maiúscula subtraindo a diferença entre minúscula e maiúscula
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
}

int main()
{
    char s[] = "All your BASE are Belong to US!";
    string_to_upper(s);
    printf("%s", s); // Saída: ALL YOUR BASE ARE BELONG TO US!
    return 0;
}
