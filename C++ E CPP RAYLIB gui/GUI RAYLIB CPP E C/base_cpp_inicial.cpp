// iostream_cin.cpp
// compile with: /EHsc
#include <iostream>

// Função que multiplica o número por 2
float multiplicaPorDois(float numero)
{
    return numero * 2;
}

int main()
{
    float numero;

    // Lê um número float
    std::cout << " \n \nDigite um número:\n";
    std::cin >> numero;

    // Chama a função para multiplicar o número por 2
    float resultado = multiplicaPorDois(numero);

    // Exibe o resultado
    std::cout << "O resultado da multiplicação por 2 é: " << resultado << std::endl;

    return 0;
}
