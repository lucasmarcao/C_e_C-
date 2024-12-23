/*
Resumo da resolução:
A função delete_movie precisa marcar um registro como removido no
arquivo binário de filmes, sem apagar os dados do registro, apenas
alterando o campo id para -1. Para isso, a função deve abrir o
arquivo no modo binário de leitura e escrita ("r+b"), acessar o
arquivo registro por registro e, quando encontrar o filme com o
ID correspondente, substituir o valor de id por -1. Isso marca o
filme como removido sem excluir fisicamente o registro. Se a operação
for bem-sucedida, a função retorna 1; caso contrário, retorna 0.
A função deve acessar o arquivo diretamente, sem carregar
todos os registros na memória.
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

// Função para remover (marcar como removido) o filme no arquivo com base no ID
int delete_movie(const char *filepath, long id)
{
    // Abre o arquivo em modo binário de leitura e escrita ("r+b")
    FILE *file = fopen(filepath, "r+b");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para remoção.\n");
        return 0; // Retorna 0 (falso) caso o arquivo não possa ser aberto
    }

    Movie current_movie;
    int found = 0; // Variável para verificar se o filme foi encontrado

    // Percorre o arquivo registro por registro
    while (fread(&current_movie, sizeof(Movie), 1, file) == 1)
    {
        // Se o ID do filme atual for igual ao ID fornecido, marcamos como removido
        if (current_movie.id == id)
        {
            // Move o ponteiro de arquivo para a posição do registro encontrado
            fseek(file, -sizeof(Movie), SEEK_CUR);
            // Marca o filme como removido, alterando seu ID para -1
            current_movie.id = -1;
            // Reescreve o registro com o ID modificado
            fwrite(&current_movie, sizeof(Movie), 1, file);
            found = 1; // Marca que o filme foi encontrado e "removido"
            break;     // Sai do loop após a atualização
        }
    }

    // Fecha o arquivo após a operação
    fclose(file);

    // Se o filme foi encontrado e "removido", retorna 1, caso contrário retorna 0
    return found ? 1 : 0;
}

int main()
{
    // ID do filme a ser "removido"
    long movie_id_to_delete = 8;

    // Chama a função para remover o filme do arquivo "movies.bin"
    int result = delete_movie("movies.bin", movie_id_to_delete);

    // Verifica o resultado da operação
    if (result == 1)
    {
        printf("\nFilme removido com sucesso!\n");
    }
    else
    {
        printf("\nFalha ao remover o filme. ID não encontrado.\n");
    }

    return 0;
}
