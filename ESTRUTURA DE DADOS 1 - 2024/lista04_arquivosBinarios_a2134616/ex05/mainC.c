/*
Resumo da resolução:
Neste exercício, a tarefa é implementar a função read_movie que deve
ler um único registro do arquivo binário na posição especificada.
A função precisa abrir o arquivo em modo de leitura binária,
calcular a posição correta do registro (com base no tamanho
de cada registro de Movie), e então usar fseek para mover
o ponteiro do arquivo para a posição desejada.
 Após isso, a função deve ler o registro
 correspondente com fread e retornar o registro.
 Caso a posição seja inválida, ou o arquivo não
 possa ser aberto, a função retorna um registro
 de Movie preenchido com zeros.
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

// Função para ler um registro de filme da posição especificada em um arquivo
Movie read_movie(const char *filepath, int pos)
{
    Movie movie = {0}; // Inicializa o registro com zero (caso posição inválida)

    // Abre o arquivo em modo binário para leitura
    FILE *file = fopen(filepath, "rb");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return movie; // Retorna um Movie vazio caso o arquivo não seja aberto
    }

    // Calcula a posição do registro desejado
    // Cada registro Movie tem um tamanho de sizeof(Movie) bytes
    long offset = pos * sizeof(Movie);

    // Move o ponteiro do arquivo para a posição correta
    fseek(file, offset, SEEK_SET);

    // Lê o registro do filme na posição desejada
    size_t elements_read = fread(&movie, sizeof(Movie), 1, file);

    // Verifica se a leitura foi bem-sucedida
    if (elements_read != 1)
    {
        printf("Erro ao ler o registro na posição %d.\n", pos);
        // Se a leitura falhar, retorna um Movie vazio (com zero)
        memset(&movie, 0, sizeof(Movie));
    }

    // Fecha o arquivo após a leitura
    fclose(file);

    return movie; // Retorna o registro de filme lido
}

int main()
{
    // Chama a função para ler o filme na posição 4 do arquivo "movies.bin"
    Movie movie = read_movie("movies.bin", 2);

    // Imprime o filme lido
    if (movie.id != 0)
    {
        printf("\nFilme encontrado:\nID: %ld\nNome: %s\n", movie.id, movie.name);
    }
    else
    {
        printf("\nPosição inválida ou erro na leitura do filme.\n");
    }

    return 0;
}
