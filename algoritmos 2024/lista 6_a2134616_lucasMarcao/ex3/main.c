#include <stdio.h>

void string_report(char str[])
{
    int letras = 0, digitos = 0, simbolos = 0;

    // Percorrendo a string
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Verificando se o caractere está dentro do intervalo imprimível da tabela ASCII
        if (str[i] >= 32 && str[i] <= 126)
        {
            // Verificando se é uma letra (maiúscula ou minúscula)
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                letras++;
            }
            // Verificando se é um dígito
            else if (str[i] >= '0' && str[i] <= '9')
            {
                digitos++;
            }
            // Se não é letra nem dígito, é um símbolo
            else
            {
                simbolos++;
            }
        }
    }

    // Imprimindo os resultados
    printf("Quantidade de letras: %d\n", letras);
    printf("Quantidade de digitos: %d\n", digitos);
    printf("Quantidade de simbolos: %d\n", simbolos);
}

int main()
{
    char minha_string[] = "Hello123!@# World";
    string_report(minha_string);
    return 0;
}
