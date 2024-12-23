#include <stdio.h>
#include <ctype.h>

int main()
{
    char caractere;

    // Solicita ao usuário que insira um caractere
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    // Verifica se o caractere é uma letra
    if (isalpha(caractere))
    {
        // Verifica se o caractere é uma vogal
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' ||
            caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U')
        {
            printf("O caractere '%c' é uma vogal.\n", caractere);
        }
        else
        {
            printf("O caractere '%c' é uma consoante.\n", caractere);
        }
    }
    else if (isdigit(caractere))
    { // Verifica se o caractere é um número
        printf("O caractere '%c' é um número.\n", caractere);
    }
    else if ((caractere >= 33 && caractere <= 47) || (caractere >= 58 && caractere <= 64) ||
             (caractere >= 91 && caractere <= 96) || (caractere >= 123 && caractere <= 126))
    { // Verifica se o caractere é um símbolo
        printf("O caractere '%c' é um símbolo.\n", caractere);
    }
    else
    {
        printf("O caractere '%c' não é uma letra, número ou símbolo ASCII.\n", caractere);
    }

    return 0;
}
