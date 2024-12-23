#include <stdio.h>

struct contact
{
    int id;
    char name[51];
    char email[51];
    int type;
};

typedef struct contact Contact;

/*
 * Função para imprimir os contatos agrupados por tipo.
 * Entrada de Dados:
 *  - n1: número de contatos
 *  - list: vetor de contatos
 *  - n2: número de tipos de contatos
 *  - types: vetor de descrições de tipos de contatos
 */
void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50])
{
    // Processamento de Dados:
    // Organizando os contatos por tipo usando um vetor de vetores de inteiros
    int indices[n2][n1];
    int count[n2];

    for (int i = 0; i < n2; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n1; i++)
    {
        int type_index = list[i].type;
        if (type_index < n2)
        {
            indices[type_index][count[type_index]++] = i;
        }
    }

    // Saída de Dados:
    // Imprimir contatos agrupados por tipo
    for (int i = 0; i < n2; i++)
    {
        if (count[i] > 0)
        { // Há contatos desse tipo
            printf("\n%s:\n", types[i]);
            for (int j = 0; j < count[i]; j++)
            {
                int contact_index = indices[i][j];
                printf("    - %s\n", list[contact_index].name);
            }
        }
    }
}

int main()
{
    char types[][50] = {"Família", "Amigo", "Trabalho", "Escola", "Outros"};
    Contact list[] = {
        {1, "Marcus Fenix", "fenix@gow.com", 2},
        {41, "Blue Mary", "mary@ff3snk.net", 0},
        {17, "Barry Burton", "bburton@re.cap", 0},
        {8, "Charlie Nash", "nash@ssz.com", 3},
        {2, "Ada Wong", "wong@re2.net", 4},
        {5, "Chris Redfield", "crfield@re.cap", 0}};
    print_contact_list(6, list, 5, types);
    return 0;
}
