#include <stdio.h>
#include <string.h>

// Definição da estrutura de contato
struct contact
{
    int id;
    char name[51];
    char email[51];
    int type;
};

typedef struct contact Contact;

// Função para contar a quantidade de contatos que possuem ao menos um dos nomes procurados
int find_by_name(int n1, Contact list[n1], int n2, char names[n2][50])
{
    int count = 0;

    for (int i = 0; i < n1; i++)
    { // Iterar sobre os contatos
        for (int j = 0; j < n2; j++)
        { // Iterar sobre os nomes procurados
            if (strstr(list[i].name, names[j]) != NULL)
            {            // Verificar se o nome procurado está presente no nome do contato
                count++; // Incrementar o contador
                break;   // Parar de procurar se o nome for encontrado
            }
        }
    }

    return count; // Retornar a quantidade de contatos encontrados
}

int main()
{
    // Exemplo de uso da função
    Contact list[30] = {
        {1, "John Doe", "john.doe@example.com", 0},
        {2, "Jane Smith", "jane.smith@example.com", 1},
        {3, "Mike Johnson", "mike.johnson@example.com", 2},
        {4, "Alice Brown", "alice.brown@example.com", 3},
        {5, "Robert Lee", "robert.lee@example.com", 4},
        // Mais contatos podem ser adicionados aqui, se necessário
    };

    char names[5][10] = {"joanna", "john", "mike", "leonor", "caroline"};
    // A chamada abaixo contará os nomes em “list” que contêm ao menos uma das palavras em “names”.
    int count = find_by_name(30, list, 5, names);

    printf("Quantidade de contatos encontrados: %d\n", count);

    return 0;
}
