/*
Descrição: A função list_reverse inverte a ordem dos elementos da lista. Para isso,
ela percorre a lista até a metade, trocando os elementos das posições opostas
utilizando um laço. Após a execução da função, a lista estará invertida, e os
elementos serão armazenados de forma reversa em relação à ordem original.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Função para inverter a ordem dos elementos na lista
void list_reverse(VectorList *list)
{
    int start = 0;            // Posição inicial da lista
    int end = list->size - 1; // Posição final da lista

    // Enquanto o índice inicial for menor que o índice final
    while (start < end)
    {
        // Troca os elementos nas posições start e end
        int temp = list->data[start];
        list->data[start] = list->data[end];
        list->data[end] = temp;

        // Move os índices para mais perto do centro
        start++;
        end--;
    }
}

int main()
{
    VectorList *list = new VectorList();

    // Adiciona elementos à lista
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->print(); // Imprime a lista original

    // Inverte a lista
    list_reverse(list);

    // Imprime a lista invertida
    list->print(); // Deve mostrar: 3 2 1

    return 0;
}
