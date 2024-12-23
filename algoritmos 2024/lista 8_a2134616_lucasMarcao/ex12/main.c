#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Estrutura de Contato
struct contact
{
    int id;
    char name[51];
    char email[51];
    int type; // 0 - Família, 1 - Amigo, 2 - Trabalho, 3 - Escola, 4 - Outros
};

typedef struct contact Contact;

// Função auxiliar para corrigir o nome
void fix_name(char *name)
{
    // Implementação omitida
}

// Função auxiliar para verificar se um nome é "Doe"
int is_doe(const char *name)
{
    // Implementação omitida
}

// Função auxiliar para gerar um tipo aleatório
int random_type(const char *name)
{
    // Implementação omitida
}

// Função para preencher o vetor de contatos
void fill_contact_list(int n, Contact list[])
{
    srand(time(NULL));
    int id_counter = 1; // Inicializar o contador de ID

    for (int i = 0; i < n; i++)
    {
        list[i].id = id_counter++; // Preencher o ID incrementalmente

        // Gerar um nome fictício (exemplo)
        sprintf(list[i].name, "John Doe %d", i + 1);
        fix_name(list[i].name); // Corrigir o nome

        // Gerar um email fictício (exemplo)
        sprintf(list[i].email, "john.doe%d@mail.br", i + 1);

        // Gerar um tipo aleatório, exceto para contatos da família "Doe"
        if (is_doe(list[i].name))
        {
            list[i].type = 1; // Amigo
        }
        else
        {
            list[i].type = random_type(list[i].name);
        }
    }
}

int main()
{
    Contact list[15];
    fill_contact_list(15, list);

    // Não há saída direta nesta função
    return 0;
}
