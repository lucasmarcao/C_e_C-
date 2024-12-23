#include <stdio.h>
#include <string.h>

// Função para inverter uma string que pode conter caracteres multibyte
void soletra_palavra(char palavra[])
{
    int len = strlen(palavra);
    printf("\n");

    // Itera sobre a string de trás para frente
    for (int i = len - 1; i >= 0; i--)
    {
        // Verifica se o caractere é parte de um caractere multibyte
        if ((palavra[i] & 0x80) == 0)
        {
            // Caractere ASCII (1 byte)
            printf("%c", palavra[i]);
        }
        else
        {
            // Caractere multibyte, pode ter 2, 3 ou 4 bytes
            int start = i;
            // Avança o ponteiro até o início do caractere multibyte
            while (start > 0 && (palavra[start] & 0xC0) == 0x80)
            {
                start--;
            }
            // Imprime o caractere multibyte
            for (int j = start; j <= i; j++)
            {
                printf("%c", palavra[j]);
            }
            // Ajusta o índice
            i = start;
        }
    }
    printf("\n");
}

int main()
{
    char palavra[50];

    printf("\n Digite uma única palavra: ");
    scanf("%49[^\n]", palavra); // Limita a leitura a 49 caracteres

    printf("\n %s \n", palavra);
    soletra_palavra(palavra);

    return 0;
}
