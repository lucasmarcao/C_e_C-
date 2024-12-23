/*
Descrição: A função list_clear foi implementada para limpar todos os elementos da lista.
Ela faz isso simplesmente ajustando o tamanho da lista (size) para 0, já que os elementos
não precisam ser desalocados, pois a memória alocada para os dados da lista ainda será válida.
Isso redefine efetivamente a lista para o estado vazio, sem remover a capacidade alocada.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Implementação da função para limpar todos os elementos da lista
void list_clear(VectorList *list)
{
    list->size = 0; // Reseta o tamanho da lista para 0, removendo todos os elementos
}

int main()
{
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->print(); // Mostra a lista antes de limpar

    // Chama a função para limpar a lista
    list_clear(list);
    printf("Lista apos limpar: \n");
    list->print(); // Mostra a lista depois de limpar

    return 0;
}
