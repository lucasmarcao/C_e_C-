#include <stdio.h>

int string_compare(const char str1[], const char str2[])
{
    int i = 0;

    // Percorre as duas strings ao mesmo tempo
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        // Se os caracteres forem diferentes
        if (str1[i] != str2[i])
        {
            // Retorna -1 se o caractere em str1 for menor que o de str2
            if (str1[i] < str2[i])
            {
                return -1;
            }
            // Retorna 1 se o caractere em str1 for maior que o de str2
            else
            {
                return 1;
            }
        }
        i++;
    }

    // Verifica se as strings são de tamanhos diferentes
    if (str1[i] == '\0' && str2[i] != '\0')
    {
        return -1; // str1 é menor
    }
    else if (str1[i] != '\0' && str2[i] == '\0')
    {
        return 1; // str1 é maior
    }
    else
    {
        return 0; // as strings são iguais
    }
}

int main()
{
    const char str1[] = "hello";
    const char str2[] = "Hello";
    int res = string_compare(str1, str2);
    printf("%d\n", res); // Saída: -1
    return 0;
}
