#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct contact
{
    int id;
    char name[51];
    char email[51];
    int type;
};

typedef struct contact Contact;

void fix_name(char *name)
{
    int i, j;

    // Remover espaços extras no início
    while (*name && *name == ' ')
    {
        name++;
    }

    // Corrigir nome
    for (i = 0, j = 0; name[i]; i++)
    {
        if (isalpha(name[i]))
        {
            // Transformar primeira letra de cada palavra em maiúscula
            if (j == 0 || (name[i - 1] == ' ' && name[i] != ' '))
            {
                name[j++] = toupper(name[i]);
            }
            else
            {
                name[j++] = tolower(name[i]);
            }
        }
        else if (name[i] == ' ')
        {
            // Substituir espaços por um único espaço
            if (name[i - 1] != ' ')
            {
                name[j++] = ' ';
            }
        }
    }

    // Remover espaços extras no final
    if (j > 0 && name[j - 1] == ' ')
    {
        j--;
    }

    // Adicionar terminador de string
    name[j] = '\0';
}

Contact create_contact(int id, char name[], int type)
{
    fix_name(name);

    // Criar e-mail
    char email[51];
    snprintf(email, sizeof(email), "%s@mail.br", name);

    Contact new_contact;
    new_contact.id = id;
    strncpy(new_contact.name, name, sizeof(new_contact.name) - 1);
    strncpy(new_contact.email, email, sizeof(new_contact.email) - 1);
    new_contact.type = type;

    // Adicionar terminador de string aos arrays name e email, caso necessário
    new_contact.name[sizeof(new_contact.name) - 1] = '\0';
    new_contact.email[sizeof(new_contact.email) - 1] = '\0';

    return new_contact;
}

int main()
{
    Contact c = create_contact(4, " JoHn! Do5e3 SILVA", 1);
    printf("{%d, \"%s\", \"%s\", %d}\n", c.id, c.name, c.email, c.type);
    return 0;
}
