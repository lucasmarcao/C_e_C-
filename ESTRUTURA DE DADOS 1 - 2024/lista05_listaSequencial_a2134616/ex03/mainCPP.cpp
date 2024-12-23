/*
Descrição: A função list_get_available foi implementada para calcular o número de posições livres restantes
na lista sequencial. Ela faz isso subtraindo o tamanho atual da lista (size) da sua capacidade máxima (capacity).
O retorno será a diferença entre capacidade e tamanho, representando as posições livres.
Se o tamanho for 3 e a capacidade for 5, a função retornará 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Implementação da função para retornar o número de posições livres restantes
int list_get_available(VectorList *list)
{
    return list->capacity - list->size; // Posições livres são a diferença entre capacidade e tamanho
}

int main()
{
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->print();

    // Chama a função para obter o número de posições livres restantes
    int available = list_get_available(list);
    printf("Posicoes livres restantes: %d\n", available);

    // Adicionando mais elementos para testar as posições livres restantes
    list->push_back(4);
    list->push_back(5);
    list->push_back(6); // Este deve falhar, pois a capacidade é 5
    list->print();

    // Chama novamente a função para verificar as posições livres
    available = list_get_available(list);
    printf("Posicoes livres restantes: %d\n", available);

    return 0;
}
