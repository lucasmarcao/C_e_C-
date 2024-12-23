/*
Resumo da solução:
O exercício pede para implementar uma função que grave o conteúdo
de um vetor de filmes, representados pela estrutura Movie, em um
arquivo chamado "movies.bin". A função deve criar o arquivo se
ele não existir, ou sobrescrevê-lo caso já exista. Em C++,
usaremos a biblioteca fstream para manipular arquivos binários.
A alocação de memória será feita dinamicamente usando new para
criar o vetor de filmes e delete[] para liberar a memória após
o uso. Além disso, o arquivo será manipulado no formato binário,
garantindo que os dados sejam gravados de forma compacta e sem
formatação adicional. O código seguirá o formato que você pediu,
ajustando a alocação de memória e o uso das bibliotecas.
*/

// ABRIR NO TERMINAL INTEGRADO.
//   g++ mainCPP.cpp -o mainCPP.exe
//   ./mainCPP.exe

#include <iostream> // Para entrada e saída
#include <fstream>  // Para manipulação de arquivos
#include <cstring>  // Para manipulação de strings
#include <cstdlib>  // Para funções auxiliares como new e delete

using namespace std;

// Definição da estrutura Movie
typedef struct
{
    long id;       // ID do filme
    char name[51]; // Nome do filme, limitado a 50 caracteres + '\0'
} Movie;

// Função para gravar o conteúdo de um vetor de filmes em um arquivo
void write_movies_to_file(const char *filepath, Movie *movies, int n)
{
    // Abre o arquivo em modo binário para gravação (cria o arquivo se não existir)
    ofstream file(filepath, ios::binary);

    // Verifica se o arquivo foi aberto corretamente
    if (!file.is_open())
    {
        cout << "Erro ao criar o arquivo.\n";
        return; // Se não conseguir abrir/criar o arquivo, retorna
    }

    // Percorre o vetor de filmes e grava cada elemento no arquivo
    for (int i = 0; i < n; i++)
    {
        // Grava cada estrutura Movie no arquivo
        file.write(reinterpret_cast<char *>(&movies[i]), sizeof(Movie));
    }

    // Fecha o arquivo após a gravação
    file.close();
    cout << "Filmes gravados com sucesso no arquivo " << filepath << endl;
}

int main()
{
    // Alocação dinâmica de memória para um vetor de filmes
    int num_movies = 7;
    Movie *movies = new Movie[num_movies]; // Aloca o vetor de filmes dinamicamente

    // Preenchendo o vetor de filmes
    movies[0] = {6, "They Live"};
    movies[1] = {11, "Big Trouble in Little China"};
    movies[2] = {10, "The Thing"};
    movies[3] = {1, "In the Mouth of Madness"};
    movies[4] = {8, "Ghosts of Mars"};
    movies[5] = {23, "Halloween"};
    movies[6] = {7, "Village of the Damned"};

    // Chama a função para gravar o vetor de filmes no arquivo "movies.bin"
    write_movies_to_file("movies.bin", movies, num_movies);

    // Liberação da memória alocada dinamicamente
    delete[] movies;

    return 0;
}
