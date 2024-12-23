/*
Resumo da resolução:
Neste exercício, a função add_movie precisa adicionar um
novo registro ao final de um arquivo binário de filmes.
Para isso, ela deve abrir o arquivo no modo de anexação
binária ("ab") para garantir que o novo registro seja
escrito no final do arquivo. Após abrir o arquivo corretamente,
a função escreverá o registro de filme fornecido com fwrite
e, se a operação for bem-sucedida, retornará 1 (verdadeiro).
Caso contrário, retornará 0 (falso) indicando erro.
A função não deve carregar todos os registros
para a memória, somente adicionar o novo registro
diretamente ao arquivo.
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

// Função para adicionar um novo filme ao final do arquivo
int add_movie(const char *filepath, Movie movie)
{
    // Abre o arquivo em modo binário de anexação ("ab"), para adicionar no final
    FILE *file = fopen(filepath, "ab");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para adição.\n");
        return 0; // Retorna 0 (falso) caso o arquivo não possa ser aberto
    }

    // Escreve o novo registro de filme no arquivo
    size_t elements_written = fwrite(&movie, sizeof(Movie), 1, file);

    // Verifica se a escrita foi bem-sucedida
    if (elements_written != 1)
    {
        printf("Erro ao escrever o filme no arquivo.\n");
        fclose(file);
        return 0; // Retorna 0 (falso) caso a escrita falhe
    }

    // Fecha o arquivo após a escrita
    fclose(file);

    return 1; // Retorna 1 (verdadeiro) se o filme foi adicionado com sucesso
}

int main()
{
    // Exemplo de filme para adicionar
    Movie new_movie = {993, "O Grande CHAD"};

    // Chama a função para adicionar o filme no arquivo "movies.bin"
    int result = add_movie("movies.bin", new_movie);

    // Verifica o resultado da operação
    if (result == 1)
    {
        printf("\nFilme adicionado com sucesso!\n");
    }
    else
    {
        printf("\nFalha ao adicionar o filme.\n");
    }

    return 0;
}
