/*
Resumo da resolução:
Para resolver esse exercício, o objetivo é escrever uma função
que conte o número de registros de filmes armazenados em um
arquivo binário. A função precisa abrir o arquivo no modo
binário de leitura ("rb") e determinar quantos registros
(estruturas Movie) existem no arquivo. A abordagem será
determinar o tamanho do arquivo com fseek e ftell, e
depois calcular o número de registros dividindo o tamanho
total do arquivo pelo tamanho de um registro de filme
(sizeof(Movie)). Se o arquivo não puder ser aberto,
a função retornará -1 como um código de erro.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição do tipo Movie
typedef struct
{
    long id;       // ID do filme
    char name[51]; // Nome do filme (máximo 50 caracteres)
} Movie;

// Função para contar o número de registros de filmes em um arquivo
int count_movies(const char *filepath)
{
    // Abre o arquivo em modo binário para leitura ("rb")
    FILE *file = fopen(filepath, "rb");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return -1; // Retorna -1 se o arquivo não puder ser aberto
    }

    // Move o ponteiro do arquivo para o final para determinar o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file); // Obtém o tamanho do arquivo em bytes
    fseek(file, 0, SEEK_SET);     // Reseta o ponteiro do arquivo para o início

    // Calcula o número de registros de filmes, dividindo o tamanho total pelo tamanho de um Movie
    int num_movies = file_size / sizeof(Movie);

    // Fecha o arquivo após a verificação
    fclose(file);

    return num_movies; // Retorna a quantidade de registros de filmes no arquivo
}

int main()
{
    // Chama a função para contar os filmes no arquivo "movies.bin"
    int size = count_movies("movies.bin");

    // Imprime a quantidade de filmes, caso o arquivo tenha sido aberto e lido corretamente
    if (size != -1)
    {
        printf("O arquivo contém %d filmes.\n", size);
    }
    else
    {
        printf("Erro ao contar os filmes.\n");
    }

    return 0;
}
