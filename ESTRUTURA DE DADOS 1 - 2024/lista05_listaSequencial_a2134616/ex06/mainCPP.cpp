/*
Descrição: A função list_print_reverse foi implementada para imprimir os elementos da lista
de forma reversa. Para isso, percorremos o vetor de dados da lista a partir do último elemento
(posição size - 1) e vamos até o primeiro elemento (índice 0). A função de impressão não altera
a estrutura da lista, apenas acessa seus elementos na ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Implementação da função para imprimir os elementos da lista de forma reversa
void list_print_reverse(VectorList *list)
{
    // Itera do último para o primeiro elemento da lista
    printf("\n(%d/%d) ", list->size, list->capacity);

    for (int i = list->size - 1; i >= 0; i--)
    {
        printf("%d ", list->data[i]); // Imprime cada elemento
    }
    printf("\n");
}

int main()
{
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(77);
    list->push_back(3);
    list->push_back(4);

    printf("Lista original: \n");
    list->print(); // Imprime a lista original

    // Imprime a lista de forma reversa
    printf("Lista em ordem reversa: \n");
    list_print_reverse(list); // Chama a função para imprimir reversamente

    return 0;
}
