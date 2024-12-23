/*
Resumo da resolução:
A função insert_sorted deve inserir um novo registro de filme de
forma ordenada no arquivo, mantendo os registros ordenados por
Movie::id. Para isso, a função deve percorrer o arquivo de filmes,
lendo os registros um por um e, quando encontrar o lugar adequado
para o novo registro (baseado no ID), deslocar os registros
subsequentes para abrir espaço para o novo. Isso pode ser feito
reescrevendo o arquivo na posição correta, uma vez que não podemos
carregar todos os registros na memória. A operação deve retornar
1 para sucesso e 0 caso ocorra um erro
(como problemas no arquivo ou na inserção).

Implementação da função insert_sorted:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tipo Movie
typedef struct
{
    long id;       // ID do filme
    char name[51]; // Nome do filme (máximo 50 caracteres)
} Movie;

// Função para inserir um filme de forma ordenada em um arquivo
int insert_sorted(const char *filepath, Movie movie)
{
    // Abre o arquivo em modo binário de leitura e escrita ("r+b")
    FILE *file = fopen(filepath, "r+b");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0; // Retorna 0 se o arquivo não pôde ser aberto
    }

    // Cria uma variável para armazenar o filme atual do arquivo
    Movie current_movie;

    // Variável para marcar onde devemos inserir o novo filme
    long pos_to_insert = -1;

    // Loop para percorrer o arquivo e encontrar a posição correta
    while (fread(&current_movie, sizeof(Movie), 1, file) == 1)
    {
        // Se o ID do filme atual for maior que o ID do filme a ser inserido,
        // a inserção deve ocorrer antes deste filme
        if (current_movie.id > movie.id)
        {
            pos_to_insert = ftell(file) - sizeof(Movie); // Posição de inserção
            break;                                       // Encontra a posição correta para a inserção
        }
    }

    // Se não encontrou posição de inserção, coloca o novo filme no final
    if (pos_to_insert == -1)
    {
        fseek(file, 0, SEEK_END);    // Vai para o final do arquivo
        pos_to_insert = ftell(file); // Posição do final
    }

    // Cria um arquivo temporário para armazenar os dados com o novo filme inserido
    FILE *temp_file = fopen("temp.bin", "wb");
    if (temp_file == NULL)
    {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(file);
        return 0; // Retorna 0 se não puder criar o arquivo temporário
    }

    // Copia os registros anteriores para o arquivo temporário
    fseek(file, 0, SEEK_SET);
    while (fread(&current_movie, sizeof(Movie), 1, file) == 1)
    {
        if (ftell(file) > pos_to_insert)
        {
            fwrite(&current_movie, sizeof(Movie), 1, temp_file);
        }
        else
        {
            break;
        }
    }

    // Escreve o novo filme no arquivo temporário
    fwrite(&movie, sizeof(Movie), 1, temp_file);

    // Copia os registros restantes para o arquivo temporário
    fseek(file, pos_to_insert, SEEK_SET);
    while (fread(&current_movie, sizeof(Movie), 1, file) == 1)
    {
        fwrite(&current_movie, sizeof(Movie), 1, temp_file);
    }

    // Fecha os arquivos
    fclose(file);
    fclose(temp_file);

    // Remove o arquivo original e renomeia o arquivo temporário para o nome original
    remove(filepath);
    rename("temp.bin", filepath);

    return 1; // Retorna 1 indicando sucesso
}

int main()
{
    // Exemplo de um filme a ser inserido
    Movie new_movie = {5, "Inception"};

    // Chama a função para inserir o filme ordenado no arquivo "movies.bin"
    int result = insert_sorted("movies.bin", new_movie);

    // Verifica o resultado da inserção
    if (result == 1)
    {
        printf("\nFilme inserido com sucesso!\n");
    }
    else
    {
        printf("\nFalha na inserção do filme.\n");
    }

    return 0;
}
