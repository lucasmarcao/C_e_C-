/*
descrição:
*/

// ABRIR NO TERMINAL INTEGRADO.
// g++ baseEmCPP.cpp -o baseEmCPP.exe
#include <iostream> // Para entrada e saída
#include <string>   // Para manipulação de strings
#include <cstdlib>  // Para funções auxiliares como malloc (mas não é usada aqui)

// default encurta codigo
using namespace std;

int main()
{
    cout << "\n\n"; // Espaço estratégico

    // Início do programa

    string str = "suco de uva"; // Usando string em vez de char*
    int tam = str.length();     // string possui o método .length() para obter o tamanho
    cout << tam;                // Mostra o tamanho da string

    // Espaço estratégico
    cout << "\n\n\a"; // Imprime uma nova linha e o alerta sonoro (beep)
    return 0;
}
