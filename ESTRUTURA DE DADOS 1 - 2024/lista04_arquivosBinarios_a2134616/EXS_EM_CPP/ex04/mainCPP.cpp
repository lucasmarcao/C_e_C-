#include <iostream>
#include <fstream> // Para manipulação de arquivos
#include <string>  // Para usar std::string

int file_exists(const char *filepath)
{
    std::ifstream file(filepath); // Tenta abrir o arquivo com std::ifstream
    if (file)
    { // Se a abertura foi bem-sucedida, o arquivo existe
        return 1;
    }
    return 0; // Caso contrário, o arquivo não existe
}

// C:\Users\Usuario\Documents\centro_vscode\aprendendoC\ESTRUTURA DE DADOS 1 - 2024\lista02_arquivosTexto_a2134616\ex01
int main()
{
    const char *path = "C:/Users/Usuario/Documents/centro_vscode/aprendendoC/ESTRUTURA DE DADOS 1 - 2024/lista02_arquivosTexto_a2134616/ex01/teste.exe";
    int res = file_exists(path);

    if (res == 1)
    {
        std::cout << "O arquivo existe.\n";
    }
    else
    {
        std::cout << "O arquivo não existe.\n";
    }

    return 0;
}
