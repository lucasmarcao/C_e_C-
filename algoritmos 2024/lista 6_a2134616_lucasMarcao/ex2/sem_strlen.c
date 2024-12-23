#include <stdio.h>

void print_string_reversed(char str[])
{
    int length = 0;
    // Encontrando o comprimento da string manualmente
    while (str[length] != '\0')
    {
        length++;
    }
    for (int i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main()
{
    char minha_string[] = "Exemplo";
    print_string_reversed(minha_string);
    return 0;
}
