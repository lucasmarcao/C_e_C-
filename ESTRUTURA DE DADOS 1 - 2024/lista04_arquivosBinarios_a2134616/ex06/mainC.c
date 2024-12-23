/*
Resumo da resolução:
A tarefa é escrever uma função find_movie que encontre
a posição (índice) de um registro de filme no arquivo
binário, com base no seu ID. Em vez de carregar
todos os registros na memória, a função deve acessar
o arquivo diretamente e verificar cada registro.
Para isso, a função abrirá o arquivo em modo binário
de leitura, lerá cada registro de Movie em sequência
usando fread e comparará o campo id de cada registro
com o ID fornecido. Se o ID for encontrado, a função
retornará a posição do registro. Caso contrário,
retornará -1 indicando que o filme não existe no arquivo.
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

// Função para encontrar a posição de um filme no arquivo baseado no seu ID
long find_movie(const char *filepath, long id)
{
    // Abre o arquivo em modo binário para leitura ("rb")
    FILE *file = fopen(filepath, "rb");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return -1; // Retorna -1 caso o arquivo não possa ser aberto
    }

    Movie movie;
    long pos = 0; // Variável para armazenar a posição do filme no arquivo

    // Lê o arquivo registro por registro, comparando o ID de cada filme
    while (fread(&movie, sizeof(Movie), 1, file) == 1)
    {
        if (movie.id == id)
        {
            fclose(file);
            return pos; // Retorna a posição do filme caso o ID seja encontrado
        }
        pos++; // Incrementa a posição para o próximo registro
    }

    // Se o ID não for encontrado no arquivo, retorna -1
    fclose(file);
    return -1;
}

int main()
{
    // Chama a função para encontrar a posição do filme com ID 23 no arquivo "movies.bin"
    long pos = find_movie("movies.bin", 11);

    // Exibe o resultado
    if (pos != -1)
    {
        printf("Filme encontrado na posição: %ld\n", pos);
    }
    else
    {
        printf("Filme com o ID fornecido não encontrado.\n");
    }

    return 0;
}
