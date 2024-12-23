#include <stdio.h>
#include <string.h>

void string_trim(char str[])
{
    int len = strlen(str);
    int start = 0;     // Índice onde os espaços em branco terminam no início da string
    int end = len - 1; // Índice onde os espaços em branco começam no final da string

    // Encontra o índice onde os espaços em branco terminam no início da string
    while (str[start] == ' ')
    {
        start++;
    }

    // Encontra o índice onde os espaços em branco começam no final da string
    while (end >= 0 && str[end] == ' ')
    {
        end--;
    }

    // Move os caracteres para a esquerda para eliminar os espaços em branco adicionais
    for (int i = start; i <= end; i++)
    {
        str[i - start] = str[i];
    }

    // Adiciona o caractere nulo no final da string
    str[end - start + 1] = '\0';
}

int main()
{
    char s[] = " hello world ";
    string_trim(s);
    printf("%s", s); // Saída: "hello world"
    return 0;
}
