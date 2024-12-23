/*
Resumo da resolução:
A função defrag deve reorganizar os registros em um arquivo que contém
"buracos", ou seja, registros marcados com ID = -1. Para isso, a
função precisa percorrer o arquivo e copiar os registros válidos
(aqueles com ID diferente de -1) para o início do arquivo,
garantindo que os registros válidos fiquem consecutivos.
Não podemos carregar todos os registros na memória ao mesmo
tempo, então a função deve acessar os registros um por um, reescrevendo
o arquivo sem interromper o fluxo de dados. A função retorna 1 em
caso de sucesso e 0 caso algum erro ocorra
(por exemplo, falha ao abrir ou reescrever o arquivo).
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

// Função para desfragmentar o arquivo de filmes
int defrag(const char *filepath)
{
    // Abrir o arquivo original em modo de leitura binária ("rb")
    FILE *file = fopen(filepath, "rb");
    if (file == NULL)
    {
        printf("\nErro ao abrir o arquivo para leitura.\n");
        return 0; // Retorna 0 se o arquivo não pôde ser aberto
    }

    // Criar um arquivo temporário para armazenar os dados reordenados
    FILE *temp_file = fopen("temp_movies.bin", "wb");
    if (temp_file == NULL)
    {
        printf("\nErro ao criar o arquivo temporário.\n");
        fclose(file);
        return 0;
    }

    Movie current_movie;
    // Percorrer o arquivo de filmes e copiar os registros válidos para o arquivo temporário
    while (fread(&current_movie, sizeof(Movie), 1, file) == 1)
    {
        if (current_movie.id != -1)
        {
            // Se o ID for válido, escrevê-lo no arquivo temporário
            fwrite(&current_movie, sizeof(Movie), 1, temp_file);
        }
    }

    // Fechar os dois arquivos
    fclose(file);
    fclose(temp_file);

    // Apagar o arquivo original
    if (remove(filepath) != 0)
    {
        printf("\nErro ao apagar o arquivo original.\n");
        return 0; // Se não conseguir apagar, retorna erro
    }

    // Renomear o arquivo temporário para o nome original
    if (rename("temp_movies.bin", filepath) != 0)
    {
        printf("\nErro ao substituir o arquivo original.\n");
        return 0; // Se não conseguir renomear, retorna erro
    }

    // Sucesso, retorna 1
    return 1;
}

int main()
{
    // Exemplo de uso da função defrag
    int result = defrag("movies.bin");

    if (result == 1)
    {
        printf("\nArquivo desfragmentado com sucesso!\n");
    }
    else
    {
        printf("\nFalha na desfragmentação do arquivo.\n");
    }

    return 0;
}
