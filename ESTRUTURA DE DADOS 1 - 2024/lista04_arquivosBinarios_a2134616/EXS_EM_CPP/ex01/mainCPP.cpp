/*
Resumo de pensamento para resolução do exercício:
Neste exercício, o objetivo é escrever uma função que grave o
conteúdo de um vetor de inteiros em um arquivo binário. O arquivo
deve ser criado caso não exista, e a gravação deve ser feita de
maneira eficiente, utilizando operações de leitura e escrita binária.
Em C++, podemos utilizar a biblioteca fstream para gerenciar
arquivos de maneira mais moderna e flexível, ao invés das funções
tradicionais de C como fopen() e fwrite(). Vou usar ofstream em
modo binário para abrir o arquivo para escrita e garantir que,
caso o arquivo não exista, ele seja criado automaticamente.
A função vai percorrer o vetor e gravar todos os seus elementos
no arquivo, sem sobrescrever dados existentes.

*/

// ABRIR NO TERMINAL INTEGRADO.
//   g++ mainCPP.cpp -o mainCPP.exe
//   ./mainCPP.exe
#include <iostream>
#include <fstream> // Para operações com arquivos
#include <cstdlib> // Para funções auxiliares, mas não será usada aqui

// Função para gravar o conteúdo de um vetor de inteiros em um arquivo
// Caso o arquivo não exista, ele será criado automaticamente.
void write_array(const char *filepath, int n, const int *v)
{
    // Abrir o arquivo em modo binário para escrita
    // O 'ios::binary' garante que a escrita seja feita de forma binária (não em texto)
    std::ofstream file(filepath, std::ios::binary);

    // Verifica se o arquivo foi aberto corretamente
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }

    // Escreve os dados do vetor no arquivo
    // O arquivo será criado se não existir e os dados serão escritos do começo
    file.write(reinterpret_cast<const char *>(v), n * sizeof(int));

    // Verifica se a escrita foi bem-sucedida
    if (file.good())
    {
        std::cout << "Dados gravados com sucesso no arquivo " << filepath << "." << std::endl;
    }
    else
    {
        std::cerr << "Erro ao escrever no arquivo." << std::endl;
    }

    // Fecha o arquivo
    file.close();
}

int main()
{
    // Exemplo de vetor de inteiros
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Chama a função para gravar o vetor no arquivo "dados.bin"
    write_array("dados.bin", 10, v);

    // Adiciona mais dados ao final do arquivo (se já existir)
    // int v2[] = {11, 12, 13, 999, 15};
    // write_array("dados.bin", 5, v2);

    return 0;
}
