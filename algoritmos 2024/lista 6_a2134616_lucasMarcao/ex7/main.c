#include <stdio.h>
#include <ctype.h>

void string_capitalize(char str[])
{
    int i = 0;
    // Definindo uma flag para indicar se a próxima letra deve ser maiúscula
    int capitalize_next = 1;

    while (str[i] != '\0')
    {
        // Se for um espaço, a próxima letra deve ser maiúscula
        if (isspace(str[i]))
        {
            capitalize_next = 1;
        }
        // Se for uma letra
        else if (isalpha(str[i]))
        {
            // Se a próxima letra deve ser maiúscula, converte para maiúscula
            if (capitalize_next)
            {
                str[i] = toupper(str[i]);
                capitalize_next = 0;
            }
            // Caso contrário, converte para minúscula
            else
            {
                str[i] = tolower(str[i]);
            }
        }
        i++;
    }
}

int main()
{
    char s[] = "welCOME To COMPUTER programming!!";
    string_capitalize(s);
    printf("%s", s); // Saída: Welcome To Computer Programming!!
    return 0;
}
