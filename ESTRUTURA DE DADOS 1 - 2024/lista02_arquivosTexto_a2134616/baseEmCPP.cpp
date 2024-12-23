/*
descrição:
*/
#include <iostream> // Para entrada e saída
#include <string>   // Para manipulação de strings
#include <cstdlib>  // Para funções auxiliares como malloc (mas não é usada aqui)

int main()
{
    std::cout << "\n\n"; // Espaço estratégico

    // Início do programa

    std::string str = "suco de uva"; // Usando std::string em vez de char*
    int tam = str.length();          // std::string possui o método .length() para obter o tamanho
    std::cout << tam;                // Mostra o tamanho da string

    // Espaço estratégico
    std::cout << "\n\n\a"; // Imprime uma nova linha e o alerta sonoro (beep)
    return 0;
}
