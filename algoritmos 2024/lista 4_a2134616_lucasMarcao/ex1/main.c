#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int trocarDigitos(int numero) {
    int primeiroDigito, ultimoDigito, novoNumero;
    
    // Obter o último dígito
    ultimoDigito = abs(numero % 10);
    
    // Obter o primeiro dígito
    primeiroDigito = abs(numero);
    while (primeiroDigito >= 10) {
        primeiroDigito /= 10;
    }
    
    // Calcular o novo número
    novoNumero = ultimoDigito * pow(10, (int)log10(abs(numero))) + (numero / 10) * 10 + primeiroDigito;
    
    return numero < 0 ? -novoNumero : novoNumero;
}

int main() {
    int numero, novoNumero;
    
    printf("Informe o número: ");
    scanf("%d", &numero);
    
    novoNumero = trocarDigitos(numero);
    
    printf("Número com os dígitos trocados: %d\n", novoNumero);
    
    return 0;
}
