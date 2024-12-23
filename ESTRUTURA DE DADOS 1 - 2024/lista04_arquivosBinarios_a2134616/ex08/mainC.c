/*
Resumo da resolução:
A função update_movie precisa substituir um registro
de filme no arquivo binário com base no seu ID.
O procedimento envolve abrir o arquivo no modo binário
("r+b") para leitura e escrita. A função então acessa o arquivo
registro por registro, verificando o campo id de cada filme.
Quando o filme com o ID correspondente for encontrado,
o registro é substituído pela versão fornecida do filme.
Caso o ID não seja encontrado, a função retorna 0 (erro).
Se a substituição for bem-sucedida, ela retorna 1. O código
garante que somente o registro especificado seja acessado,
sem carregar todos os registros para a memória.
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

// Função para atualizar o filme no arquivo com base no ID
int update_movie(const char *filepath, Movie movie)
{
    // Abre o arquivo em modo binário de leitura e escrita ("r+b")
    FILE *file = fopen(filepath, "r+b");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para atualização.\n");
        return 0; // Retorna 0 (falso) caso o arquivo não possa ser aberto
    }

    Movie current_movie;
    int found = 0; // Variável para verificar se o filme foi encontrado

    // Percorre o arquivo registro por registro
    while (fread(&current_movie, sizeof(Movie), 1, file) == 1)
    {
        // Se o ID do filme atual for igual ao ID fornecido, substituímos o registro
        if (current_movie.id == movie.id)
        {
            // Move o ponteiro de arquivo para a posição do registro encontrado
            fseek(file, (sizeof(Movie) * (-1)), SEEK_CUR);
            // Escreve o novo registro no arquivo
            fwrite(&movie, sizeof(Movie), 1, file);
            found = 1; // Marca que o filme foi encontrado e atualizado
            break;     // Sai do loop após a atualização
        }
    }

    // Fecha o arquivo após a operação
    fclose(file);

    // Se o filme foi encontrado e atualizado, retorna 1, caso contrário retorna 0
    return found ? 1 : 0;
}

int main()
{
    // Exemplo de filme para atualização
    Movie updated_movie = {8, "Ghosts of jupiter - Reedited"};

    // Chama a função para atualizar o filme no arquivo "movies.bin"
    int result = update_movie("movies.bin", updated_movie);

    // Verifica o resultado da operação
    if (result == 1)
    {
        printf("\nFilme atualizado com sucesso!\n");
    }
    else
    {
        printf("\nFalha ao atualizar o filme. ID não encontrado.\n");
    }

    return 0;
}
