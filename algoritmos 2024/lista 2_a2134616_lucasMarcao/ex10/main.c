#include <stdio.h>
#include <ctype.h>

int main()
{
    char caractere;

    // Solicita ao usuário que insira um caractere
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    // Verifica se o caractere não é uma letra
    if (!isalpha(caractere))
    {
        printf("O caractere digitado não é uma letra.\n");
    }
    else
    {
        // Verifica se o caractere é minúsculo e o converte para maiúsculo, se necessário
        if (islower(caractere))
        {
            caractere = toupper(caractere);
        }
        printf("O caractere digitado em maiúsculo é: %c\n", caractere);
    }

    return 0;
}
