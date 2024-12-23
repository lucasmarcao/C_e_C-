#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Função para corrigir um nome.
 * Entrada de Dados:
 *   - name: nome a ser corrigido
 */
void fix_name(char name[])
{
    char temp[100]; // Um buffer temporário para armazenar o nome corrigido
    int i = 0, j = 0;
    int first_letter = 1; // Flag para detectar a primeira letra de uma palavra

    // Ignorar espaços no início
    while (isspace(name[i]))
        i++;

    // Processar o nome caracter por caracter
    while (name[i] != '\0')
    {
        if (isalpha(name[i]))
        { // Se for uma letra
            temp[j++] = first_letter ? toupper(name[i]) : tolower(name[i]);
            first_letter = 0;
        }
        else if (isspace(name[i]))
        { // Se for espaço
            if (isalpha(name[i + 1]))
            { // Próximo caracter é letra
                if (!first_letter)
                {
                    temp[j++] = ' '; // Adicionar espaço antes de uma nova palavra
                }
                first_letter = 1; // Próxima letra deve ser maiúscula
            }
        }
        i++;
    }

    // Remover espaço no final, se houver
    if (j > 0 && temp[j - 1] == ' ')
        j--;

    temp[j] = '\0';     // Terminar a string
    strcpy(name, temp); // Copiar de volta para o nome original
}

int main()
{
    char name[] = "   4 LuCa5s 5 mArc#ao";
    fix_name(name);
    printf("Nome corrigido: \"%s\"\n", name);
    return 0;
}
