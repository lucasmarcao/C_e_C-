/*
Resumo da resolução:
A tarefa consiste em criar uma função write_all_movies
que grava um vetor de registros do tipo Movie em um
arquivo binário. O arquivo deve ser criado se não existir.
A função recebe o caminho do arquivo (filepath), o número
de elementos do vetor (n), e o próprio vetor de filmes (v).
Para isso, abrimos o arquivo no modo binário de escrita ("wb"),
 verificamos a alocação do arquivo e usamos a função fwrite
  para gravar os dados. Caso o arquivo já exista, ele será
  sobrescrito. Após a gravação, o arquivo é fechado com
  fclose.
*/
#include <stdio.h>
#include <stdlib.h>

// Definição do tipo Movie
typedef struct
{
    long id;       // ID do filme
    char name[51]; // Nome do filme (máximo 50 caracteres)
} Movie;

// Função para gravar o conteúdo de um vetor de filmes em um arquivo
void write_all_movies(const char *filepath, int n, const Movie *v)
{
    // Tenta abrir o arquivo no modo binário para escrita ("wb")
    FILE *file = fopen(filepath, "wb");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return; // Se não for possível abrir ou criar o arquivo, retorna
    }

    // Grava o vetor de filmes no arquivo, um filme de cada vez
    size_t elements_written = fwrite(v, sizeof(Movie), n, file);

    // Verifica se todos os filmes foram gravados corretamente
    if (elements_written != n)
    {
        printf("Erro ao escrever os filmes no arquivo.\n");
    }
    else
    {
        printf("Dados gravados com sucesso no arquivo %s.\n", filepath);
    }

    // Fecha o arquivo após a gravação
    fclose(file);
}

int main()
{
    // Exemplo de vetor de filmes
    Movie list[] = {
        {6, "They Live"},
        {11, "Big Trouble in Little China"},
        {10, "The Thing"},
        {1, "In the Mouth of Madness"},
        {8, "Ghosts of Mars"},
        {23, "Halloween"},
        {7, "Village of the Damned"}};

    // Chama a função para gravar o vetor de filmes no arquivo "movies.bin"
    write_all_movies("movies.bin", 7, list);

    return 0;
}
